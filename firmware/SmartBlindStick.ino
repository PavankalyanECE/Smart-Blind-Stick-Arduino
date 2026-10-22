
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 6
#define BUZZER_PIN 7

unsigned long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo with a timeout
  duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    // No valid echo
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("No echo detected");
    delay(100);
    return;
  }

  // Calculate distance in centimeters
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 20) {
    // Very close obstacle
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    delay(100);
  }
  else if (distance <= 50) {
    // Nearby obstacle
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1500);
    delay(100);
    noTone(BUZZER_PIN);
    delay(150);
  }
  else if (distance <= 100) {
    // Obstacle farther away
    digitalWrite(LED_PIN, LOW);
    tone(BUZZER_PIN, 1000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(500);
  }
  else {
    // No obstacle within 1 metre
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    delay(100);
  }
}

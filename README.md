
# Smart Blind Stick Using Arduino UNO

## About the Project

This project is a low-cost assistive technology prototype designed to help visually impaired people detect nearby obstacles while walking.

An Arduino UNO processes distance measurements from an HC-SR04 ultrasonic sensor. A buzzer provides audio alerts, and an LED indicates nearby obstacles.

## Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- LED
- Buzzer
- 220-ohm resistor
- Jumper wires
- Stick and enclosure materials
- USB or suitable power supply

## Circuit Connections

| Component | Arduino UNO |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| LED Anode (+) | D6 through 220-ohm resistor |
| LED Cathode (-) | GND |
| Buzzer Positive (+) | D7 |
| Buzzer Negative (-) | GND |

## Working Principle

1. The ultrasonic sensor sends sound waves.
2. Reflected waves are used to calculate the distance to an obstacle.
3. The Arduino processes the distance measurement.
4. The buzzer produces alerts based on the obstacle distance.
5. The LED indicates obstacle detection.

## Alert Levels

- 0–20 cm: Continuous buzzer alert; LED ON.
- 21–50 cm: Faster intermittent alerts; LED ON.
- 51–100 cm: Slower intermittent alerts.
- Above 100 cm: Buzzer OFF; LED OFF.

## Software Requirements

- Arduino IDE
- Arduino UNO board support

No external libraries are required for the basic code.

## Future Improvements

- Vibration motor for silent alerts
- Rechargeable battery
- Improved enclosure and wiring
- Testing with different obstacle types
- Additional safety and usability improvements

## Author

Pavan Kalyan Imandi

Electronics and Communication Engineering  
Interests: Embedded Systems, Arduino, and Robotics

## Safety Notice

This is an educational prototype and may not detect every obstacle reliably. It should not replace a traditional white cane or other established mobility aids.

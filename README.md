# ESP32 Smart Parking Sensor

## Project Overview

This project is an ESP32-based smart parking sensor. It uses an HC-SR04 ultrasonic sensor to measure the distance between the sensor and an object.

The ESP32 processes the distance and indicates the parking status using an LED and buzzer.

## Features

- Ultrasonic distance measurement
- Parking occupied detection
- Parking available indication
- LED blinking alert
- Buzzer sound alert
- Serial Monitor distance display
- ESP32 GPIO interfacing

## Components Used

- ESP32 development board
- HC-SR04 ultrasonic sensor
- 3-pin buzzer module
- LED
- 220Ω resistor
- 1kΩ resistors
- Breadboard
- Jumper wires

## Pin Connections

| Component | Pin | ESP32 |
|---|---|---|
| HC-SR04 | VCC | VIN / 5V |
| HC-SR04 | GND | GND |
| HC-SR04 | TRIG | GPIO 5 |
| HC-SR04 | ECHO | GPIO 18 through resistor divider |
| Buzzer | S | GPIO 13 |
| Buzzer | + | 3V3 |
| Buzzer | - | GND |
| LED | Positive | GPIO 2 through 220Ω resistor |
| LED | Negative | GND |

## Working Logic

- Distance greater than 20 cm: Parking available
- Distance 20 cm or less: Parking occupied
- Occupied status: LED blinks and buzzer sounds

## Technologies Used

- ESP32
- Embedded C/C++
- Arduino IDE
- HC-SR04 ultrasonic sensor
- GPIO programming
- Serial communication
- Basic timer handling using millis()

## Project Hardware

![ESP32 Smart Parking Sensor](project-photo.jpg)

## Future Improvements

- OLED display
- Multiple parking slots
- Wi-Fi monitoring
- MQTT integration
- Mobile dashboard

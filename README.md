# Smart Helmet for Safety and Accident Detection using IoT

## Overview

This project implements an IoT-based smart helmet designed to enhance rider safety by detecting accidents and monitoring helmet usage. The helmet integrates various sensors and communication modules to provide real-time alerts and emergency notifications.

---

## Features

- **Accident Detection:** Utilizes accelerometer and gyroscope sensors to detect sudden impacts or falls.
- **Helmet Usage Detection:** Ensures the helmet is worn properly before the vehicle starts.
- **Emergency Alerts:** Sends SMS notifications to predefined emergency contacts with the GPS location of the accident using GSM and GPS modules.
- **Real-Time Monitoring:** Data is sent and can be monitored on IoT platforms such as ThingSpeak.
- **Compact and Wearable:** Designed to be comfortable and practical for everyday use.

---

## Technologies Used

- **Hardware:**
  - Arduino Uno / Compatible Microcontroller
  - MPU6050 (Accelerometer and Gyroscope)
  - GPS Module (e.g., Neo-6M)
  - GSM Module (e.g., SIM800L)
  - Buzzer and LEDs for alerts
  - Helmet enclosure and mounting hardware

- **Software:**
  - Arduino IDE (C/C++ programming)
  - ThingSpeak or similar IoT cloud platform (optional)
  - SMS Gateway via GSM module

---

## How It Works

1. Sensors continuously monitor the rider's head movement and impact.
2. When a potential accident is detected (sudden acceleration change), the system immediately retrieves GPS coordinates.
3. The GSM module sends an SMS with the location to emergency contacts.
4. The helmet can also detect if it’s being worn, preventing unsafe riding without proper protection.
5. Sensor data can be uploaded to an IoT platform for remote monitoring and analytics.

---

## Setup Instructions

### Hardware Setup

1. Connect MPU6050 sensor to the Arduino (SDA, SCL, VCC, GND).
2. Connect GPS and GSM modules according to their pin specifications.
3. Connect buzzer and LEDs to digital output pins.
4. Mount all components securely inside or on the helmet.

### Software Setup

1. Install the Arduino IDE from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software).
2. Install necessary libraries (MPU6050, SoftwareSerial, TinyGPS++) via the Arduino Library Manager.
3. Upload the provided Arduino sketch (`SmartHelmet.ino`) to the Arduino board.
4. Configure emergency contact numbers in the sketch.
5. Power on the helmet and test sensor readings.

---

## Usage

- Wear the helmet before starting the vehicle.
- The system will automatically monitor and detect accidents.
- In case of an accident, emergency contacts will receive the SMS alert with the location.
- Use the IoT platform dashboard (if configured) to monitor helmet data remotely.

---

## Future Enhancements

- Integrate a mobile app for live notifications and tracking.
- Add voice call alerts alongside SMS.
- Use more advanced AI models to reduce false positives.
- Enhance helmet comfort and battery life.

---

## Acknowledgments

- Arduino community and sensor library developers
- IoT platform providers
- Open source contributors

--

*Stay safe, ride smart! 🛵🪖*

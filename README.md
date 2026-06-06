# Robot-Car-autonomous-ultrasonic-line-tracking-servo-scanning
This project is an autonomous robotic car system built using an Arduino-compatible microcontroller.
The robot is capable of navigating its environment by combining ultrasonic obstacle detection, servo-based scanning, and line tracking sensors to make real-time movement decisions.

The system is designed as a foundation for IoT and intelligent robotics applications, simulating real-world autonomous navigation behavior.

⚙️ Key Features
🚗 Autonomous movement (Forward / Left / Right / Stop)
📡 Obstacle detection using ultrasonic sensor (HC-SR04)
🔄 Servo motor scanning (left/right environment analysis)
🧠 Smart decision-making based on distance comparison
🛤️ Line tracking sensors integration (IR sensors)
🔊 Buzzer alert system for obstacle warning
💡 LED indicators for system status
⚡ PWM motor speed control
🧠 System Logic

The robot continuously:

Measures front distance using ultrasonic sensor
If an obstacle is detected:
Stops the motors
Scans left and right using a servo motor
Compares available paths
Chooses the safest direction
If no obstacle is detected:
Continues moving forward
Updates status indicators
🧩 Hardware Components
Arduino UNO / compatible board
HC-SR04 Ultrasonic sensor
SG90 Servo motor
L298N Motor driver
DC motors (x2)
IR line tracking sensors (x3)
Buzzer
LEDs (Red / Green)
Battery pack
🔧 Software Used
Arduino IDE
C / C++ (Embedded programming)
🚀 Possible Upgrades
ESP8266 / ESP32 IoT connectivity
Firebase real-time monitoring
Mobile app control (Bluetooth / WiFi)
AI-based path optimization
Computer vision integration (Raspberry Pi)
🎯 Project Goal

The goal of this project is to simulate a low-cost autonomous navigation system and provide a strong base for future work in:

Robotics
Embedded systems
IoT applications
Smart automation
👨‍💻 Author

Abdallah Ben Aicha
Embedded Systems & IoT Engineering Student

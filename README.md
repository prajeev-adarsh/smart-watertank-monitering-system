# 💧 Smart Water Tank Level Monitoring System

An Arduino-based Smart Water Tank Level Monitoring System that automatically monitors the water level in a storage tank using an HC-SR04 ultrasonic sensor. The system displays the current water level status on a 16×2 I2C LCD, provides visual indication using LEDs, automatically controls a water pump through a relay module, and alerts the user with a buzzer when the tank becomes full.

This project is designed as a simple, low-cost automation system suitable for learning embedded systems, Arduino programming, and basic industrial automation concepts. It can also be used as a foundation for more advanced IoT-based smart water management systems.

---

# 📖 Project Overview

Water tanks require regular monitoring to avoid overflow, water wastage, and dry running of pumps. Manual monitoring is time-consuming and often unreliable. This project solves these problems by continuously measuring the water level inside a tank using an ultrasonic sensor.

The Arduino processes the sensor data and determines whether the water level is Low, Medium, or Full. Based on the detected level, the system automatically controls the water pump, updates the LCD display, changes the LED indicators, and activates a buzzer when the tank reaches its full capacity.

The project demonstrates the practical implementation of sensors, displays, relays, actuators, and embedded programming in a single automation system.

---
#Simulation link: https://www.tinkercad.com/things/eFw002WPhdv-smart-watertank-monitoring-system?sharecode=R3O2bHofAafceAGw8azrSZfavPob8a8QVY6mEtWGeBs

# ✨ Features

- Real-time water level monitoring
- Automatic motor ON and OFF control
- Non-contact ultrasonic level measurement
- 16×2 I2C LCD for status display
- LED indication for different water levels
- Buzzer alert when the tank becomes full
- Sensor fault detection
- Simple and modular Arduino code
- Easy to customize for different tank sizes
- Beginner-friendly hardware and software design

---

# 🛠 Hardware Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- 16×2 I2C LCD Display
- Relay Module
- DC Water Pump (or Motor)
- Red LED
- Yellow LED
- Green LED
- Active Buzzer
- Breadboard
- Jumper Wires
- USB Cable

---

# 💻 Software Requirements

- Arduino IDE
- Tinkercad (simulation)

---

# ⚙️ Working Principle

1. The HC-SR04 ultrasonic sensor continuously measures the distance between the sensor and the water surface.

2. The Arduino calculates the water level based on the measured distance.

3. According to the measured value, the system classifies the water level into one of three stages:

   - Low Level
   - Medium Level
   - Full Level

4. For each stage, the Arduino performs the following actions:

   **Low Level**
   - Turns ON the Red LED
   - Starts the water pump through the relay
   - Displays "LOW" on the LCD

   **Medium Level**
   - Turns ON the Yellow LED
   - Keeps the motor running
   - Displays "MEDIUM" on the LCD

   **Full Level**
   - Turns ON the Green LED
   - Stops the water pump
   - Sounds the buzzer three times
   - Displays "FULL" on the LCD

5. If the ultrasonic sensor does not return a valid reading, the system displays a sensor fault message and turns OFF the motor for safety.

---

# 📏 Water Level Thresholds

The project currently uses the following distance thresholds:

- Distance greater than or equal to **200 cm** → Low Water Level
- Distance between **100 cm and 199 cm** → Medium Water Level
- Distance less than **100 cm** → Full Water Level

These values can be modified in the Arduino code to match the dimensions of any water tank.

---

# 🔌 Circuit Connections

### HC-SR04 Ultrasonic Sensor

- VCC → 5V
- GND → GND
- TRIG → Digital Pin 10
- ECHO → Digital Pin 9

### Relay Module

- IN → Digital Pin 5
- VCC → 5V
- GND → GND

### LEDs

- Red LED → Digital Pin 2
- Yellow LED → Digital Pin 3
- Green LED → Digital Pin 4

### Buzzer

- Positive (+) → Digital Pin 6
- Negative (-) → GND

### 16×2 I2C LCD

- SDA → A4
- SCL → A5
- VCC → 5V
- GND → GND


# ▶️ Getting Started

1. Install the Arduino IDE on your computer.

2. Install the LiquidCrystal_I2C library.

3. Connect all hardware components according to the circuit connections provided above.

4. Open the project in Arduino IDE.

5. Select **Arduino UNO** as the board.

6. Choose the correct COM port.

7. Upload the code to the Arduino.

8. Open the Serial Monitor if required.

9. Change the distance between the ultrasonic sensor and the object (or water surface) to observe the system automatically switching between different water levels.


---

# 🚀 Future Improvements

This project can be extended with several additional features, including:

- ESP32 or NodeMCU integration
- IoT-based remote monitoring
- Mobile application support
- Blynk dashboard integration
- Telegram notifications
- SMS alerts
- Cloud data logging
- Water usage analytics
- Multiple tank monitoring
- Automatic pump scheduling

---

# 🎯 Applications

This project can be used in a variety of real-world scenarios, including:

- Residential water tanks
- Apartments and hostels
- Agricultural irrigation systems
- Industrial water storage
- Commercial buildings
- Educational laboratories
- Smart home automation
- Water treatment facilities

---

# 📚 Learning Outcomes

This project provides practical experience with:

- Arduino Programming
- Embedded Systems
- Ultrasonic Sensor Interfacing
- Relay Module Control
- LCD Interfacing
- Digital Electronics
- Automation Systems
- Sensor-Based Applications
- Hardware Integration
- Basic Industrial Automation


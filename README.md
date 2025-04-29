# Alcohol Detection System with NodeMCU ESP8266

A real-time alcohol detection system using MQ2 sensor, I2C LCD, and buzzer with NodeMCU ESP8266.

## Features
- Real-time alcohol concentration monitoring
- 16x2 LCD display via I2C
- Audible alarm with active-low buzzer
- Adjustable detection threshold
- Serial monitor output for debugging

## Components
| Component | Quantity |
|-----------|----------|
| NodeMCU ESP8266 | 1 |
| MQ2 Gas/Alcohol Sensor | 1 |
| 16x2 LCD with I2C | 1 |
| Active-low buzzer | 1 |
| Breadboard | 1 |
| Jumper wires | 10+ |
| 10KΩ resistor | 1 |

## Wiring Diagram (Text-Based)
NodeMCU ESP8266 Peripheral Components
+---------------+ +---------------------+
| | | |
| 3.3V |-----| VCC (MQ2 & LCD) |
| GND |-----| GND (All) |
| A0 |-----| A0 (MQ2) |
| D1 |-----| SCL (LCD) |
| D2 |-----| SDA (LCD) |
| D5 |-----| + (Buzzer) |
| | | |
+---------------+ +---------------------+
## Installation

### Hardware Setup
1. Connect components as per the wiring diagram
2. Double-check all connections before powering

### Software Setup
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP8266 board support:
   - File > Preferences > Additional Boards Manager URLs:
     `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
3. Install required libraries:
   ```bash
   # LiquidCrystal_I2C library
   Sketch > Include Library > Manage Libraries > Search "LiquidCrystal I2C"
   Code Upload
Clone this repository

Open Alcohol_Detector.ino in Arduino IDE

Select board: "NodeMCU 1.0 (ESP-12E Module)"

Select correct COM port

Click Upload

Configuration
Adjust these values in the code as needed:
const int threshold = 300;  // Detection sensitivity
const int warmupTime = 120; // Sensor warmup in seconds

Usage
Power on the system

Wait for sensor warmup (2 minutes)

LCD will display real-time readings

Buzzer sounds when alcohol detected

Serial Monitor Output
Alcohol Level: 245
Alcohol Level: 380 (ALERT!)
Alcohol Level: 287
Troubleshooting
Issue	Solution
LCD not working	Check I2C address (try 0x3F)
No sensor readings	Verify analog connection
Buzzer always on	Check active-low wiring
ESP8266 not detected	Install correct USB drivers
License
MIT License © 2023

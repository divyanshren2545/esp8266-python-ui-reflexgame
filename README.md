**ESP8266 Reflex Game with Python UI**
**Description**
This is a reflex game where a bouncing LED is stopped using a Python-based desktop UI. Built using ESP8266 and simple components, this project helps users understand timing, GPIO, and Python-to-serial communication.

**Features**
Real LED bouncing visual effect
Desktop Python UI to interact
Scoreboard
Serial communication with microcontroller

**Setup Instructions**
Clone the repo
Upload ESP code to ESP8266 via Arduino IDE
Connect LEDs to GPIO 
LED(anode)         ESP PIN
1                    D1
2                    D2
3                    D3
4                    D4
5                    D5

LED(cathode)           ESP PIN
1,2,3,4,5                GND

Run python_ui.py

**Circuit Diagram**
Look for circuit_diagram.png in the repo.

**Folder Structure**
/esp_code        → Arduino sketch (.ino)
/python_ui       → Python UI script
/docs            → README, Requirements, Circuit image

**Dependencies**
Arduino IDE
Python 3.x
pip install pyserial

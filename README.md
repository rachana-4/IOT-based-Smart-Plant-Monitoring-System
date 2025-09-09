🌱 IoT-based Smart Plant Monitoring System ✨

IoT-based Smart Plant Monitoring System is a microcontroller-powered solution that allows real-time monitoring and control of essential plant health parameters—such as soil moisture, temperature, and humidity—through the Blynk IoT platform. It automates watering by controlling a pump based on soil moisture levels and sends alerts when moisture is low.

This project bridges the gap between nature and technology, making plant care smarter, more efficient, and accessible from anywhere.

---

🚀 Features

🌡️ Real-time Sensor Monitoring
Track soil moisture, temperature, and humidity in real time via the Blynk mobile app.

💧 Automated Watering System
Control a water pump through Blynk or automatically based on soil moisture thresholds.

📱 Blynk Integration
Control and monitor remotely with simple virtual pins and event notifications.

⚡ Lightweight & Efficient
Built on the ESP8266 platform with optimized sensor polling using BlynkTimer.

🔔 Smart Alerts
Sends a warning via Blynk event when soil moisture drops below a safe threshold.

---

🛠️ Tech Stack

Microcontroller: ESP8266 (NodeMCU)
IoT Platform: Blynk (Classic)
Sensors & Components:

DHT11 (Temperature & Humidity Sensor)

Soil Moisture Sensor

Relay Module (for water pump control)
Language: C++ (Arduino)
Libraries Used:

BlynkSimpleEsp8266

DHT Sensor Library

ESP-8266 WiFi

---

🔧 How It Works

The DHT11 sensor reads temperature and humidity data.

The Soil Moisture sensor reads the moisture content of the soil.

These values are sent to the Blynk app via virtual pins (V1-V3).

The Relay Module controls a pump, which can be toggled manually via Blynk (V4) or automatically based on soil readings.

If the soil moisture exceeds a certain dryness threshold (e.g., > 400), a Blynk notification is triggered.

---

📦 Installation

Clone the Repository

git clone https://github.com/rachana-4/IOT-based-Smart-Plant-Monitoring-System.git


Open the Code in Arduino IDE

Install the following libraries (via Library Manager):

Blynk

DHT Sensor Library

ESP8266 WiFi

Update the Credentials in Code

Replace the placeholder values:

#define BLYNK_TEMPLATE_ID "Your template ID"

#define BLYNK_TEMPLATE_NAME "Your template name"

#define BLYNK_AUTH_TOKEN "Your auth token in blynk app"

char ssid[] = "Replace with Wifi name";

char pass[] = "Replace with Wifi Password";


Upload to ESP8266 (NodeMCU)
Connect your board, select the right COM port, and upload the sketch.

Start Monitoring
Open the Blynk app → Connect your template → Monitor your plant in real-time!

--- 

🌐 Virtual Pin Mapping (Blynk App)
Virtual Pin	Purpose
V1	Soil Moisture
V2	Temperature
V3	Humidity
V4	Pump Control Button

---

🌟 Future Scope

💾 Data Logging – Store readings in the cloud or SD card for analysis.

📊 Charts & Trends – Visualize sensor data over time.

🌍 Voice Assistant Integration – Alexa or Google Assistant control.

☁️ OTA Updates – Wireless firmware upgrades.

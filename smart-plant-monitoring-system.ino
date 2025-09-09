#define BLYNK_TEMPLATE_ID "Your template ID"
#define BLYNK_TEMPLATE_NAME "Your template name"
#define BLYNK_AUTH_TOKEN "Your auth token in blynk app"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Replace with your WiFi credentials
char ssid[] = "Replace with Wifi name";
char pass[] = "Replace with Wifi Password";

// Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// Define pins
#define DHTPIN D2           // DHT sensor connected to GPIO4 (D2)
#define RELAY_PIN D1        // Relay connected to GPIO5 (D1)
#define SOIL_SENSOR_PIN A0  // Soil moisture sensor connected to A0

// DHT sensor type
#define DHTTYPE DHT11  // or DHT22 for DHT22 sensor
DHT dht(DHTPIN, DHTTYPE);

// Variables
int soilMoistureValue = 0;
float temperature = 0;
float humidity = 0;

// Virtual Pins
#define VPIN_SOIL V1   // Virtual pin for soil moisture in Blynk
#define VPIN_TEMP V2   // Virtual pin for temperature in Blynk
#define VPIN_HUMID V3  // Virtual pin for humidity in Blynk
#define VPIN_PUMP V4   // Virtual pin for pump control in Blynk

BlynkTimer timer;

// Function to read sensor data and send to Blynk
void sendSensorData() {
  // Read soil moisture
  soilMoistureValue = analogRead(SOIL_SENSOR_PIN);
  // Read temperature and humidity
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Send data to Blynk
  Blynk.virtualWrite(VPIN_SOIL, soilMoistureValue);
  Blynk.virtualWrite(VPIN_TEMP, temperature);
  Blynk.virtualWrite(VPIN_HUMID, humidity);

  // Debugging info
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  if(soilMoistureValue>400){
    Blynk.logEvent("warning","Turn on the Pump");
  }
}

// Blynk function to control the water pump
BLYNK_WRITE(VPIN_PUMP) {
  int pumpState = param.asInt();  // Get the value from the app (0 or 1)
  digitalWrite(RELAY_PIN, pumpState);
}

void setup() {
  // Debug console
  Serial.begin(9600);

  // Initialize sensors
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Pump off by default

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);

  // Set up a timer to read sensor data every 10 seconds
  timer.setInterval(10000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
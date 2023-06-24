#include <ThingSpeak.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
long channelNumber = 99999999; //enter the ThingSpeak channel ID here in the quotation marks given
const char apiKey[] = "XXXXXXXXXXXX";     //  Enter the Write API key for your ThingSpeak channel in the quotation marks given
const char *ssid =  "EnterWiFiname";     // Enter WiFi Name (SSID) in the quotation marks given
const char *password =  "passwordhere"; // Enter your WiFi Password in the quotation marks given
#define DHTPIN 3          // GPIO Pin connected to DHT11 is GPIO3, or pin D3
DHT dht(DHTPIN, DHT11);
WiFiClient client;

const int moiAnaPin = A0;             // Moisture sensor pin
float moisture;              // Variable for Moisture reading
float humidity;                  // Variable for Humidity reading
float temperature;                  // Variable for Temperature reading

void setup() {
  Serial.begin(115200);     //specify baud rate
  delay(10);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to WiFi, watch your plants meanwhile...\n");              // Print till not connected
  }
  Serial.println("");
  Serial.println("WiFi connection successful, welcome to Gardenia!");
  ThingSpeak.begin(client);
}

void loop() {
  humidity = dht.readHumidity();     // Read humidity
  temperature = dht.readTemperature();     // Read temperature
  moisture = ( 100.00 - ( (analogRead(moiAnaPin) / 2023.00) * 100.00 ) );   //Formula for calculating soil moisture
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT sensor returning null, please check sensor, board or connection!");        //DHT sensor failure
    delay(2000);
    return;
  }

  Serial.println("Soil Moisture percentage: %f percent. Temperature: %f degrees Celsius. Humidity: %f percent. Sending to ThingSpeak in 15s!", moisture, temperature, humidity);
  //Moisture, temperature, humidity output on serial monitor
  delay(10);

  if (moisturePercentage < 15) {
    Serial.println("Water low!");   // Immediate watering required
}
  if (moisturePercentage > 15 && moisturePercentage < 25) {
    Serial.println("Watering needed soon!");    // Watering needed very soon
}
  delay(15000);

  ThingSpeak.setField(1, moisture);       //1st field denotes soil moisture
  ThingSpeak.setField(2, temperature);                        //2nd field denotes temperature
  ThingSpeak.setField(3, humidity);                        //3rd field denotes humidity
  ThingSpeak.writeFields(channelNumber, apiKey);    //Write data to corresponding Thingspeak channel for the above 3 fields
}

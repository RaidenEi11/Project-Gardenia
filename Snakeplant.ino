#include <DHT.h>
#include <ESP8266WiFi.h>
String apiKey = "APIKEY";     //  API key here
const char* server = "api.thingspeak.com";
const char *ssid =  "WiFi";     // Enter your WiFi Name
const char *pass =  "Password"; // Enter your WiFi Password
#define DHTPIN D0          // GPIO Pin where the DHT11 is connected
DHT dht(DHTPIN, DHT11);
WiFiClient client;

const int moisturePin = A0;             // Moisture sensor pin
unsigned long interval = 15000;
unsigned long previousMillis = 0;
unsigned long interval1 = 1000;
unsigned long previousMillis1 = 0;
float moisturePercentage;              // Moisture reading
float h;                  // Variable for Humidity reading
float t;                  // Variable for Temperature reading

void setup()
{
  Serial.begin(115200);
  delay(10);
  dht.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");              // Print till not connected
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop()
{
  unsigned long currentMillis = millis(); // Take current time

  h = dht.readHumidity();     // Read humidity
  t = dht.readTemperature();     // Read temperature

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  moisturePercentage = ( 100.00 - ( (analogRead(moisturePin) / 1023.00) * 100.00 ) );   //Formula for calculating soil moisture

  if ((unsigned long)(currentMillis - previousMillis1) >= interval1) {
    Serial.print("Soil Moisture is  = ");
    Serial.print(moisturePercentage);
    Serial.println("%");
    previousMillis1 = millis();
  }

if (moisturePercentage < 50) {
  Serial.println("Water low!");   // Immediate watering required
}
if (moisturePercentage > 50 && moisturePercentage < 55) {
  Serial.println("Watering needed soon!");    // Watering needed very soon
}

if ((unsigned long)(currentMillis - previousMillis) >= interval) {

  sendThingspeak();           // Send data to Thingspeak cloud
  previousMillis = millis();
  client.stop();
}

}

void sendThingspeak() {
  if (client.connect(server, 80))
  {
    String postStr = apiKey;              // add API key in the postStr string
    postStr += "&field1=";
    postStr += String(moisturePercentage);    // Add moisture reading
    postStr += "&field2=";
    postStr += String(t);                 // Add temperature reading
    postStr += "&field3=";
    postStr += String(h);                  // Add humidity reading
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());           // Send length of the string
    client.print("\n\n");
    client.print(postStr);                      // Send complete string
    Serial.print("Moisture Percentage: ");
    Serial.print(moisturePercentage);
    Serial.print("%. Temperature: ");
    Serial.print(t);
    Serial.print(" C, Humidity: ");
    Serial.print(h);
    Serial.println("%. Sent to Thingspeak.");
  }
}

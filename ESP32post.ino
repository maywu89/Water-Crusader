//May Wu
//HackMIT 2019
//ESP32 takes temperature and humidity data read from DHT11by. Data is received in Nose-RED json by specifying 
//HTTP request and the sending actual post.
//Code adapted and modified using open source DHTTester.ino,Simpletime.ino, and ESP 32 tutorial on https://techtutorialsx.com 
//Electronics: DHT11 Temperature & Humidity Sensor, ESP32 
//Connections: ground pin of ESP32 to ground pin of DHT11; 3V3 pin of ESP32 to power pin of DHT11, signal pin of DHT11 
//             connected to digital pin 27 on esp32. 10microF capacitor connecting EN and ground of ESP32
//             (This is needed to boot the ESP32 so we do not have to hold the boot button every time for a new upload.


//Libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "time.h"

//connect esp32 to wifi
 
const char* ssid = "MIT GUEST";
//const char* password =  "yourNetworkPassword";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 68400;
const int   daylightOffset_sec = 3600;

//DHT11 initialization
#define DHTPIN 27     // DHT signal pin connected to digital pin 27
#define DHTTYPE    DHT11     
DHT dht(DHTPIN, DHTTYPE);


void setup() {
 
  Serial.begin(115200);
  delay(4000);   
  dht.begin();
  WiFi.begin(ssid); //(ssid,password) if wifi has password

  //wifi connection
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 
}

 
void loop() {
 String a = "Downtown";
 float t = dht.readTemperature(); //celsius
 float h = dht.readHumidity();
 Serial.println(t);
 Serial.println(h);

 //print time
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  char timeStringBuff[50]; //50 chars should be enough
  strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y, %H:%M:%S,", &timeinfo);
  //print like "const char*"
  //Serial.println(timeStringBuff);
  
  //Optional: Construct String object 
  String asString(timeStringBuff);
  String b = timeStringBuff;
  
 String total = a+","+b+ String(t) + "," + String(h);
 
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   HTTPClient http;   
 
   http.begin("http://lead-pipelines-testing.mybluemix.net/data");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
 
   int httpResponseCode = http.POST(total);   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}

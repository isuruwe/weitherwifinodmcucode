/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>

const char* ssid     = "SW";
const char* password = "ituswl@b";

const char* host = "10.23.30.2";
const char* streamId   = "....................";
const char* privateKey = "....................";
IPAddress ip(10,23,30,221);
IPAddress dns(255,255,255,0);
IPAddress gtw(10,23,30,1);
String acv;
void setup() {
 
  Serial.begin(9600);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.config(ip,gtw,dns);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  
 
}

int value = 0;

void loop() {


  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 11000;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
 
  
acv= Serial.readString();
 Serial.print(acv);
//client.println(rfo.toInt());
  client.print(acv);
 
 
 
}


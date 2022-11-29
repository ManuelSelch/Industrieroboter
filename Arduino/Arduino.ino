#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#ifndef STASSID
#define STASSID "ManuelBot"
#define STAPSK  "password"
#endif
const char* ssid = STASSID;
const char* password = STAPSK;


int inputPin = 2;

int currentClock = 0;
int maxClock = 7;
int startStatus = 0;
int code[8] = {1,1,1,1,1,1,1,1}; 
bool receivingData = false;

void setup() {
  Serial.begin(9600);
  connectWifi();
  otaStart();
  pinMode(inputPin, INPUT_PULLUP);    
}

void loop() {
  delay(1000);
  if(receivingData){
    receiveData();
  }else{
    checkForStartSignal();
  }
}

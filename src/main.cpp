#include <Arduino.h>
#include "credentials.h"
#include<ESP8266WiFi.h>
#include "httphelper.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN,OUTPUT);

  Serial.begin(115200);

  Serial.println("Connecting...");

  WiFi.begin(WIFI_SSID,WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("Connected...\n");


  String URL = "http://f4d5afdfbd82.ngrok.io";

  get(URL);
  post(URL,"SAM");

  get(URL+"/json",1);

  post(URL,"{\"message\":\"GO USCMakers\"}",1);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);

}
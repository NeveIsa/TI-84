#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

void get(String url, int json=0)
{
  Serial.println("\nGETTING...");

  HTTPClient http;
  http.begin(url);

  int code = http.GET();
  Serial.print("STATUS CODE: "); Serial.println(code);
  String response = http.getString();
  Serial.println("RESPONSE: ");
  Serial.println(response);

  if(json)
  {
      const int capacity = 4 * JSON_OBJECT_SIZE(2);
      StaticJsonDocument<capacity> doc;
      DeserializationError e = deserializeJson(doc, response);

      if(e) {
          Serial.println("Deserialization Error:");
          Serial.println(e.c_str());
      }
      else {
              const char* message = doc["message"];
              Serial.println(message);
      }
  }

  http.end();
}


void post(String url, String data,int json=0)
{
  Serial.println("\nPOSTING...");

  HTTPClient http;
   
  http.begin(url);

  String headerContentType = "text/plain";

  if(json) headerContentType = "application/json";

  http.addHeader("Content-type",headerContentType);

  int code = http.POST(data);
  Serial.print("STATUS CODE: "); Serial.println(code);


  Serial.print("Printing response: ");
  String response = http.getString();
  Serial.println();

  http.end();
}
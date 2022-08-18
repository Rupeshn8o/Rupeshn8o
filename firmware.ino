#define BLYNK_TEMPLATE_ID "TMPL-QY8DEep"
#define BLYNK_DEVICE_NAME "SOIL"
#define BLYNK_AUTH_TOKEN "cA2i5ZnvFx0N12Mfx3-YjUArI7GW2hvX"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include <SimpleTimer.h>
#define DHTTYPE DHT11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;
char auth[] = "cA2i5ZnvFx0N12Mfx3-YjUArI7GW2hvX";
char ssid[] = "AndroidAP";
char pass[] = "idjy9009"; 
float t;
float h;
void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}

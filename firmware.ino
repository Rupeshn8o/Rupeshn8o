#define BLYNK_TEMPLATE_ID "TMPL-QY8DEep"
#define BLYNK_DEVICE_NAME "SOIL"
#define BLYNK_AUTH_TOKEN "cA2i5ZnvFx0N12Mfx3-YjUArI7GW2hvX"
#define BLYNK_PRINT Serial]
#define BlynkTimer timer
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
char ssid[] = "AndroidAP";
char pass[] = "idjy9009";
char auth[] = "cA2i5ZnvFx0N12Mfx3-YjUArI7GW2hvX"; 
float t;
float h;
int soil; 
int flo;
float j

void myTimer() 
{
  Blynk.virtualWrite(V1, soil);
  Blynk.virtualWrite(V0, flo);  
}

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth,ssid,pass);
    dht.begin();
    timer.setInterval(2000,sendUptime);
    Blynk.begin(auth, ssid, pass); 
    timer.setInterval(1000L, myTimer); 
     pinMode(moat,OUTPUT);
     pinMode(moist,INPUT);
     pinMode(flo,INPUT);
    float j = dht.readHumidity();
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
  soil = digitalRead(4);
  flo = digitalRead(2); 
  j = analogRead(0);
} 

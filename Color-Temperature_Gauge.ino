#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int r=0, g=0, b=0;


#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
  
void setup() {
Serial.begin(9600);
Serial.println(F("DHTxx test!"));
dht.begin();


strip.begin();          
strip.show();           
strip.setBrightness(50);


}

void loop()
{
  delay(2000);
  float f = dht.readTemperature(true);
  
  if (isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
    
}

 int fValue = digitalRead(2);

  if ((60 <= f) && (f <= 80)) g=-2.55*f*f+357*f-12240;
  if ((60 <= f) && (f <= 80)) r=12.75*f-765;
  if ((60 <= f) && (f <= 80)) b=-12.75*f+1020;


  Serial.print(f);

  strip.setPixelColor(0, r, g, b); 
  strip.setPixelColor(1, r, g, b); 
  strip.setPixelColor(2, r, g, b); 
  strip.setPixelColor(3, r, g, b); 
  strip.setPixelColor(4, r, g, b); 
  strip.setPixelColor(5, r, g, b); 
  strip.setPixelColor(6, r, g, b); 
  strip.setPixelColor(7, r, g, b); 
  strip.setPixelColor(8, r, g, b); 
  strip.setPixelColor(9, r, g, b); 


delay (1000);
strip.show();
}

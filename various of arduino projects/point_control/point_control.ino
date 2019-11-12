#include <Adafruit_NeoPixel.h>
int PIN = 6;
int NUMPIXELS = 8;
uint32_t last_millis = 0;
uint32_t last_millisY= 0;
uint32_t last_millis1= 0;
uint32_t last_millis2= 0;
int brightness1 = 70;
int brightness2 = 20;
int i;
int DELAYVAL = 200;
int brightness = 150;
int counter = 0;
int counter1 = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(115200);
}




        
void loop() {
  int Y =analogRead(A6);

  if(millis()- last_millis > 100){
    if ( Y < 100){
      i++;
      if (i > 7){
        i = 7;
      }
      pixels.clear();
      pixels.setPixelColor(i, pixels.Color(0, brightness,0));
      pixels.show();
      
      
    }
    if ( Y > 1000){
      i--;
      if (i < 0){
        i = 0;
      }
      pixels.clear();
      pixels.setPixelColor(i, pixels.Color(0, 150,0));
      pixels.show();
      
    }
    last_millis = millis();
    Serial.println(last_millis);
  }
  
  
    
  if( millis() - last_millisY > 100){
    //Serial.println(Y);
    uint32_t last_millisY = millis();
    Serial.println(i);
  }
}

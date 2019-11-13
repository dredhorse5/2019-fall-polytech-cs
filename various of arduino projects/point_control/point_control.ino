#include <Adafruit_NeoPixel.h>
int PIN = 6;
int NUMPIXELS = 8;
uint32_t last_millis = 0;
uint32_t last_millisY= 0;
int i;
int brightness = 150;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(115200);
}




        
void loop() {
  int Y =analogRead(A6);
  int DELAYVAL = analogRead(A5);
  int RED = map(analogRead(A4), 0, 1023, 0, 150);
  int GREEN = map(analogRead(A3), 0, 1023, 0, 150);
  int BLUE = map(analogRead(A2), 0, 1023, 0, 150);

  if(millis()- last_millis > DELAYVAL){
    if ( Y < 100){
      i++;
      if (i > 7){
        i = 7;
      }
      pixels.clear();
      pixels.show();
      
      
    }
    if ( Y > 1000){
      i--;
      if (i < 0){
        i = 0;
      }
      
    }
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(RED, GREEN,BLUE));
    pixels.show();
    last_millis = millis();
  }
  
  
    
  if( millis() - last_millisY > 200){
    //Serial.println(Y);
    last_millisY = millis();
    Serial.println(i);
    Serial.println(RED);
    Serial.println(GREEN);
    Serial.println(BLUE);
  }
}

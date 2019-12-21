#include <Adafruit_NeoPixel.h>
int PIN = 6;
int NUMPIXELS = 8;
uint32_t last_millis_red = 0;
uint32_t last_millis_green = 0;
uint32_t last_millis_blue = 0;
int red = 50;
int green= 50;
int blue = 50;
int r = 1;
int g = 1;
int b = 1;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  //====================================================
  if (millis()-last_millis_red > 30){
    red += r*random(2,3);
    if (red >= 245 or red <= 5){
      r *= -1;
    }
    last_millis_red = millis();
  }
  //====================================================
  if (millis()-last_millis_green >20){
    green += g*random(1,2);
    if (green >= 245 or green <= 5){
      g *= -1;
    }
    last_millis_green = millis();
  }
  //====================================================
  if (millis()-last_millis_blue >25){
    blue += b*random(3,4);
    if (blue >= 245 or blue <= 5){
      b *= -1;
    }
    last_millis_blue = millis();
  }
  //====================================================
  for( int i; i < 8; i++){
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
  }
    pixels.show();
}

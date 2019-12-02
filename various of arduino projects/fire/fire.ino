#include <Adafruit_NeoPixel.h>
int mode = 0;
int PIN = 6;
int NUMPIXELS = 8;
int DELAYVAL = 500;
int last_millis = 0;
int last_millis_LOW = 0;
int fire[8] = {160, 160, 160, 160, 160, 160, 160, 160};
int num_mode[2] = {0,0,0};
int fire_mode1 = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  if( millis() - last_millis > DELAYVAL){
    mode = random(0, 1000);
    if(mode>0 && mode < 100){
      num_mode[0] = 8
    }
    
    for( int i = 0; i <= 2; i++){
      if( num_mode[i] > 0){
        if(i = 0){
          mode1();
        }
        if( i = 1){
          mode2();
        }
        if (i = 2){
          mode3();
        }
      }
    }


//===========================================================================   
    if(millis() - last_millisY > 5){
    Serial.print("a");
    for(int num = 0; num <= NUMPIXELS; num++){
      if(tail[num] > 1){
        tail[num] = tail[num] - brightness;
        if( tail[num] < 0) tail[num] = 0;
        pixels.setPixelColor(num, pixels.Color(tail[num],0,tail[num]));
      }
    }
  }
//===========================================================================
  pixels.show();
}

void mode1(){
  pixels.setPixelColor(fire_mode1, pixels,Color(160, 0,0);
}

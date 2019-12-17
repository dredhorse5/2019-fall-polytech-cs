#include <Adafruit_NeoPixel.h>
int tail[8] = {160, 160, 160, 160, 160, 160, 160,160};
int PIN = 6; // пин светодиодной ленты
int NUMPIXELS = 8; // колличество светодиодов
int brightness = 5 ; // скорость затухания светодиода
int DELAYVAL = 0;
int DELAYVAL_TAIL = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//======================Нужные переменные======================
uint32_t last_millis = 0;
uint32_t last_millisX= 0;
uint32_t last_millisY= 0;
int led= 0;
int n = 0;
int last_led = 0;
//=============================================================

void setup() {
  pixels.begin();
  Serial.begin(115200);
}
       
void loop() {
  //pixels.clear();
  int Y = analogRead(A6); // движение светодиода
  int DELAYVAL = analogRead(A5); // скорость движения светодиода
  int DELAYVAL_TAIL = map(analogRead(A7), 0, 1023, 0, 100); // скорость затухания хвоста
  if(millis()- last_millis > DELAYVAL){
    last_led = led;
    //====================================
    if ( Y < 100){
      led++;
      if (led > 7) led = 7; 
    }
    
    if ( Y > 1000){
      led--;
      if (led < 0) led = 0; 
    }
    //=====================================
    if( last_led - led < 0){
      n = led - 1;
      tail[n] = 160;
    }
    if( last_led - led > 0){
      n = led + 1;
      tail[n] = 160;
    }
    last_millis = millis();
  }
  
  if(millis() - last_millisY > DELAYVAL_TAIL){
    Serial.print("a");
    for(int num = 0; num <= NUMPIXELS; num++){
      if(tail[num] > 1){
        tail[num] = tail[num] - brightness;
        if( tail[num] < 0) tail[num] = 0;
        pixels.setPixelColor(num, pixels.Color(tail[num],0,tail[num]));
      }
    }
    //=====================================
   
    pixels.setPixelColor(led, pixels.Color(160,0,160));
    pixels.show();
    last_millisY = millis();
  }
  
}

/*void printSerial(){
  if( millis() - last_millisY > 200){
    //Serial.print(tail[0]); Serial.print(tail[1]) ;Serial.print(tail[2]); Serial.print(tail[3]); Serial.print(tail[4]); Serial.print(tail[5]); Serial.print(tail[6]); Serial.print(tail[7]);
    //Serial.println(" ");
    //Serial.println(n);
    //Serial.println(Y);
    //last_millisY = millis();
    //Serial.println(led);
    //Serial.println(RED);
    //Serial.println(GREEN);
    //Serial.println(BLUE);
  }
}*/

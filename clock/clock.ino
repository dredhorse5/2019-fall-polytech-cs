#include <GyverEncoder.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
boolean buttonKey = true;
int hours = 0;
int minutes = 0;
int seconds = 0;
int a,b,c,count, switchON, hoursIS, minutesIS, secondsIS;
uint32_t last_millis = 0;
LiquidCrystal_I2C lcd(0x3F,16,2);
Encoder enc(4, 3, 2, TYPE2);
//=====================================================
void setup() {
  lcd.init();                      
  lcd.backlight();
  Serial.begin(9600);
}
//=====================================================


void encoder(){
  enc.tick();
  if (enc.isRightH() and switchON > 0){
    count--;
    if(switchON > 0){
      switchON = 4;
    }
  }
  if (enc.isLeftH() and switchON > 0){
    count++;
    if(switchON > 0){
      switchON = 4;
    }
    
  }
  if (enc.isClick()){
    switchON = 4;
  }
}
//=====================================================

void clockMY(){
  hours = millis()/3600000 - a*24 + hoursIS;
  minutes = millis()/60000 - b*60 + minutesIS;
  seconds = millis()/1000 - c*60 + secondsIS;
  
  if(hours > 23){
    a++;
  }if(hours < 0) hoursIS = 0;
  
  if(minutes > 59){
    b++;
  }if(minutes < 0) minutesIS = 0;
  
  if(seconds > 59){
    c++;
  }if(seconds < 0) secondsIS = 0;
  
  if (count < 0) count = 2;
  if (count > 2) count = 0;
}
//=====================================================


void displayMY(){
  lcd.setCursor(6,0);
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds);
  lcd.print("    ");
  

}

//=====================================================
void loop() {
  encoder();
  clockMY();
  displayMY();
  
  if(millis() - last_millis > 1000 ){
    switchON--;
    if(switchON < 0){
      switchON = 0;
    }
    last_millis = millis();
  }


  
  if (switchON > 0){
    switch(count){
      case 0:
        if (enc.isRight()){
          hoursIS++;
          switchON = 4;
        }
        if (enc.isLeft()){
          hoursIS--;
          switchON = 4;
        }
        lcd.setCursor(0,1);
        lcd.print("hours");
        lcd.print("   ");
        break;
        
      case 1:
        if (enc.isRight()){
          minutesIS++;
          switchON = 4;
        }
        if (enc.isLeft()){
          minutesIS--;
          switchON = 4;
        }
        lcd.setCursor(0,1);
        lcd.print("minutes");
        lcd.print("   ");
        break;
        
      case 2:
        if (enc.isRight()){
          secondsIS++;
          switchON = 4;
        }
        if (enc.isLeft()){
          secondsIS--;
          switchON = 4;
        }
        lcd.setCursor(0,1);
        lcd.print("seconds");
        lcd.print("   ");
        break;
    }
  }
  
  if (switchON == 0){
    lcd.setCursor(0,1);
    lcd.print("       ");
  }
}
//=====================================================



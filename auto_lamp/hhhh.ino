#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,16,2);
int led = 3;
unsigned long timer = 1;
int days = 0;
unsigned long night = 24*60*60;
int minuteKey = 0;
//==============================рассвет
unsigned long morning_start = timer* 9; //время начала рассвета
unsigned long morning_end = timer *  10;  // время конца рассвета
//======конец рассвета=== начало заката
uint32_t evening_start = timer * 19;  // время начала заката
uint32_t evening_end = timer *   20;  // время конца
//=========================конец заката

void setup() {
  pinMode(led, OUTPUT);
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hour");
  //lcd.setCursor(7,0);
  //lcd.print("day");
  //lcd.setCursor(0,1);
  //lcd.print("status");
  
}

void loop() {
  int hours = millis()/3600000 - days*24;
  int minutes = millis()/60000 - minuteKey*60;
  if(minutes >= 90){
    minuteKey++;
  }
  lcd.setCursor(6,0);
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print("  ");
  if(hours> morning_start and morning_end > hours){
    int i = map(minutes, 0, 60, 0, 255);
    analogWrite(led, i);
    //Serial.println("EEEEEEEEEEEEEEEEEEEEEEE");
  }
  if(hours>morning_end and evening_start< hours){
    digitalWrite(led, HIGH);
  }
  if(hours > evening_start and evening_end < hours){
    int k = map(minutes, 0, 60, 255, 0);
    analogWrite(led, k);
  }
  if(hours > evening_end and night < hours){
    digitalWrite(led, LOW);
  }
  if(hours>=1000*60*60*24){
    days ++;
  }
  
}

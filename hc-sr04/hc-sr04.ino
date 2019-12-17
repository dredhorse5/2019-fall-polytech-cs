#include <hcsr04.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define ECHO_PIN  11
#define TRIG_PIN  10
#define TIMEOUT  30000
LiquidCrystal_I2C lcd(0x3F,16,2);
int trigPin = 10; 
int echoPin = 11;
HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, TIMEOUT);
uint32_t last_millis = 0;
uint32_t last_distance = 0;
uint32_t distance = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  hcsr04.begin();
}

void loop() {
  distance = hcsr04.getDistanceMm();
  if(millis()- last_millis > 200){
    int velocity = (distance - last_distance)/0.2;
    last_distance = distance;
    
    lcd.setCursor(0,0);
    lcd.print(distance);
    lcd.print(" mm  ");

    lcd.setCursor(0,1);
    lcd.print(velocity);
    lcd.print(" mm/s   ");
    last_millis = millis();
    
  }

}

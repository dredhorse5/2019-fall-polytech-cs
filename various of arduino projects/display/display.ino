#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3F,16,2); // Указываем I2C адрес (наиболее распространенное значение), а также параметры экрана (в случае LCD 1602 - 2 строки по 16 символов в каждой 


void setup()
{
  lcd.init();                      // Инициализация дисплея  
  lcd.backlight();                 // Подключение подсветки
  lcd.setCursor(0,0);              // Установка курсора в начало первой строки
  lcd.print("Hello");       // Набор текста на первой строке
  lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  lcd.print("ArduinoMaster");       // Набор текста на второй строке
  
  delay(3000);
  lcd.clear();
}


void loop(){
  for(int i = 0; i < 50; i++){
    lcd.setCursor(0,0);
    lcd.print(i);
    delay(200);
    
  }
}

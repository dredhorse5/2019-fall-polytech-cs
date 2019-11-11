int red = 5; 
int green = 6;
int blue = 9;
int yellow = 11;

int mode = 2;

//int touch = 8;
int O;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  //pinMode(touch, INPUT);
  attachInterrupt(0, modeS, RISING);
}
//=========================================================
void mode1(){
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}
//=========================================================
void mode2(){
  int counter = 0;
  
  switch(counter){
    case 0:
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(yellow, LOW);
      delay(150);
      break;
    
    case 1:
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(yellow, LOW);
      delay(150);
      break;
    
    case 2:
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      digitalWrite(yellow, LOW);
      delay(150);
      break;
  
    case 3:
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      digitalWrite(yellow, LOW);
      delay(150);
      break;
  }
  counter ++;
  if(counter > 3){
    counter = 0;
  }
}
//=========================================================
void mode3(){
  for(int k = 1; k < 255; k += 1){
    analogWrite(red, k);
    analogWrite(green, k);
    analogWrite(blue, k);
    delay(1);
  }
  for(int k = 255; k > 1; k -= 1){
    analogWrite(red, k);
    analogWrite(green, k);
    analogWrite(blue, k);
    delay(1);
  }
}
//=========================================================
void mode4(){

  for( int red_value = 255; red_value > 1; red_value--){
    int green_value = 256 - red_value;
    analogWrite(red, red_value);
    analogWrite(green, green_value);
    delay(1);
  } 
  
  for( int green_value = 255; green_value > 1; green_value--){
    int blue_value = 256 - green_value;
    analogWrite(green, green_value);
    analogWrite(blue, blue_value);
    delay(1);  
  } 
  
  for(int blue_value = 255; blue_value > 1; blue_value--){
    int red_value = 256 - blue_value;
    analogWrite(blue, blue_value);
    analogWrite(red, red_value);
    delay(1);  
  }

}
//=========================================================

void mode5(){
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(120);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(250);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(120);
  
  
}

void mode6(){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
}

/*void modeS(){
  if(digitalRead(touch) == HIGH){
    mode++;
    if (mode>6){
      mode = 0;
    }
    Serial.print("Eah");
  }*/
void modeS(){
  if(Serial.available() > 0){
    int k = Serial.read() - '0';
    Serial.print(k);
    if (k = 1){ mode = 1;Serial.println('1');}
    if (k = 2){ mode = 2;Serial.println('2');}
    if (k = 3){ mode = 3;Serial.println('3');}
    if (k = 4){ mode = 4;Serial.println('4');}
    if (k = 5){ mode = 5;Serial.println('5');}
    if (k = 6){ mode = 6;Serial.println('6');}
  }
  
  
}


void loop(){
  switch (mode) {
    case 0:
      mode1();
      break;
      
    case 1:
      mode2();
      break;
      
    case 2:
      mode3();
      break;
      
    case 3:
      mode4();
      break;
      
    case 4:
      mode5();
      break;
      
    case 5:
      mode6();
      break;
  }
}

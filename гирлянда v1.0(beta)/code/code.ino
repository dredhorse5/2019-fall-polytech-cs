int red = 5;
int green = 6;
int blue = 9;

int mode;

int touch = 2;
int counter = 10;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(touch, INPUT);
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
  int L = counter % 3;

  if( L == 0){
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(150);
  }
  if(L == 1){
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(150);
  }
  if(L == 2){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(150);
  }
  counter ++;
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
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(120);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(250);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  delay(120);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(120); 
}

void mode6(){
  
}

void modeS(){
  if(digitalRead(touch) == HIGH){
    mode++;
    if (mode>5){
      mode = 0;
    }
    Serial.print("Eah"); 
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
  }
}

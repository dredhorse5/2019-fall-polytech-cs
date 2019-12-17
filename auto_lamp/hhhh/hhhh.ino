int led = 3;
int minuteKey = 0;
int days;
//==============================рассвет
int morning_start =60* 9 ; //время начала рассвета в часах
int morning_end =60*   10;  // время конца рассвета в часах
//======конец рассвета=== начало заката
int evening_start =60
*  18;  // время начала заката в часах
int evening_end =60*    19;  // время конца в часах
//=========================конец заката

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  int minutes = millis()/60000 - days*1440; 
  if(minutes>= morning_start and morning_end > minutes){
    int i = map(minutes, morning_start , morning_end, 0, 255);
    analogWrite(led, i);
  }
  
  if(minutes >= morning_end and evening_start> minutes) digitalWrite(led, HIGH);
    
  
  if(minutes >= evening_start and evening_end > minutes){
    int i = map(minutes, evening_start, evening_end, 255, 0);
    analogWrite(led, i);
    }
  
  if(minutes >= evening_end) digitalWrite(led, LOW);
  
  if(minutes >= 1440) days ++;
  
}

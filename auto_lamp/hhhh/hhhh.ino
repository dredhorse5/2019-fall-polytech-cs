int led = 3;
int minuteKey = 0;
float days;
//==============================рассвет
float morning_start =60* 0 ; //время начала рассвета в часах
float morning_end =60*   0.01;  // время конца рассвета в часах
//======конец рассвета=== начало заката
float evening_start =60*  0.02;  // время начала заката в часах
float evening_end =60*    0.05;  // время конца в часах
//=========================конец заката
//( (x - in_min) * (out_max - out_min) / (in_max - in_min) - out_min )

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float minutes = float(millis())/60000 - days*1440; 
  if(minutes>= morning_start and morning_end > minutes){
    int i = ( (minutes - morning_start) * (255 - 0) / (morning_end - morning_start) - 0 );
    analogWrite(led, i);
  }
  
  if(minutes >= morning_end and evening_start> minutes) digitalWrite(led, HIGH);
    
  
  if(minutes >= evening_start and evening_end > minutes){
    int i = 255 - ((minutes - evening_start) * (255 - 0) / (evening_end - evening_start) - 0 );
    analogWrite(led, i);
    }
  
  if(minutes >= evening_end) digitalWrite(led, LOW);
  
  if(minutes >= 1440) days ++;
  
}

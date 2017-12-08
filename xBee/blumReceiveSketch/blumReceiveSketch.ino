//Xbee send sketch


const int red = 3;
const int green = 5;
const int speaker = 6;

char data;
int onLed = green;
int offLed = red;
int freq = 131;
unsigned long prev_time = 0;

void setup(){
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(speaker,OUTPUT);
}

void loop(){
  if (millis()>= prev_time + 100)
  {
    if (onLed == green)
    {
     onLed = red;
     offLed = green;
    }else
    {
      onLed = green;
      offLed = red;
    }
    if (freq == 261)
    {
      freq = 131;
    }else{
      freq = 261;
    }
    prev_time = millis();
  }
  if (Serial.available() > 0 )
  {
    data = Serial.read();
    if (data == '1')
    {
      digitalWrite(onLed,HIGH);
      digitalWrite(offLed,LOW);
      tone(speaker, freq);
    }
    else if (data =='0')
    {
      digitalWrite(onLed,LOW);
      digitalWrite(offLed,LOW);
      noTone(speaker);
    }
  }
}
  


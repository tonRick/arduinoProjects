// Serial Parse Using C functionsto be read by Arduino
//Uses page 103 of Arduino Cookbook

int index = 0; //index variable
const int ledPin = 13;
int value = 0;
int blinkRate = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop(){
  if(Serial.available()) // is there data?
  {
    char ch = Serial.read();  // read the data if available
    if(isDigit(ch) ) 
       value = value*10 + (ch-'0'); //append digits to array
    else if (ch == '\n')
    {
      blinkRate = value;
      Serial.println(value);
     value = 0;
    }
  }
  blinker();
} 
 void blinker()
 {
     digitalWrite(ledPin,HIGH);
     delay(blinkRate);
     digitalWrite(ledPin,LOW);
     delay(blinkRate);
}

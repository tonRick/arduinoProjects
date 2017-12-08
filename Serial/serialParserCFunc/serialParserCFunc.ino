// Serial Parse Using C functionsto be read by Arduino
//Uses page 103 of Arduino Cookbook

const int maxChars = 5; // sets the max string length
char strValue[maxChars+1]; //max length + terminating null
int index = 0; //index variable
const int ledPin = 13;
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
    if(index < maxChars && isDigit(ch) ) 
       strValue[index++] = ch; //append digits to array
    else 
    {
      strValue[index] = 0;
      blinkRate = atoi(strValue);
      Serial.println(atoi(strValue));
     index = 0;
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

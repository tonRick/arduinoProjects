
const int ledPin = 13;
int blinkRate = 0;
int value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  blinker();
}

void serialEvent()
{
  while(Serial.available()>0)
  {
    char ch = Serial.read();
    if (isDigit(ch))//new line is not a digit, so exits
    {
      value = value*10 + (ch-'0');
    }

  }
  Serial.println(value);
  blinkRate = value;
  value = 0;
}

void blinker()
{
  long time = millis()
  digitalWrite(ledPin,HIGH);
  delay(blinkRate);
  digitalWrite(ledPin,LOW);
  delay(blinkRate);
}

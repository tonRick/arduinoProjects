//  Sketch to test the use of interrupts. 

const int ledPin = 11;
const int ledPin2 = 10;
const int buttonInt = 0;

volatile int selectedLED = ledPin;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  attachInterrupt(0,onOff,HIGH);
}
void onOff()
{
  analogWrite(selectedLED,0);
  if(selectedLED == ledPin)
    selectedLED = ledPin2;
  else selectedLED = ledPin;
}

void loop()
{
  Serial.println(selectedLED);
  for (int ii = 0; ii < 256; ii++)
    { 
      analogWrite(selectedLED,ii);
      delay(10);
    }
    for (int ii = 255; ii>=0; ii--)
    {
      analogWrite(selectedLED,ii);
      delay(10);
    }
}




//  Sketch to test the use of interrupts. 

const int ledPin = 11;
const int buttonInt = 0;
volatile boolean onOffBool;
int selectedLED = ledPin;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  attachInterrupt(0,onOff,HIGH);
}
void onOff()
{
  onOffBool = !onOffBool;
}

void loop()
{
  for (int ii = 0; ii < 206; ii++)
    { if(onOffBool ==1)
      {
      ledFade(ii);
      }else analogWrite(selectedLED,0);
    }
   for (int ii = 205; ii>=0; ii--)
    {if(onOffBool ==1)
      {
      ledFade(ii);
      }else analogWrite(selectedLED,0);
    }
}

void ledFade(int iter)
{
      analogWrite(selectedLED,iter);
      Serial.println(onOffBool);
      delay(10);
}


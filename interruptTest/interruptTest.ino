
int led[] = {8, 7};
int numLed = 2;
int ledPrev = 0;
int buttonPin = 0;
int pwmPin = 3;

int previousVal;
volatile int selectedLed = 0;
volatile int value;

void setup()
{
  
  for (int ii = 0; ii <numLed; ii++)
  {
   pinMode(led[ii],OUTPUT);
  }
  pinMode(buttonPin,OUTPUT);
  pinMode(pwmPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led[0],HIGH);
  previousVal = 0;
  attachInterrupt(buttonPin,valueChange,RISING);
}

void valueChange()
{
  if (selectedLed == 0)
  value = 128;
  if (selectedLed == 1)
  value = 20;
}

void loop()
{
  for(int ii = 0; ii<numLed;ii++)
  {
    digitalWrite(led[ii],HIGH);
    digitalWrite(led[ledPrev],LOW);
    selectedLed = ii;
    analogWrite(pwmPin,value);
    Serial.println(value);
    delay(1000);
    
    ledPrev = ii;
    }

}
  

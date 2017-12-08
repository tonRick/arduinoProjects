
const int ledPin = 11;
const int buttonPin = 12;
const int potPin = 14;
int potValue = 0;
boolean onOff = 0; //boolean for lighting 
boolean statePrevious; //boolean to see if button is held
unsigned long prev_iter = 0; // timer variable
unsigned long send_iter = 0;
const int loopTimer = 10; // loop timing variable

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  
}

void loop(){
  Serial.flush();
  if (millis() > prev_iter + loopTimer) //delay for loop
    {
     boolean buttonState = digitalRead(buttonPin); //variable to check button
     delay(5); //delay to debounce  
     if (buttonState && buttonState != statePrevious)
     {
        onOff  = !onOff;// if there is a low signal, that isn't held, toggle
      }
      //if it is off, turn the light off, if it is not 0, 
      //check the status of the potentiometer and turn on the led to this value
     if (onOff == 0)
     {
       analogWrite(ledPin,0);
     } else
     {  // if 1, check value and turn LED to this value
       potValue = getPotValue();
       analogWrite(ledPin,potValue);
     }
     //if a second has passed, send to Serial
     if(millis() > send_iter + loopTimer*25)
     {
       sendToSerial();
       send_iter = millis();
     }
     statePrevious = buttonState; //set old to new
     prev_iter = millis();
    }
}

int getPotValue()
{
  return map(analogRead(potPin),0,1023,0,255);
}

void sendToSerial()
{
  Serial.print(onOff);
  Serial.print(",");
  Serial.print(potValue);
  Serial.print('\n');
}
  

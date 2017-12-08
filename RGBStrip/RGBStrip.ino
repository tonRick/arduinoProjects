
//Script Written by Dan Godrick
//Dec 2014
//Using Jeremy Blum's Exploring Arduino


//Variable declarations - Red, Green, Blue values will be used to 
//control intensity and color. Pins 3,5,6 will be used as PWM control

int redVal = 255;
int greenVal = 255;
int blueVal = 255;

const int redOut = 3;
const int greenOut = 5;
const int blueOut = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(redOut,OUTPUT);
  pinMode(greenOut,OUTPUT);
  pinMode(blueOut,OUTPUT);
  Serial.println("Please enter 3 numbers separated by commas");
}

void loop()
{
  while (Serial.available()>0) //If there is information available
  {
    redVal = Serial.parseInt();
    greenVal = Serial.parseInt();
    blueVal = Serial.parseInt();
    
    if (Serial.read() == '\n') //newline sets values
    {
      analogWrite(redOut,redVal);
      analogWrite(greenOut,greenVal);
      analogWrite(blueOut,blueVal);
      Serial.print(redVal);
      Serial.print(",");
      Serial.print(greenVal);
      Serial.print(",");
      Serial.println(blueVal);
      
    }
  }
}

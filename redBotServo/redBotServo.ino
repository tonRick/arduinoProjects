

#include <RedBot.h>
#include <Servo.h>
RedBotMotors motors;

Servo dgServo;

// Create a couple of constants for our pins.
const int buzzerPin = 8;
const int servoPin = 9;
const int buttonPin = 12;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT);  // configures the buzzerPin as an OUTPUT
  
  pinMode(13,OUTPUT);
  pinMode(14,INPUT);
  pinMode(A1,OUTPUT);
  dgServo.attach(servoPin);
  Serial.begin(9600);
}

void loop()
{ 
  int light = analogRead(14);
  int mapped = map(light,0,800,128,255);
  boolean val1 = digitalRead(buttonPin);
  Serial.println(light);
  if (val1 == LOW){
    dgServo.write(165);
  } else{
      if ( light >= 400) // if the button is pushed (LOW)
      { 
        dgServo.write(90);
        digitalWrite(13,HIGH);
        digitalWrite(A1,HIGH);
    
      } else  // otherwise, do this.
      { 
        dgServo.write(20);
        digitalWrite(13,LOW);
        digitalWrite(A1,LOW);
      }
  }
}



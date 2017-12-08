/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#define trigPin 12
#define echoPin 13
#define ledPin 9

const int brightness = 255;
const int maxDist = 36; //inches
const int minDist = 2; //inches
int prevDistance = 0; //to sort read errors
int LEDlevel = 0;
boolean logic = 0;



void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int distance = distanceFind();
  if (distance < maxDist)
  {
    if (distance > minDist)
    {
      LEDlevel = 255;
    } else LEDlevel = 0;
    analogWrite(ledPin,LEDlevel);
    Serial.print(distance);
    Serial.print(","); 
    Serial.print(LEDlevel);
    Serial.print('\n');
    delay(50);
    logic = 0;    
  }else 
  {if (logic == 0)
    {     
      digitalWrite(ledPin,LOW);
      Serial.print(0);
      Serial.print(","); 
      Serial.print(0);
      Serial.print('\n');
      delay(50);
      Serial.print(0);
      Serial.print(","); 
      Serial.print(0);
      Serial.print('\n');
      delay(100);
      Serial.print(0);
      Serial.print(","); 
      Serial.print(0);
      Serial.print('\n');
      logic = !logic;
    }
  }
}

int distanceFind()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / (29.1*2.54); //distance inches
  return distance;
}


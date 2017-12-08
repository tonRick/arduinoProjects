#include<Servo.h>

Servo finger;
int anglePrev = 10;
int initialVal = 0;

void setup() {
 Serial.begin(9600);
 pinMode(14,INPUT);
 pinMode(13,OUTPUT); //status pin
 finger.attach(9);
 finger.write(0);
 delay(1000);
 initialVal = analogRead(14); 
}

void loop() {
  int flexVal = analogRead(14);
  flexVal = constrain(flexVal,initialVal,initialVal+120);
  Serial.print("FlexVal \t");
  Serial.println(flexVal);
  int angle = map(flexVal,initialVal,initialVal+120,10,165);
  int angleAvg = (angle+anglePrev)/2;
  Serial.print(angleAvg);
  finger.write(angleAvg);
  delay(150);
  anglePrev= angle;
  
}


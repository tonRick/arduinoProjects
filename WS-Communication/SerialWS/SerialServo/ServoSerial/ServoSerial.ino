/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */


#include <Servo.h>

Servo myservo;
int led       =   10;
int servoPin  =    9;
int hit       =   11;
int hit2      =   12;
int moveServo ;
int angle ;
int angleInc = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  angle = 105;
  pinMode(led, OUTPUT);
  pinMode(hit,OUTPUT);
  pinMode(hit2,OUTPUT);
  myservo.attach(9);
  myservo.write(angle);
  Serial.begin(9600);  //Bluetooth rate  
}

// the loop routine runs over and over again forever:
void loop() {
  // wait for serial input  
  if (Serial.available() > 0) {  
    // read the incoming byte:  
    moveServo = Serial.read();
    //moveServo = Serial.parseInt() ; 

//  
//    // ASCII '<' is 44, ASCII '>' is 46 (comma and period, really)  
  if (moveServo == 44) { angle = angle - angleInc; }  
   if (moveServo == 46) { angle = angle + angleInc; }  
   if (moveServo == 118) { angle = 90; }
   if (moveServo == 49) { 
            angle = 20;
            digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
           }  
   if (moveServo == 50) {
            angle = 105;
            digitalWrite(led, LOW);  // turn the LED on (HIGH is the voltage level)
           }
   if (moveServo == 51) {
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, LOW);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, LOW);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, LOW);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, LOW);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit2, LOW);
             
         }        
           
 
    // print pulseWidth back to the Serial Monitor (uncomment to debug)  
    myservo.write(angle);
    Serial.println(moveServo);
    Serial.println("Angle: ");  
    Serial.println(angle);      
  }  
  
  
  
}

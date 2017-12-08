/*
This code controls a servo for a remotely operated door
 */


#include <Servo.h> //include the servo library
#include <SoftwareSerial.h>

Servo myservo; // define myservo
int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int led       =   10; //led definition to tell which door is open
int servoPin  =    9; //pwm (~) pin for servo control
int hit       =   11; //Hit must be specified via LED
int hit2      =   12; //Hit must be specified via LED
int moveServo ;  //integer from Serial
int angle ;      //integer to servo
int angleInc = 10; //set door open using incrementing

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  angle = 105; //Initial angle set as 105 degrees
  pinMode(led, OUTPUT); //led is output
  pinMode(hit,OUTPUT);  //hit output
  pinMode(hit2,OUTPUT); //hit 2 - flashing output
  myservo.attach(9);  //attach servo to pin 9 on Arduino
  myservo.write(angle); // move the servo to the angle 
  Serial.begin(115200);//115200);  //115200 is Bluetooth rate
  bluetooth.begin(115200);  
}

// the loop routine runs over and over again forever:
void loop() {
  // wait for serial input  
  if (bluetooth.available() > 0) {  
    // read the incoming byte:  
    moveServo = bluetooth.read(); 
    //moveServo = Serial.parseInt() ; 

//  
//    // ASCII ',' is 44, ASCII '.' is 46, 'v' is 118  
  if (moveServo == 44) { angle = angle - angleInc; }  
  if (moveServo == 46) { angle = angle + angleInc; }  
  if (moveServo == 118) { angle = 90; }
  if (moveServo == 49) {//ascii 49 is '1' 
            angle = 20;
            digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
           }  
   if (moveServo == 50) {//ascii 50 is '2'
            angle = 105;
            digitalWrite(led, LOW);  // turn the LED on (HIGH is the voltage level)
           }
   if (moveServo == 51) {//ascii 51 is '3'
             bluetooth.println("HIT!!!");
             Serial.println("HIT!!");
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, HIGH);  // turn the LED on (HIGH is the voltage level)
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit, LOW);
             digitalWrite(hit2, HIGH);
             delay(250);
             digitalWrite(hit2, LOW);

             
         }        
           
 
    // print pulseWidth back to the Serial Monitor (uncomment to debug)  
    myservo.write(angle);
    bluetooth.print("ASCII Code: ");
    bluetooth.println(moveServo);
    bluetooth.print("Angle: ");  
    bluetooth.println(angle);
    bluetooth.println();
    bluetooth.println();
    Serial.print("Angle: ");
    Serial.println(angle);    
  }  
  
  
  
}

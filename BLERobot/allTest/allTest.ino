#include <Servo.h> 
#include <Metro.h>
Metro measureDistance = Metro(50);
Metro sweepServo = Metro(20);

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control
unsigned long actualDistance = 0;

Servo myservo;  // create servo object to control a servo 
int pos = 60; 
int sweepFlag = 1;

int URPWM = 3; // PWM Output 0－25000US，Every 50US represent 1cm
int URTRIG= 10; // PWM trigger pin
uint8_t EnPwmCmd[4]={0x44,0x02,0xbb,0x01};    // distance measure command
 
void setup(){                                 // Serial initialization
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT); 
  myservo.attach(9); 
  Serial.begin(9600);                         // Sets the baud rate to 9600
  SensorSetup();
   myservo.write(90);
  delay(3000);
}
 
void loop(){

 if(measureDistance.check() == 1){
      actualDistance = MeasureDistance();
      
      Serial.println(actualDistance);
//      delay(100);
 }
 
 if(sweepServo.check() == 1){
      servoSweep();
 }
 
 if(actualDistance <= 30){
            myservo.write(90);
            if(pos>=90){              
                  carBack(150,150);
               
                delay(600);  
                carTurnRight(150,150);     
               
                  delay(600);
                  
               }else{
                 carBack(150,150);

                   delay(600);
                   carTurnLeft(150,150);
                   delay(600);
               }
    }else{
                   carAdvance(150,150);
            
                   delay(100);
     }
//        carBack(150,150);
}
                                     
 
void SensorSetup(){ 
  pinMode(URTRIG,OUTPUT);                     // A low pull on pin COMP/TRIG
  digitalWrite(URTRIG,HIGH);                  // Set to HIGH 
  pinMode(URPWM, INPUT);                      // Sending Enable PWM mode command
  for(int i=0;i<4;i++){
      Serial.write(EnPwmCmd[i]);
   } 
}

 
int MeasureDistance(){  // a low pull on pin COMP/TRIG  triggering a sensor reading
    digitalWrite(URTRIG, LOW);
    digitalWrite(URTRIG, HIGH);               // reading Pin PWM will output pulses    
    unsigned long distance=pulseIn(URPWM,LOW);    
    if(distance==50000){              // the reading is invalid.
      Serial.print("Invalid");    
    }else{
      distance=distance/50;           // every 50us low level stands for 1cm
    }
    return distance;
}

void carStop(){                 //  Motor Stop
  digitalWrite(speedPin_M2,0); 
  digitalWrite(directionPin_M1,LOW);    
  digitalWrite(speedPin_M1,0);   
  digitalWrite(directionPin_M2,LOW);    
}   

void carTurnLeft(int leftSpeed,int rightSpeed){         //Turn Left
  analogWrite (speedPin_M2,leftSpeed);              //PWM Speed Control
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
} 

void carTurnRight(int leftSpeed,int rightSpeed){        //Turn Right
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);   
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}

void carBack(int leftSpeed,int rightSpeed){             //Move backward
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}
void carAdvance(int leftSpeed,int rightSpeed){          //Move forward  
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
}

void servoSweep(){
  if(sweepFlag){  
     if(pos>=60 && pos<=120){                   
        pos=pos+5;                                  // in steps of 1 degree 
        myservo.write(pos);                         // tell servo to go to position in variable 'pos' 
    }
      if(pos>119)  sweepFlag = false;                       // assign the variable again
  }
   else {                                       
      if(pos>=60 && pos<=120){    
        pos=pos-5;
        myservo.write(pos);
      }
      if(pos<61)  sweepFlag = true;
    }

}

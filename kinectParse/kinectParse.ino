/*Kinect parse for Servo control
 * 
 * Taken from Making things See
 * 
 * written by D. Godrick
 * 7/25/2017
 * 
 * 
 */

 #include<Servo.h>

#define humerusPin 9
#define radiusPin 10

 Servo humerus;
 Servo radius;




 int nextServo = 0;
 int servoAngles[] = {5,5};

 void setup(){

  Serial.begin(9600);
  humerus.attach(humerusPin);
  radius.attach(radiusPin);
  Serial.setTimeout(100);
 }

void loop(){


if (Serial.available()>0){//if data is available
  int angle = Serial.read();
  constrain(angle,10,165);
// Serial.println(angle);
  servoAngles[nextServo] = angle;
  nextServo++;
  if (nextServo > 1){
    nextServo = 0;
  }
//  Serial.print(servoAngles[0]);
//  Serial.print("\t");
//  Serial.println(servoAngles[1]);
  humerus.write(servoAngles[0]);
  radius.write(servoAngles[1]);
  }
}




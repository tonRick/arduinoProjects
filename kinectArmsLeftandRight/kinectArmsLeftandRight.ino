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

#define rightHumerusPin 9
#define rightRadiusPin 10
#define leftHumerusPin 3
#define lefttRadiusPin  5


 Servo rightHumerus;
 Servo rightRadius;
 Servo leftHumerus;
 Servo leftRadius;



 int nextServo = 0;
 int servoAngles[] = {5,5,5,5};

 void setup(){

  Serial.begin(115200);
  rightHumerus.attach(rightHumerusPin);
  rightRadius.attach(rightRadiusPin);
  leftHumerus.attach(leftHumerusPin);
  leftRadius.attach(lefttRadiusPin);

 // Serial.setTimeout(100);
 }

void loop(){


if (Serial.available()>0){//if data is available
  int angle = Serial.read();
  
  servoAngles[nextServo] = angle;
  nextServo++;
  if (nextServo > 3){
    nextServo = 0;
  }
//  Serial.print(servoAngles[0]);
//  Serial.print("\t");
//  Serial.println(servoAngles[1]);
  rightHumerus.write(servoAngles[0]);
  rightRadius.write(servoAngles[1]);
  leftHumerus.write(servoAngles[2]);
  leftRadius.write(servoAngles[3]);
  }
}




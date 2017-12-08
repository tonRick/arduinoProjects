  const int LM_sig = 3;  //PWM Pin Left Motor 
  const int RM_sig = 11; //PWM Pin Right Motor
  const int LMdir = 12;  //Direction Left Motor
  const int RMdir = 13;  //Direction Right Motor
  
  int LM_speed;                              //Variable for spped of Left Motor
  int RM_speed;                              //Variable for spped of Right Motor
  int Avg_speed = 35;                        //Average (Nominal) speed of the robot
  int IRL = 14;                                //Pin Sensor is attached to
  int IRR = 16;
  float LoopTime = 0.1000;                  //Time that the loop takes to run 
  float deltaTime = (LoopTime / 1000.00000); //Convert Loop time to seconds
  
void setup(){  
 Serial.begin(9600); //Sets up the Serial port
 pinMode(LM_sig,OUTPUT);
 pinMode(RM_sig,OUTPUT);
 pinMode(LMdir,OUTPUT);
 pinMode(RMdir,OUTPUT);
 pinMode(IRL,INPUT);
 pinMode(IRR,INPUT);
 digitalWrite(13,LOW); //Set direction to forward
 digitalWrite(12,LOW); //Set direction to forward
}

void loop(){

  //Reads in sensor values and maps it to the output range
  int lVal = map(analogRead(IRL), 0, 1023, 0, 255);
  int rVal = map(analogRead(IRR), 0, 1023, 0, 255);
  
  // if the left value is on the black, speed up the right wheel and
  //slow down the left wheel
  if (lVal > 200)
  {
     LM_speed = constrain(Avg_speed - 35, 0, 255);
     RM_speed = constrain(Avg_speed + 35, 0, 255);
    //Calculates the speed between 0 and 255 for each motor
    analogWrite(LM_sig, LM_speed); 
    analogWrite(RM_sig, RM_speed*.95);
  } 
  //check if the right value is on the black, if it is, speed left,slow right
  else if (rVal >200)
  {
     LM_speed = constrain(Avg_speed + 35, 0, 255);
     RM_speed = constrain(Avg_speed - 35, 0, 255);
    //Calculates the speed between 0 and 255 for each motor
    analogWrite(LM_sig, LM_speed); 
    analogWrite(RM_sig, RM_speed*.95);
  } 
  //if they both are on white, go straight
  else
  {
     LM_speed = constrain(Avg_speed, 0, 255);
     RM_speed = constrain(Avg_speed, 0, 255);
    //Calculates the speed between 0 and 255 for each motor
    analogWrite(LM_sig, LM_speed); 
    analogWrite(RM_sig, RM_speed*.95);
  }
  
  
  //For testing check output of sensor and  motor speeds
  
  Serial.print("    LSens ");
  Serial.print(IRL);
  Serial.print("    RSens ");
  Serial.print(IRR);
  Serial.print("    LM_speed ");
  Serial.print(LM_speed);
  Serial.print("    RM_speed ");
  Serial.println(RM_speed);
  //Prints the Sensor value and motor speed to the serial port. Used for tuning.

}
   
  

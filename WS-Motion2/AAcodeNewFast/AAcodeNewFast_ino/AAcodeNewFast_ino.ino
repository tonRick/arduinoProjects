  const int LM_sig = 3;  //PWM Pin Left Motor 
  const int RM_sig = 11; //PWM Pin Right Motor
  const int LMdir = 12;  //Direction Left Motor
  const int RMdir = 13;  //Direction Right Motor
  
  int LM_speed;                              //Variable for spped of Left Motor
  int RM_speed;                              //Variable for spped of Right Motor
  int Avg_speed = 30;                        //Average (Nominal) speed of the robot
  int IR = 15;                                //Pin Sensor is attached to
  float Kp = 0.25000;                        //Proportionality constant
  float Kd = 0.00015;                        //Derivative constant
  float Ki = 0.00000;                        //Integral constant
  float LoopTime = 0.1000;                  //Time that the loop takes to run 
  float deltaTime = (LoopTime / 1000.00000); //Convert Loop time to seconds
  float ErrOld = 0.00000;                    //Variable for previous error
  float ErrSum = 0.00000;                    //Variable for the sum of error over time
  float Err = 0.00000;                       //Variable for error
  float ErrP;                                //Variable for Proportional error
  float ErrD;                                //Variable for Derivative error
  float ErrI;                                //Variable for Integral error  
  int Command;                               //Variable for Command output
  int Desired = 180;                          //Sensor offset value for perfectly on the line. This is what we want to contol to
  int Actual;                                //Variable for Actual Sensor value
  
void setup(){  
 Serial.begin(9600); //Sets up the Serial port
 pinMode(LM_sig,OUTPUT);
 pinMode(RM_sig,OUTPUT);
 pinMode(LMdir,OUTPUT);
 pinMode(RMdir,OUTPUT);
 digitalWrite(13,LOW); //Set direction to forward
 digitalWrite(12,LOW); //Set direction to forward
}

void loop(){
  Actual = map(analogRead(IR), 0, 1023, 0, 255);
  //Reads in sensor value and re-maps it to the output range
    
  Err = Desired - Actual;
  //PID wants the error to be zero, so subtract the sensor value from the offset. This is how far away from the target we currently are
  ErrSum = ErrSum + Err;
  //Adding up error over time for use in Integral
  
  delay(LoopTime);
  //Delays the loop for the requested looptime
  
  ErrP = Kp * Err;
  
  ErrD = Kd * (Err - ErrOld) / deltaTime;
  
  ErrI = Ki * ErrSum * deltaTime;
  
  Command = ErrP + ErrD + ErrI;
  //Adds up the respective P, I & D errors to produce the total command output
       
  LM_speed = constrain(Avg_speed - Command, 0, 255);
  RM_speed = constrain(Avg_speed + Command, 0, 255);
  //Calculates the speed between 0 and 255 for each motor
  
  analogWrite(LM_sig, LM_speed); 
  analogWrite(RM_sig, RM_speed*.95);
  //Outputs the motor speeds
  
  
  ErrOld = Err;
  //Sets current error to what will be previous error for next loop. Used in derivative calculation
  
  Serial.print("    Actual ");
  Serial.print(Actual);
  Serial.print("    LM_speed ");
  Serial.print(LM_speed);
  Serial.print("    RM_speed ");
  Serial.println(RM_speed);
  //Prints the Sensor value and motor speed to the serial port. Used for tuning.

}
   
  

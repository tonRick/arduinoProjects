/* Code by Dan Godrick with help from Jared Wampler
 *  for PID control of robot
 */

//Robot Setup Variables
const int speedPinL = 3;                            //Pin Left Motor is attached to
const int speedPinR = 11;                            //Pin Right Motor is attahced to
const int dirPinL = 12;                     //direction pin left motor
const int dirPinR = 13;                     //direction pin right motor
int LM_speed;                              //Variable for speed of Left Motor
int RM_speed;                              //Variable for speed of Right Motor
  
//State variable - If the first data piece is a 0, go to joystick mode. If it is a 1, PID mod
int stateVar = 0; // default joystick mode

//Joystick Variables
int readVal1 = 50;
int readVal2 = 0;
int perL = 0;
int perR = 0;
int dirL = 0;
int dirR = 0;
  
//PID Variables. 
  int Avg_speed = 35;                        //Average (Nominal) speed of the robot
  int IR = 15;                                //Pin Sensor is attached to
  float Kp = 0.2500;                        //Proportionality constant
  float Kd = 0.015;                        //Derivative constant
  float Ki = 0.00000;                        //Integral constant
  float LoopTime = 1.0000;                  //Time that the loop takes to run 
  float deltaTime = (LoopTime / 1000.00000); //Convert Loop time to seconds
  float ErrOld = 0.00000;                    //Variable for previous error
  float ErrSum = 0.00000;                    //Variable for the sum of error over time
  float Err = 0.00000;                       //Variable for error
  float ErrP;                                //Variable for Proportional error
  float ErrD;                                //Variable for Derivative error
  float ErrI;                                //Variable for Integral error  
  int Command;                               //Variable for Command output
  int Desired = 185;                          //Sensor offset value for perfectly on the line. This is what we want to contol to
  int Actual;                                //Variable for Actual Sensor value
  
void setup(){  
 Serial.begin(115200); //Sets up the Serial port
 pinMode(speedPinL,OUTPUT);
 pinMode(speedPinR,OUTPUT);
 pinMode(dirPinL,OUTPUT);
 pinMode(dirPinR,OUTPUT);
 digitalWrite(dirPinL,LOW);//Sets direction
 digitalWrite(dirPinR,LOW);//Sets direction   
}

void loop(){
  getData(); //First get the data from the Bluetooth
  //If the first data piece is a 0, go to joystick mode. If it is a 1, PID mode
  if (stateVar == 1) {
    pidMode();  
  } else{
    joystickMode();
  }
  
  
}

void getData(){
  while (Serial.available()>0) //If there is information available
  {
    stateVar =  Serial.parseInt();
    readVal1 =  Serial.parseInt();
    readVal2 =  Serial.parseInt();
    if (Serial.read() == '\n') //newline sets values
    {
      Serial.print(stateVar);
      Serial.print(",");
      Serial.print(readVal1);
      Serial.print(",");
      Serial.print(readVal2);      
    }
      setDirection();
      setSpeeds();
  }
}

void joystickMode(){
}
 
void pidMode(){
  
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
  
  analogWrite(speedPinL, LM_speed); 
  analogWrite(speedPinR, RM_speed);
  //Outputs the motor speeds
  
  
  ErrOld = Err;
  //Sets current error to what will be previous error for next loop. Used in derivative calculation
  
//  Serial.print("    Actual ");
//  Serial.print(Actual);
//  Serial.print("    LM_speed ");
//  Serial.print(LM_speed);
//  Serial.print("    RM_speed ");
//  Serial.println(RM_speed);
//  //Prints the Sensor value and motor speed to the serial port. Used for tuning.
}

void setDirection(){
  if (readVal1 >= 0){
    digitalWrite(dirPinL,0); //Low is forward
  } else if (readVal1 < 0){
    digitalWrite(dirPinL,1); //1 is Reverse
  }
  if (readVal2 >= 0){
    digitalWrite(dirPinR,0); //Low is Forward
  }else if (readVal2 < 0){
    digitalWrite(dirPinR,1); //High is reverese
  }
}

void setSpeeds(){
  readVal1 = abs(readVal1);//only interested in magnitude 
  readVal2 = abs(readVal2);//only interested in magnitude 
  readVal1 = map(readVal1, 0,50,0,75); // map to make quicker
  readVal2 = map(readVal2, 0,50,0,75); // map to make quicker
  
  perL = readVal1;
  perR = readVal2;
  Serial.print('\t');
  Serial.print(perL);
  Serial.print(",");
  Serial.println(perR);
  analogWrite(speedPinL,perL);
  analogWrite(speedPinR,perR);
}


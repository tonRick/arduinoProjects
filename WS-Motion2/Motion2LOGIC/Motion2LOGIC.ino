/* Motion 2 Logic Exercise
 *  Written by Dan Godrick
 *  10/28/2015
 *  
 *  Uses QRD1114 and Sparkfun Motor Shield
 *  
 */
  
  int lSig = 3;                            //Pin Left Motor is attached to
  int rSig = 11;                            //Pin Right Motor is attahced to
  int lDirPin = 13;                          //Variable for LM direction
  int rDirPin = 12;                          //Variable for RM direction
  int LIR = 14;                              //Left sensor Pin 
  int RIR = 16;                              //Right sensor Pin 
  int leftRead = 0;                             //Left Read Intialize
  int rightRead = 0;                             //Right Read Initialize
  int sSpeed = 45;
    
void setup(){  
 Serial.begin(9600); //Sets up the Serial port
 pinMode(lSig,OUTPUT);
 pinMode(rSig,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 digitalWrite(13,LOW); //LOW is forward
 digitalWrite(12,LOW); //LOW is forward  
}

void loop(){
  leftRead = analogRead(LIR);
  rightRead = analogRead(RIR);
  Serial.print(leftRead);
  Serial.print(" ");
  Serial.println(rightRead);

  //analyze left first, clockwise travel
  if (leftRead > 700)
  {
    turnLeft();
  }else if (rightRead > 700) //Read from right sensor - if higher than 300, on line
  {
    turnRight();
  } else {
    goForward();
  }
}


void goForward()
{
  digitalWrite(lDirPin,LOW);
  digitalWrite(rDirPin,LOW);
  analogWrite(lSig,sSpeed);
  analogWrite(rSig,sSpeed);
  delay(5);
}

void turnLeft()
{
  digitalWrite(lDirPin,LOW);
  digitalWrite(rDirPin,HIGH);
  analogWrite(lSig,sSpeed);
  analogWrite(rSig,sSpeed);
  delay(5);
}

void turnRight()
{
  digitalWrite(lDirPin,HIGH);
  digitalWrite(rDirPin,LOW);
  analogWrite(lSig,sSpeed);
  analogWrite(rSig,sSpeed);
  delay(5);
}


  

   
  

#include <Wire.h>
  
int loopcount = 0;
int pennyboard = 2;
int UD = 0;
int LR = 0;

void setup() {
  // put your setup code here, to run once:
  
  // Serial port
  Serial.begin(9600);

  //i2c
  Wire.begin();

//SetPositionCount to zero//
////////////////////////////
  Wire.beginTransmission(pennyboard);
  byte SetPositionCount[] = {0x08,0x7D,0x00};
  Wire.write(SetPositionCount,3);
  Wire.endTransmission();
  
 Wire.beginTransmission(1); //talk to Pboard #2
  byte speed = 0x20;
  byte spin[] = {0x0C,0xC0,speed}; //spin at speed described by 3rd byte
  Wire.write(spin,3);
  Wire.endTransmission(); 
}

void loop() {
  // put your main code here, to run repeatedly:
 
  loopcount++;
  Serial.println(loopcount);
    
  

}

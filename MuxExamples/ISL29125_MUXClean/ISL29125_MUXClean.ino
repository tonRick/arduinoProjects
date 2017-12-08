/******************************************************************************

This sketch multiplexes the outputs of two RGB Sensors
The RGB sensors use I2C, but have the same address, so a multiplexer is necessary

The RGB sensors are ISL 29125, and there is a great deal of information put together by 
Jordan McConnell @ SparkFun Electronics
11 Apr 2014
https://github.com/sparkfun/ISL29125_Breakout

The code for the ISL 29125, simply pulls from the great library, which
allows the declaration of the SFE_ISL29125 object called as RGB_sensor. 

Then, the WIRE library is used to get I2C communication enabled. 

The hookup of the multiplexer allows the user to select the channels that they 
want

Distributed as-is; no warranty is given. 
******************************************************************************/

#include <Wire.h>
#include "SFE_ISL29125.h"

// Declare sensor object
SFE_ISL29125 RGB_sensor;

//Multiplexer pins
const int s0 = 11;
const int s1 = 10;
const int s2 = 9;
const int s3 = 8;

const int numSensor = 2; // number of RGb sensors 

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

// Define Multiplex output pins - sets all to output
  for (int ii = 8; ii < 12; ii++){
  pinMode(ii,OUTPUT);
}

//Initialize each RGB Sensor

for (int ii = 0 ; ii <= (numSensor - 1); ii++){ 
  
  readMux(ii); //define the channel on the multiplex
  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.print("Sensor: ");Serial.print(ii);
    Serial.println(" Initialization Successful\n\r");
    delay(100);
  }
 } 
}

// Read sensor values for each color and print them to serial monitor
void loop()
{
 for (int ii = 0 ; ii <= (numSensor - 1); ii++){ 
  Serial.print("Sensor "); Serial.print(ii);Serial.print(" Reading ");
  readMux(ii); //set sensor
  readRGB(); //Read from multiplexer
  
  }
  Serial.println();
  delay(500);
}

void readRGB(){
  // Read sensor values (16 bit integers)
  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();
  
  // Print out readings, change HEX to DEC if you prefer decimal output
  Serial.print("Red: "); Serial.print(red,DEC); Serial.print("\t");
  Serial.print("Green: "); Serial.print(green,DEC);Serial.print("\t");
  Serial.print("Blue: "); Serial.print(blue,DEC);Serial.print("\t");
  Serial.println();
  //delay(2000);
}

int readMux (int channel){

   int controlPin[] = {s0,s1,s2,s3}; //array of control pins

   int muxChannel[16][4] =
   {
    {0,0,0,0}, //channel0
    {1,0,0,0}, //channel1  
    {0,1,0,0}, //channel2  
    {1,1,0,0}, //channel3  
    {0,0,1,0}, //channel4  
    {1,0,1,0}, //channel5  
    {0,1,1,0}, //channel6  
    {1,1,1,0}, //channel7  
    {0,0,0,1}, //channel8  
    {1,0,0,1}, //channel9  
    {0,1,0,1}, //channel10  
    {1,1,0,1}, //channel11
    {0,0,1,1}, //channel12
    {1,0,1,1}, //channel13  
    {0,1,1,1}, //channel14 
    {1,1,1,1}, //channel15        
   };
   for(int jj = 0; jj <4; jj++){
    digitalWrite(controlPin[jj],muxChannel[channel][jj]); //row is channel, on/off defined by column
   }
   int aIn = analogRead(14);
   return aIn;
  
}





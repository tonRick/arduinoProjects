/******************************************************************************
ISL29125_basics.ino
Simple example for using the ISL29125 RGB sensor library.
Jordan McConnell @ SparkFun Electronics
11 Apr 2014
https://github.com/sparkfun/ISL29125_Breakout

This example declares an SFE_ISL29125 object called RGB_sensor. The 
object/sensor is initialized with a basic configuration so that it continuously
samples the light intensity of red, green and blue spectrums. These values are
read from the sensor every 2 seconds and printed to the Serial monitor.

Developed/Tested with:
Arduino Uno
Arduino IDE 1.0.5

Requires:
SFE_ISL29125_Library

This code is beerware.
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


void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

// Define Multiplex output pins - sets all to output
  for (int ii = 8; ii < 12; ii++){
  pinMode(ii,OUTPUT);
}

//Initialize each RGB Sensor

//Sensor 0 
  readMux(0); //define the channel 1 on the multiplex

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.print("Sensor 0 Initialization Successful\n\r");
  }

//Sensor 1 
  readMux(1); //define the channel 1 on the multiplex

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.println("Sensor 1 Initialization Successful\n\r");
  }
  
}

// Read sensor values for each color and print them to serial monitor
void loop()
{
  Serial.println("Sensor 0 Reading");
  readMux(0); //set sensor to 0
  readRGB(); //Read from multiplexer
  
  Serial.println("Sensor 1 Reading");
  readMux(1); //set sensor to 1 
  readRGB(); //Read from multiplexer

  delay(2000);
}

void readRGB(){
  // Read sensor values (16 bit integers)
  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();
  
  // Print out readings, change HEX to DEC if you prefer decimal output
  Serial.print("Red: "); Serial.println(red,DEC);
  Serial.print("Green: "); Serial.println(green,DEC);
  Serial.print("Blue: "); Serial.println(blue,DEC);
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





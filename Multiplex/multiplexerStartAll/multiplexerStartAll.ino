

/*Multiplexer Start Code
Daniel Godrick
November 20,2015

This code is to check the functionality of the CD74HC4067 breakout board
Walk 

Help was found on the Sparkfun website where it was purchased, and the bildr blog
The bildr really helped with the coding of the readMux Function!

Code for channel choice:
To simplify things, 1 is HIGH, 0 is LOW
0000 – 0
1000 – 1
0100 – 2
1100 – 3
0010 – 4
1010 – 5
0110 – 6
1110 – 7
0001 – 8
1001 – 9
0101 – 10
1101 – 11
0011 – 12
1011 – 13
0111 – 14
1111 – 15

*/

//First define output pins. These are used to choose the output from the multiplexer

const int s0 = 8;
const int s1 = 9;
const int s2 = 10;
const int s3 = 11;

void setup() {
// Define output pins - sets all to 0
for (int ii = 8; ii < 12; ii++){
  pinMode(ii,OUTPUT);
}

//Define input pin
pinMode(14,INPUT); // 14 is a0

Serial.begin(9600); //begin serial monitor

}

void loop() {

//Display all outputs in tab delineated form
for (int ii = 0; ii <16; ii++)
{
  Serial.print(readMux(ii));Serial.print("\t");//tab delimited output
}
Serial.println();
delay(500);
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


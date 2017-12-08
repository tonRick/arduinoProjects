

/*Multiplexer Start Code
Daniel Godrick
November 20,2015

This code is to check the functionality of the CD74HC4067 breakout board
Crawl! 

Help was found on the Sparkfun website where it was purchased, and the bildr blog

The digital logic is a little backward. But not too hard to understand.
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

  read1();//used to choose a read channel. 

  int aIN = analogRead(14);
  Serial.println(aIN);
  delay(1000);



}

void read1 (){
   
  digitalWrite(s0,1);
  digitalWrite(s1,0);
  digitalWrite(s2,0);
  digitalWrite(s3,1);
}


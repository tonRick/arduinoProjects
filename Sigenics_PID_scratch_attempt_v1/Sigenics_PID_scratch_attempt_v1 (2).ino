#include <Wire.h>
  
int loopcount = 0;
int pennyboard = 2;
int UD = 0;
int LR = 0;

void setup(void){
	
  // Serial port
  Serial.begin(9600);

  //i2c
  Wire.begin();
 
 //Scan//
/////////
//Wire.beginTransmission(pennyboard);
//byte Scan[] = {0x2C};
//Wire.write(Scan,1);
//Wire.endTransmission();
//
//int avail = Wire.available();
//Wire.requestFrom(pennyboard,avail);
//
//Serial.println(avail);
//
//int addresses[avail];
//
//while(Wire.available())
//{
//  for (int i=0; i < avail; i++){
//  addresses[i]=Wire.read(); //read bytes
//  }
//  
//}
//Serial.println(addresses);
  
//SetPositionCount to zero//
////////////////////////////
Wire.beginTransmission(pennyboard);
byte SetPositionCount[] = {0x08,0x7D,0x00};
Wire.write(SetPositionCount,3);
Wire.endTransmission();

//Enable PID Control//
/////////////////////
//Wire.beginTransmission(pennyboard);
//byte SetEnablePID[] = {0x80,0x80};
//Wire.write(SetEnablePID,2);
//Wire.endTransmission();
//
////Set Kp Parameter//
//////////////////////
//Wire.beginTransmission(pennyboard);
//byte SetKpParameter[] = {0x81,0x3d,0xcc,0xcc,0xcd}; //Kp = 0.1
////byte SetKpParameter[] = {0x81,0x3f,0x80,0x00,0x00}; //Kp = 1.0
//Wire.write(SetKpParameter,5);
//Wire.endTransmission();
//
////Set Ki Parameter//
//////////////////////
//Wire.beginTransmission(pennyboard);
//byte SetKiParameter[] = {0x82,0x00,0x00,0x00,0x00}; //Ki = 0.0
////byte SetKiParameter[] = {0x82,0x3f,0x00,0x00,0x00}; //Ki = 0.5
//Wire.write(SetKiParameter,5);
//Wire.endTransmission();
//
////Set Kd Parameter//
//////////////////////
//Wire.beginTransmission(pennyboard);
//byte SetKdParameter[] = {0x83,0x00,0x00,0x00,0x00}; //Kd = 0.0
////byte SetKiParameter[] = {0x82,0x3f,0x00,0x00,0x00}; //Kd = 0.5
//Wire.write(SetKdParameter,5);
//Wire.endTransmission();
//
//
}

void loop(){
  
loopcount++;
Serial.println(loopcount);

//Joystick Input//
//////////////////
//
//  UD = analogRead(A0);
//  LR = analogRead(A1);
//  Serial.print("UD = ");
//  Serial.print(UD, DEC);
//  Serial.print(", LR = ");
//  Serial.println(LR, DEC);   
//	
////Spin to check communication//
////////////////////////////////

Wire.beginTransmission(2); //talk to Pboard #2
byte speed = 0x00;
byte spin[] = {0x0C,0xC0,speed}; //spin at speed described by 3rd byte
Wire.write(spin,3);
Wire.endTransmission();

//Read Encoder//
////////////////
//word enc =  ReadEncoder(pennyboard);
//Serial.println(enc);
////delay(100);

////Set Target Position//
/////////////////////////
//Wire.beginTransmission(pennyboard);
//byte SetTargetPosition[] = {0x84,0x10,0x27};
//Wire.write(SetTargetPosition,3);
//Wire.endTransmission();


//Set Target Position with Joystick//
/////////////////////////////////////
//word set = map(UD,0,1023,0,65535); //map to encoder values
//Serial.println("word: ");
//Serial.println(set);
//byte set1 = highByte(set); //high byte
//byte set2 = lowByte(set); //low byte

//
//Wire.beginTransmission(pennyboard);
//byte SetTargetPosition[] = {0x84,set1,set2};
//Wire.write(SetTargetPosition,3);
//Wire.endTransmission();
delay(1000);
}


//Read Encoder Value Function//
//////////////////////////////

word ReadEncoder(int Pboard)
{
Wire.beginTransmission(Pboard);
byte send[] = {0x01,0x00};
Wire.write(send,2);
Wire.endTransmission();

Wire.requestFrom(Pboard,2);
int avail = Wire.available();
//Serial.println(avail);

byte enc[2];
word enc_word;

while(Wire.available()==2)
{
  enc[0]=Wire.read(); //read first byte
  //Serial.println(enc[0]);
  enc[1]=Wire.read(); //read second byte
  //Serial.println(enc[1]);
  enc_word = word(enc[1],enc[0]); //convert bytes to word
//  Serial.println(enc_word);
  
}

return enc_word;

}

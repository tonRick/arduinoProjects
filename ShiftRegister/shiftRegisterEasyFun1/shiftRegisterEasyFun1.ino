
int ser =8; //pins for data
int latch = 9; // latch pin
int clk = 10; //clock pin
int values[] = {  B10000000,
                  B01000000,
                  B00100000,
                  B00010000,
                  B00001000,
                  B00000100,
                  B00000010,
                  B00000001,
                  B00000000}; //Array of Values for individual lights
int ms = 25; //delay time 
int registers = 1; //how many registers are used  
                  
void setup(){
  //define pin outs
  pinMode(ser,OUTPUT); 
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  
  //Turn off all registers and wait for a second
  
  digitalWrite(latch,LOW);
  shiftOut(ser,clk,LSBFIRST,B11001111);
//  shiftOut(ser,clk,MSBFIRST,B00001000);
//  shiftOut(ser,clk,MSBFIRST,0xFD);
  
  digitalWrite(latch,HIGH);

}

void loop(){
}

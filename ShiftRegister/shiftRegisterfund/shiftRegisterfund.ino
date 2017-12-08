
int ser =10; //pins for data
int latch = 11; // latch pin
int clk = 12; //clock pin
int values[] = {  B10000000,
                  B01000000,
                  B00100000,
                  B00010000,
                  B00001000,
                  B00000100,
                  B00000010,
                  B00000001,
                  B00000000}; //Array of Values for individual lights
int ms =1000; //delay time 
int registers = 3; //how many registers are used
int direction = 1; //initial direction
                  
void setup(){
  //define pin outs
  pinMode(ser,OUTPUT); 
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  
  //Turn off all registers and wait for a second
  
  digitalWrite(latch,LOW);
  for (int ii=0; ii < registers; ii++){
  shiftOut(ser,clk,MSBFIRST,B11111111); // pattern to check registers
  }
  digitalWrite(latch,HIGH);
  delay(3000);
  //Serial.begin(9600);
}

void loop(){
  
//        digitalWrite(latch,LOW);
//        shiftOut(ser,clk,MSBFIRST,B00000001);//
//        shiftOut(ser,clk,MSBFIRST,B00000000);//
//        shiftOut(ser,clk,MSBFIRST,B00000000);//
//        digitalWrite(latch,HIGH);
       
}



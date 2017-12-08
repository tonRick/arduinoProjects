
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
int registers = 3; //how many registers are used  
                  
void setup(){
  //define pin outs
  pinMode(ser,OUTPUT); 
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  
  //Turn off all registers and wait for a second
  
  digitalWrite(latch,LOW);
  for (int ii=0; ii <3; ii++){
  shiftOut(ser,clk,MSBFIRST,B00011000);
  }
  digitalWrite(latch,HIGH);
  delay(3000);
  Serial.begin(9600);
}

void loop(){
  for (int ii = 23; ii >= 0; ii--){
    int chain = ii/8 + 1;
    int light  = ii % 8;
    /*Serial.print("Iteration: ");
    Serial.print(ii);
    Serial.print(" Chain number: ");
    Serial.print(chain);
    Serial.print(" Light number is: ");
    Serial.print(light);
    Serial.println();*/
    switch (chain){
      case 3:
        digitalWrite(latch,LOW);
        shiftOut(ser,clk,MSBFIRST,B00000000);//Third in Chain
        shiftOut(ser,clk,MSBFIRST,B00000000);
        shiftOut(ser,clk,MSBFIRST,values[light]);
        digitalWrite(latch,HIGH);
        delay(ms);
        break;
      case 2:
        digitalWrite(latch,LOW);
        shiftOut(ser,clk,MSBFIRST,B00000000);//Third in Chain
        shiftOut(ser,clk,MSBFIRST,values[light]);
        shiftOut(ser,clk,MSBFIRST,B00000000);
        digitalWrite(latch,HIGH);
        delay(ms);
        break;
       case 1:
        digitalWrite(latch,LOW);
        shiftOut(ser,clk,MSBFIRST,values[light]);//Third in Chain
        shiftOut(ser,clk,MSBFIRST,0);
        shiftOut(ser,clk,MSBFIRST,0);
        digitalWrite(latch,HIGH);
        delay(ms);
        break;       
  }
  }
}



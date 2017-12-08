
int ser =0; //pins for data
int latch = 1; // latch pin
int clk = 2; //clock pin
int values[] = {  B10000000,
                  B01000000,
                  B00100000,
                  B00010000,
                  B00001000,
                  B00000100,
                  B00000010,
                  B00000001,
                  B00000000}; //Array of Values for individual lights
int ms = 75; //delay time 
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
  shiftOut(ser,clk,MSBFIRST,B00111000); //random pattern to check registers
  }
  digitalWrite(latch,HIGH);
  delay(3000);
  //Serial.begin(9600);
}

void loop(){
  int totalLights = registers*8 - 1 ; //get total lights used in setup, index to 0 
  //if direction is 1 go right, else go left
  if (direction == 1){
    goLeft(totalLights);
    direction = -1;
    }
    else{
    goRight(totalLights);
    direction = 1;
    }
}
 
void goLeft(int lights){     
  for (int ii = lights; ii >= 0; ii--){
    int chain = ii/8 + 1;
    int light  = ii % 8;
    /*
    Serial.print("Iteration: ");
    Serial.print(ii);
    Serial.print(" Chain number: ");
    Serial.print(chain);
    Serial.print(" Light number is: ");
    Serial.print(bitLight);
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
void goRight(int lights){     
  for (int ii = 0; ii <= lights; ii++){
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


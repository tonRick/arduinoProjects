
//This code can be used to test a 3 chain shift register circuit
//The code can be used to demonstrate how shift registers can be 
//set with the "shift out" function


int ser = 10; //pins for data
int latch = 11; // latch pin
int clk = 12; //clock pin
int registers = 3;
                  
void setup(){
  //define pin outs
  pinMode(ser,OUTPUT); 
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  
  //Turn on all registers and wait for a second
  
  digitalWrite(latch,LOW); //enable data to be written
  for (int ii=0; ii < registers; ii++){
  shiftOut(ser,clk,MSBFIRST,B11111111); // pattern to check LEDS
  }
  digitalWrite(latch,HIGH);//send the data

  delay(1000);
  
//turn off all registers and wait for a second
  digitalWrite(latch,LOW); ////enable data to be written
  for (int ii=0; ii < registers; ii++){
  shiftOut(ser,clk,MSBFIRST,B00000000); // pattern to check LEDS
  }
  digitalWrite(latch,HIGH);//send the data
  delay(1000);
  
  
  //Serial.begin(9600);
}

void loop(){
 //Play with the bytes to see how to turn on specific LEDs
        digitalWrite(latch,LOW);
        shiftOut(ser,clk,MSBFIRST,B00000000);//
        shiftOut(ser,clk,MSBFIRST,B10000000);//
        shiftOut(ser,clk,MSBFIRST,B00000000);//
        digitalWrite(latch,HIGH);
       
}



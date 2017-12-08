
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
                  B00000000,}; //Array of Values for individual lights
int ms = 10; //delay time 
int numRegister = 3; //how many registers are used
int direction = 1; //initial direction
                  
void setup(){
  //define pin outs
  pinMode(ser,OUTPUT); 
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  
  //Turn off all registers and wait for a second
  
  digitalWrite(latch,LOW);
  for (int ii=0; ii < numRegister; ii++){
  shiftOut(ser,clk,MSBFIRST,B00011000); //random pattern to check registers
  }
  digitalWrite(latch,HIGH);
  delay(3000);
  Serial.begin(9600);
}

void loop(){
  int totalLights = numRegister*8 - 1 ; //get total lights used in setup, index to 0 
  goRight(totalLights, numRegister);
}
 
void goRight(int lights, int reg){     
  for (int ii = lights; ii >= 0; ii--) //for all of the lights in the chain
  {
    int chain = ii/8 + 1; //algorithm to determine the chain in question 
    int light  = ii % 8; //algorithm to determine the light in question
    
    
    /* uncomment to check algorithm with serial monitor
    Serial.print("Iteration: ");
    Serial.print(ii);
    Serial.print(" Chain number: ");
    Serial.print(chain);
    Serial.print(" Light number is: ");
    Serial.print(light);
    Serial.println();
    delay(1000);
    */
    digitalWrite(latch,LOW); //start the serial transfer by setting the latch low
    
    //turn all of the chains off AFTER for the chain in question 
    for(int kk=0; kk<chain; kk++){
          shiftOut(ser,clk,MSBFIRST,B00000000);
        }
    //on the chain in question, control the light in question
    shiftOut(ser,clk,MSBFIRST,values[light]);
    
    //turn all of the chains off BEFORE the chain in question
    for(int ll=chain; ll<reg; ll++){
          shiftOut(ser,clk,MSBFIRST,B00000000);
        }
    digitalWrite(latch,HIGH); //end the serial transfer
    delay(ms);//delay for a bit
  }
  
}
 


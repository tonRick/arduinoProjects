
//Button Lock code
//9/16/2016 

//Written by Dan Godrick - with motivation from Enrique

//This code can be used to create a lock with Arduino
//If you get the right sequence, lights light up
//If you get it wrong, the lights flash and unlight



//Define button pins 
const int but1 = 2;
const int but2 = 3;
const int but3 = 4;

//Define LED pins
const int LED1 = 9;
const int LED2 = 10;
const int LED3 = 11;

//Set previous button states 
int pre1 = 0;
int pre2 = 0;
int pre3 = 0;

//Define toggles - we use the buttons as pseudo switches
bool tg1 = 0;
bool tg2 = 0;
bool tg3 = 0;

//preToggle
bool preTg1 = 0;
bool preTg2 = 0;
bool preTg3 = 0;

//Last button tested - needed for logic
int lastButton = 0;

//Logic dictates that we need to count the button presses
int buttonCounter = 0;

//We want to flash, and then reset, so will need to count the flash
int flashCounter = 0;

//We will have 3 states, so need some logic to tell us when we are in state 1 or state 2
bool state1 = 0;
bool state2 = 0;
bool state3 = 0;

void setup() {
//  Serial.begin(9600); //used to debug
  
  pinMode(but1,INPUT_PULLUP);
  pinMode(but2,INPUT);
  pinMode(but3,INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

//Set all pins low 
  for(int ii = 9; ii<=13 ; ii++){
    digitalWrite(ii,LOW);
  }
}

void loop() {
  processButtons(); //first process whether a button is pressed/toggled
  logicTest(); //then test if they were pressed in the right order
//  Serial.print(buttonCounter);
//  Serial.print(" ");
//  Serial.println(lastButton);
}

void logicTest(){
  if(buttonCounter < 1){
    allOff();
  } else if((buttonCounter == 1) && (lastButton ==3)){ //First press 1. If true - go to state 1. If not FLASH! 
    analogWrite(LED3,30);
    state1 = 1;
  } else if ((buttonCounter == 2) && (lastButton == 3) && state1){//Next press 2. If true go to state 2, If not FLASH!
    digitalWrite(LED3,HIGH);
    state2 = 1;
  } else if ((buttonCounter == 3) && (lastButton == 1) && state2){//Next Press 3. If true light them all up... If not. FlasH! 
    digitalWrite(LED1,HIGH);
    digitalWrite(LED3,HIGH);
    state3 = 1;
  } else if ((buttonCounter == 4) && (lastButton == 2) && state3){//Next Press 3. If true light them all up... If not. FlasH!
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);   
  } else if (flashCounter == 0){ //Set flash counter so we just flash 1 time. 
    flash();
    flashCounter = 1;
  } else{ //After flashing, set all LED off, and then reset
    allOff();
    flashCounter = 0;
    buttonCounter = 0;
  }
}

//Sets all LED to off. Used for reset
void allOff(){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
}

//quick function to process whether button is pressed
void processButtons(){
  processBut1();
  processBut2();
  processBut3();
}

//Function to increment a counter if any button is pressed, and determine which 
//button was pressed last
void buttonPressed(){
  if ((tg1 != preTg1) || (tg2 != preTg2) || (tg3 != preTg3) ){
    buttonCounter++;
  } 
  if (tg1 != preTg1){
    lastButton = 1;
  } else if(tg2 != preTg2){
    lastButton = 2;
  } else if (tg3 != preTg3){
    lastButton = 3;
  }
  
}

//Function to tell if button 1 was pressed
void processBut1(){
  int read1 = digitalRead(but1);
  delay(10); //wait a touch for bouncing
  read1 = !read1;
 
  if((read1 == 1) && (pre1 == 0)){
    tg1 = !tg1;
  }
  pre1 = read1;
  buttonPressed();
  preTg1 = tg1;
}


//Function to tell if button 2 was pressed
void processBut2(){
  int read2 = digitalRead(but2);
  delay(10); //wait a touch for bouncing
  if((read2 == 1) && (pre2 == 0)){
    tg2 = !tg2;
  }
  pre2 = read2;
  buttonPressed();
  preTg2 = tg2;
}

//Function to tell if button 3 was pressed
void processBut3(){
  int read3 = digitalRead(but3);
  delay(10); //wait a touch for bouncing
  read3 = !read3;
//  Serial.println(read3);
  if((read3 == 1) && (pre3 == 0)){
    tg3 = !tg3;
  }
  pre3 = read3;
  buttonPressed();
  preTg3 = tg3;
}


void flash(){
  for (int ii = 0; ii < 40; ii++){
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    delay(15);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    delay(15);
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    delay(15);
     digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    delay(15);
  }
}



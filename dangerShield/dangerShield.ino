/*
 * Danger Shield Example Sketch
 * Copyright (c) 2010 SparkFun Electronics.  All right reserved.
 * Written by Chris Taylor
 *
 * This code was written to demonstrate the Danger Shield from SparkFun Electronics
 * 
 * This code will test all of the devices on the Danger Shield one at a time. 
 * Press button 1 (D10) to cycle through the different tests. View their output on 
 * a terminal running at 9600 baud. 
 *
 * http://www.sparkfun.com

* The code was modified to include the use of functions and to in
corporate a knock sensor instead of the capacitance sensor


 */


// Shift register bit values to display 0-9 on the seven-segment display
const byte ledCharSet[12] = {

  B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01101111,B11111111,B01111001
};

// Global variables
float val = 0;
int state = 0;
int x = 0;
int i = 0;
int prev_time = 0;
int delay_time = 500;

// Pin definitions
#define SLIDER1  16
#define SLIDER2  15
#define SLIDER3  14

#define KNOCK    19

#define BUTTON1  10
#define BUTTON2  11
#define BUTTON3  12

#define LED1  5
#define LED2  6

#define BUZZER   3

#define TEMP  4

#define LIGHT  17

#define LATCH 7
#define CLOCK 8
#define DATA 4

// State machine values
#define SLIDER_TEST 7
#define BUZZER_TEST 2
#define KNOCK_TEST  3
#define TEMP_TEST  4
#define LIGHT_TEST 5
#define BUTTON_TEST 6
#define SEVENSEG_TEST 1



void setup()
{
  Serial.begin(9600);
  
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(BUTTON3,INPUT);
  
  digitalWrite(BUTTON1,HIGH);//Pull up activator
  digitalWrite(BUTTON2,HIGH);
  digitalWrite(BUTTON3,HIGH);
  
  
  pinMode(BUZZER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA,OUTPUT);
  
  

  Serial.println("Danger Shield Component Test");  
  Serial.println("Press Button 1 to begin.");  
}

void loop()
{
  
  
  if(!(digitalRead(BUTTON1))) // Change state
  {
    delay(50); // Debounce
    state++;
    if(state > 7){ 
      state = 1; 
    }
    while(!(digitalRead(BUTTON1)));
  }

  if(state == SLIDER_TEST) // Displays values of sliders
  {
    sliderTest();
  }

  if(state == BUZZER_TEST) // Activates buzzer
  {
    tone(BUZZER,300);
    
//    for(int x = 0; x < 100; x++)
//    {
//      digitalWrite(BUZZER, HIGH);
//      delay(1);
//      digitalWrite(BUZZER, LOW);
//      delay(1);
//    }
//    
  }

  if(state == KNOCK_TEST) // Tests knock pad
  {
    noTone(BUZZER);
    displayVal(0);
    int knockVal = analogRead(KNOCK); 
    if(knockVal > 1)
      {
        Serial.println("Knock");
        displayVal(11);
        flash();
        } else displayVal(0); 
   }

  if(state == TEMP_TEST) // Displays temp sensor values
  {
    val = analogRead(TEMP) * 0.004882814;
    float degreesC = (val - 0.5) * 100.0-7;
    float degreesF = (degreesC)*9/5 + 32;
    Serial.print("Temp: ");
    Serial.println(degreesF);
    int dispTemp = degreesF/10;
    displayVal(dispTemp);
  }

  if(state == LIGHT_TEST) // Displays light sensor values
  {
    val = analogRead(LIGHT);
    Serial.print("Light: ");
    Serial.println(val);
    int dispLight = val/100;
    displayVal(dispLight);
    
  }

  if(state == BUTTON_TEST) // Toggles LED's depending on Buttons 2 and 3
  {  
    Serial.println("Button 2 & 3 Test");
    displayVal(10);
    if(digitalRead(BUTTON3))
    {
      digitalWrite(LED1,HIGH);
    }
    else
    {
      digitalWrite(LED1,LOW);
      displayVal(3);
    }
    if(digitalRead(BUTTON2))
    {
      digitalWrite(LED2,HIGH);
    }
    else
    {
      digitalWrite(LED2,LOW);
      displayVal(2);
    }
  }

  if(state == SEVENSEG_TEST) // Cycles through 0-9 on seven-segment - B is 8.
  {
    i = 0;
    
    Serial.println("Seven segment display test");
    while(digitalRead(BUTTON1))
    {
      int currTime = millis();
      if (currTime - prev_time > delay_time)  
        {
        digitalWrite(LATCH,LOW);
        shiftOut(DATA,CLOCK,MSBFIRST,~(ledCharSet[i]));
        digitalWrite(LATCH,HIGH);
        i++;
        if(i==12){
          i = 0;
        }
        prev_time = currTime;
        }
      
    }
  }
}

void flash()
{
  for (int ii = 0; ii < 10; ii ++)
  { 
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    tone(BUZZER,1000);
    delay(500/10);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    tone(BUZZER,500);
    delay(500/10);
  }
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  noTone(BUZZER);
}

void sliderTest()
{
    Serial.print("Sliders: ");
    int val1 = 1023 - analogRead(SLIDER1);
    Serial.print("  ");
    Serial.print(val1);
    int val2 = 1023 - analogRead(SLIDER2);
    Serial.print("  ");
    Serial.print(val2);
    int val3 = 1023 - analogRead(SLIDER3);
    Serial.print(" ");
    Serial.println(val3);
    delay(30);
    sliderCompare(val1, val2, val3);
}

void sliderCompare(int s1, int s2,int s3){
  if (s1 >= s2){
    if (s1 >= s3)
       {
        digitalWrite(LATCH,LOW);
        shiftOut(DATA,CLOCK,MSBFIRST,~(ledCharSet[1]));
        digitalWrite(LATCH,HIGH);
       } else {
        digitalWrite(LATCH,LOW);
        shiftOut(DATA,CLOCK,MSBFIRST,~(ledCharSet[3]));
        digitalWrite(LATCH,HIGH);
   }}else
   { 
     if (s2 >= s3) {
        digitalWrite(LATCH,LOW);
        shiftOut(DATA,CLOCK,MSBFIRST,~(ledCharSet[2]));
        digitalWrite(LATCH,HIGH);
      }else 
        {
          digitalWrite(LATCH,LOW);
          shiftOut(DATA,CLOCK,MSBFIRST,~((ledCharSet[3])));
          digitalWrite(LATCH,HIGH);
    }
   }

  }
  
void displayVal (int dispVal)
   {
          digitalWrite(LATCH,LOW);
          shiftOut(DATA,CLOCK,MSBFIRST,~((ledCharSet[dispVal])));
          digitalWrite(LATCH,HIGH);
    }
  

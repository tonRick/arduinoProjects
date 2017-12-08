

#include <Servo.h>

Servo finger;

int value = 0;
int initValue = 0;
const int arraySize = 20;
static int array1[arraySize];
int count = 0; // count for array position
float sum = 0;
int average;


int movingAverage(int v){
  //first check to make sure that we haven't reached the end of the array
  if (count >= arraySize){
    count = 0;
  }
  array1[count] = v; //set the value in place 
  count++; //increment count
    
  for (int jj = 0; jj < arraySize; jj++){
    sum = sum + array1[jj];
  }

//Serial.print("\t");
//Serial.print(sum);
//Serial.print("\t");
//Serial.println(arraySize);
int avg = sum/arraySize;
sum = 0;//reset sum

return avg;



}

void displayArray(){// Display everything 
for(int ii =  0; ii <= 9;ii++){
  Serial.print(array1[ii]);
  Serial.print(" ");
  }
Serial.println();
}

void setup() {
pinMode(13,OUTPUT);
finger.attach(9);
finger.write(10);
delay(1500);
Serial.begin (9600);
pinMode(A0,INPUT);
initValue = analogRead(A0);
//initialize array to 1s
for(int ii =  0; ii<arraySize ;ii++){
  array1[ii] = initValue;
  Serial.print(array1[ii]);
  Serial.print(" ");
}

Serial.println("\n Ready for Data");

digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
delay(100);
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
delay(100);
}

void loop() {

  value = analogRead(A0);
  average = movingAverage(value);
  average = constrain(average,initValue,initValue+100);
  Serial.print(average);
  Serial.print(" ");
  int angle = map(average,initValue,initValue+100,10,165);
  Serial.println(angle);
  finger.write(angle);
  
}




//

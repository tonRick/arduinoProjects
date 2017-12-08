
int value = 0;
const int arraySize = 10;
static int array1[arraySize];
int count = 0; // count for array position
float sum = 0;
int average;




void setup() {

Serial.begin (9600);
Serial.setTimeout(10);
//initialize array to 1s
for(int ii =  0; ii<arraySize ;ii++){
  array1[ii] = 0;
  Serial.print(array1[ii]);
  Serial.print(" ");
}
Serial.println("\n Ready for Data");

}

void loop() {
if (Serial.available()>0){
  value = Serial.parseInt();
  average = movingAverage(value);
  displayArray();
  Serial.println(average);
  }
}

void displayArray(){// Display everything 
for(int ii =  0; ii <= 9;ii++){
  Serial.print(array1[ii]);
  Serial.print(" ");
  }
Serial.println();
}

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

Serial.print("\t");
Serial.print(sum);
Serial.print("\t");
Serial.println(arraySize);
int avg = sum/arraySize;
sum = 0;//reset sum
return avg;


}
//

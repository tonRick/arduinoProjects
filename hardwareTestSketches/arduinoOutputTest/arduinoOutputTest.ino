
/*This program is used to test the Arduino outputs to make sure 
that the pin outputs are functioning correctly
*/
int count; 

void setup(){
  pinMode (1,OUTPUT);
  pinMode (2,OUTPUT);
  pinMode (3,OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT);
  pinMode (6,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (13,OUTPUT);
}

void loop(){
  count = 0;
  for (count =0; count <14; count++){
  digitalWrite(count,HIGH);//turn the pin on
  delay(5);//set delay in ms
  digitalWrite(count,LOW);//turn the pin off
  delay(5); //set the delay in ms
  }
  
}

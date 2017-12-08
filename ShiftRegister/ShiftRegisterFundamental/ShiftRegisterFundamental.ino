

//This code can be used how the Shift register receives information and 
//sends it down the chain. 

//Define pins
int serData = 10;
int serLatch = 11;
int serClk = 12;

void setup() {

//Set pins to outputs
  pinMode(serData,OUTPUT);
  pinMode(serClk,OUTPUT);
  pinMode(serLatch,OUTPUT);

Serial.begin(9600);

}

void loop() {

//If the user inputs a 1 in the Serial Monitor, send a High signal
//else if the user inputs a 0, send a LOW signal. 


if (Serial.available()>0){
  int ii = Serial.read();
  if (ii == 49){
    digitalWrite(serLatch,LOW); //data can now be written
    digitalWrite(serData,HIGH);  //change this from high to low and see how the shift reg work!
    pulse(); //this is how the shift register knows there is data
    pulse();
    digitalWrite(serLatch,HIGH);//send the data and close the latch  
  }
  else if (ii == 48){
    digitalWrite(serLatch,LOW); //data can now be written
    digitalWrite(serData,LOW);  //change this from high to low and see how the shift reg work!
    pulse(); //this is how the shift register knows there is data
    digitalWrite(serLatch,HIGH);//send the data and close the latch  
  }else{}

}

}

void pulse(){
    digitalWrite(serClk,HIGH);
    digitalWrite(serClk,LOW);
    delay(1);
}


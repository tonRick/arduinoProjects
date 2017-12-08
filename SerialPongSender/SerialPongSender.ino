
//Sensor Reader to play Monski Pong
//From Making things talk

//Dan Godrick


//Setup button and default values. 
const int leftFlex = 14;
const int rightFlex = 15;
const int resetButton  = 2;
const int serveButton = 3;

int leftValue = 0;
int rightValue = 0;
int reset = 0;
int serve = 0;

void setup() {
 Serial.begin(115200);
 pinMode(resetButton, INPUT);
 pinMode(serveButton, INPUT);
 digitalWrite(resetButton,LOW);
 digitalWrite(serveButton,LOW);
// while(Serial.available() <=0){
//  Serial.println("hello");
// }
}

void loop(){
//  if (Serial.available() > 0){
    int inByte = Serial.read();
    
    leftValue = analogRead(leftFlex);
    rightValue = analogRead(rightFlex);
    reset = digitalRead(resetButton);
    serve = digitalRead(serveButton);

    Serial.print(leftValue);
    Serial.print(",");
  
    Serial.print(rightValue);
    Serial.print(",");
  
    Serial.print(reset);
    Serial.print(",");
  
    Serial.println(serve);
//  }
}


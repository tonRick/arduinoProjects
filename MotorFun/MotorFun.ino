
int potPin = 0;
int en = 3;
int pin1 = 7;
int pin2 = 8;

void setup(){
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
  brake();
}
void loop(){
  int pinVal = analogRead(potPin);
  
  if(pinVal >= 563){
    int cont = map(pinVal,562,1023,100,255);
    forward(cont);
  }else if (pinVal < 462){
    int cont = map(pinVal,461,0,100,255);
    reverse(cont);
  }else{
  brake();
  }
  delay(50);
}

void forward(int value){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  analogWrite(en,200);
  Serial.print("The Value is: ");
  Serial.println(value);
}

void reverse(int value){
    digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  analogWrite(en,200);
  Serial.print("The Value is: ");
  Serial.println(value);
}

void brake(){
  digitalWrite(en,LOW);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(en,HIGH);
}

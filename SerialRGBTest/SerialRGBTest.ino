
int red = 10;
int green = 10;
int blue = 9;

int currentPin = 13;
int brightness = 0;

void setup() {
 Serial.begin(9600);
 for (int ii = 9; ii<12; ii++){
  pinMode(ii,OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0){
  int input = Serial.read();
  Serial.write(input);
  
   if ((input == 'r') || (input == 'R')){
    currentPin = red;
   }
   if ((input == 'g') || (input == 'G')){
      currentPin = green;
   }
   if ((input == 'b') || (input == 'B')){
      currentPin = blue;
    }
   if ((input >= '0') && (input <= '9')){
    brightness = map(input,'0','9',0,128);
    analogWrite(currentPin, brightness);
    Serial.println(brightness);
    
   }
   

  
 }
}

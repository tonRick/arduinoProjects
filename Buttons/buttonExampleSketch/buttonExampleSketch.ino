
//ButtonExampleSketch
//Daniel Godrick
//created: 9/14/2016


//this sketch is used to show how pull up pull down, and internal pull up resistors work with 
//Arduino


//define pins

#define greenBut  2
#define redBut  3
#define blueBut  4
#define greenLED  10
#define redLED  11
#define blueLED  12

void setup() {
 pinMode(greenBut,INPUT_PULLUP); // activates the internal pullup resistor
 pinMode(redBut,INPUT);
 pinMode(blueBut,INPUT);
 pinMode(blueLED,OUTPUT);
 pinMode(redLED,OUTPUT);
 pinMode(greenLED,OUTPUT);
 //Serial.begin(9600); //for development

}

void loop() {
  //get readings
  int but1 = digitalRead(greenBut);
  int but2 = digitalRead(redBut);
  int but3 = digitalRead(blueBut);

  // buttons attached to pullup resistors have inverse logic. Invert the inverse!
  but1 = !but1;
  but3 = !but3;

  //Turn lights on if the button is pressed. 
  if(but1 == 1){
    digitalWrite(greenLED,1);
  } else{
    digitalWrite(greenLED,0);
  } 
  if(but2 == 1){
    digitalWrite(redLED,1);
  } else{
    digitalWrite(redLED,0);
  } 
  if(but3 == 1){
    digitalWrite(blueLED,1);
  } else{
    digitalWrite(blueLED,0);
  }   
  //Slow the code just a touch
  delay(25);
}

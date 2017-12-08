/*Code for Easy Button Datalogger
 * 
 * Uses an timer debounced Easy button to count help
 * 10 taps sends a signal to a processing sketch
 * 
 * Dan Godrick
 * 10/14/2016
 */

int state = 1;// Button state is default 1 - switches on zero
int prevState = 1; // used to check only when button is pressed
int counter  = 0;
unsigned long startTime = 0; // start Timer for sending
int sendCounter = 0; //counter for sending
const int debounceTime = 5; //5 ms between readings 
const int sendTime = 2000; //Time for presses to send the counter to the Serial monitor 
const int numberPresses = 5; //number of presses in 2 seconds to send the data


void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT); //Uses pin 2 in case I wanted to switch to interrupts

}

void loop() {
  readButtonState();
  delay(debounceTime);
}

void readButtonState(){
  state = digitalRead(2);
  //if the button changed from high to low, it was pressed
  if ((prevState == 1) && (state == 0))
  {
    
    counter++;
    checkSend();
   Serial.print(counter);
   Serial.print(",");
   Serial.print(startTime);
   Serial.print("\t");
   Serial.println(sendCounter);
   
  }
  prevState = state;
}

void checkSend()
{
  if (sendCounter == 0){
    startTime = millis();
  }
  sendCounter++;
  if(millis() <= (startTime +sendTime)){
    if(sendCounter >= numberPresses){
    Serial.print("sendIt! ");
    Serial.print(counter - sendCounter);
    Serial.println();
    sendCounter = 0;
    delay(1000); //correct for extra presses during send
    counter = 0; // if we send data, then the counter needs to index to 0
    
    }
  }else if (millis() > (startTime + sendTime)){
    sendCounter = 0;
  }
  
}


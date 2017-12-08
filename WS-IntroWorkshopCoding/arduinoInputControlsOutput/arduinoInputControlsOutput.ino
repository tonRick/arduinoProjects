/* Interactive LED Project
 Example code for ENG1400 Interactive LED
 
 Code modified by: D. Godrick
 Using example from B. Huang at SparkFun
 Date: 08/22/14
 
 */
 
// The next three lines declare variables that we can use later in the code
// in place of the actual numbers.

int LED = 12; //Careful! 
int sensorPin = A0;
int potLevel = 0; //What is this? 

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);  // this line sets up a serial com interface
  // to communicate back to your PC
}                       

void loop()
{
  // this code repeats over and over. 
   potLevel = analogRead(sensorPin);  // reads in the level of the sensor. 
                                      // analogRead will return a value between 0 and 1023 

  Serial.print("Sensor value =");    // prints a string to read to Serial comm
  Serial.print(potLevel);            // prints the variable level to Serial 
  Serial.println();                  // prints a CRLF
  // this part of the code specifies the delay time based on the potLevel
  digitalWrite(LED, HIGH);
  delay(potLevel);
  digitalWrite(LED, LOW);
  delay(potLevel);

}


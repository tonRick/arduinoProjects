
/*Sketch to show the fundamentals of Serial

If there is no data, -1 is returned

Values are in ascii

*/

void setup(){
  Serial.begin(9600);
}

void loop(){
  int value = random(599);//Serial.read();
  //Serial.println(value);
  Serial.write(lowByte(value));
  Serial.write(highByte(value));
  //Serial.println();
  delay(1000);
}

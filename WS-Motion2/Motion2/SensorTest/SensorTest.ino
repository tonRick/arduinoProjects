
int left = 14;
int mid = 15;
int right = 16;


void setup()
{
  Serial.begin(9600);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(mid,INPUT);
  Serial.println("Left  Right  Mid");
}

void loop(){
  int vL = analogRead(left);
  int vM = analogRead(mid); 
  int vR = analogRead(right);
 
  
  Serial.print(vL);
  Serial.print("   ");
  Serial.print(vM);
  Serial.print("   ");
  Serial.println(vR);
  
  delay(100);
  
}

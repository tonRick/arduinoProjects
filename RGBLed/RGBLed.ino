int dTime  =100;
int state = 1;

void setup() 
{
  for(int ii = 0; ii<14; ii++)
  {
    pinMode(ii,OUTPUT);
  }

}

void loop() 
{

switch (state){
  default:
    trans(3,5);
    state = 2;
    break;
  
  case 1://transition from red to green
    trans(3,5);
    state = 2;
    break;
  
  case 2: 
   trans(5,9);
   state = 3;
   break;
  
  case  3: 
  trans(9,3);
   state = 1;
    break;
    
}
}

void trans(int pin1, int pin2){
   for (int ii = 0; ii < 255; ii++){
    analogWrite(pin1,255-ii);
    analogWrite(pin2,ii);
    delay(dTime);
   }
}


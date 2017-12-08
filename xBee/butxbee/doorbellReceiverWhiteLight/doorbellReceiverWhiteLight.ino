
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

//set the intitial state to be dull red
int redVal = 23;
int greenVal = 0;
int blueVal = 0;

const int numFields = 2; //sets the field number
int fieldIndex = 0;
int values[numFields];


void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop()
{
 getData();
}

void getData()
{
   if (Serial.available() > 0)
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <='9')
    {//if digit, put it in an array
     if (fieldIndex < numFields)
     { 
       values[fieldIndex] = (values[fieldIndex]*10) + (ch - '0');
     }
    }else if (ch == ',')
    {
      fieldIndex = fieldIndex++;
    }else //if not a digit or comma, end collection
    {
      if (values[0] > 0)
       {
         int redVal = constrain(values[1],0,255);
         int greenVal = constrain(values[1],0,255);
         int blueVal = constrain(values[1],0,255);
         analogWrite(redPin,redVal);
         analogWrite(greenPin,greenVal);
         analogWrite(bluePin,blueVal);
         Serial.print(values[0]);
         Serial.print(",");
         Serial.println(redVal);                
       }else
       {
         analogWrite(redPin,0);
         analogWrite(greenPin,0);
         analogWrite(bluePin,0);
         Serial.print(values[0]);
       }
      //reset 
     for (int ii = 0; ii < min(numFields,fieldIndex+1);ii++)
      { 
       values[ii] = 0;
       Serial.print(values[ii]);
       
       }
       fieldIndex = 0 ;
     }
  }
}
  
    
  

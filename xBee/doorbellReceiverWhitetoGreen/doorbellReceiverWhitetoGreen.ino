
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

//set the intitial state to be white
const int brightness = 200;
int redVal = brightness;
int greenVal = brightness;
int blueVal = brightness;

const int numFields = 2; //sets the field number
int fieldIndex = 0;
int values[numFields];
int on;

void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop()
{
 
  on = getData();
 Serial.println(on);
 delay(250);
}

int getData()
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
         int redVal = values[1];
         int greenVal = brightness;
         int blueVal = brightness-constrain(values[1],0,brightness);
         analogWrite(redPin,redVal);
         analogWrite(greenPin,greenVal);
         analogWrite(bluePin,blueVal);
         Serial.print(values[0]);
         Serial.print(",");
         Serial.println(redVal); 
         return redVal;         
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
  
    
  

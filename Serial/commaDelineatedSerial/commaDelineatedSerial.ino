
const int numFields = 3; //sets the field number
int fieldIndex = 0;
int values[numFields];


void setup(){
  Serial.begin(9600);
}

void loop()
{
  getdata();
}

void getdata()
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
       for (int ii = 0; ii < min(numFields,fieldIndex+1);ii++)
       { 
         Serial.println(values[ii]);
         values[ii] = 0;
       }
       fieldIndex = 0 ;
     }
  }
}
    
    
  

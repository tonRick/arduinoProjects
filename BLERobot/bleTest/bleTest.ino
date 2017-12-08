int led = 13;         
char rcv_buf[10];     // Receive command arrays.
void setup() 
{                
  pinMode(led, OUTPUT);    
  Serial.begin(115200); 
  digitalWrite(led,HIGH);  
}
 
void loop() 
{ 
  int data_len=0;           
  while(1)
  {
    while(Serial.available())                 
    {
       rcv_buf[(data_len++)%10] =Serial.read();       
    }
    if(rcv_buf[data_len-2]== '\r' && rcv_buf[data_len-1]=='\n')      // Stop reading the serial once getting the ending command.
       break;
  }
  if ((data_len==4)&&(!strncmp(rcv_buf,"ON",2)))      // Open the light L when the command is "ON".
  {
       digitalWrite(led, HIGH);                       // Set D13 pin as high and openg the light L
       Serial.println("LIHGT ON");                      
  }else if((data_len==5)&&(!strncmp(rcv_buf,"OFF",3)))   // Close the light L when the command is "OFF".
  {
       digitalWrite(led, LOW);                      // Set D13 pin as low and  the light L
       Serial.println("LIHGT OFF");              
  }
}

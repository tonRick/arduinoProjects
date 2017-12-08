int ii;
int jj;

void setup(){
  ii=0;
  for (ii==0; ii<=13; ii++){
    pinMode(ii,OUTPUT);
  }
}

void loop(){
  jj=0;
  for (jj==0; jj<=13; jj++){
    digitalWrite(jj,HIGH);
  }
  delay (1);
  jj=0;
  for (jj==0; jj<=13; jj++){
    digitalWrite(jj,LOW);
  }
  delay(20);
}


//Making Things Talk
//Basic Internet Sketch

//Dan Godrick
//June 30, 2016


#include<SPI.h>
#include<Ethernet.h>

EthernetServer server(80);

byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0x40, 0xBB};
IPAddress gateway(172,21,76,1);
IPAddress subnet(255,255,254,0);
IPAddress ip(172,21,77,245);

void setup() {  
  
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.begin(9600);
  pinMode(14,INPUT);
}

void loop() {
  EthernetClient client = server.available();
  if(client){
    Serial.println("Client OK");
    int lineLength = 0;
    
    while(client.connected()){
      if(client.available()){
        char thisChar = client.read();
        Serial.write(thisChar);
        if (thisChar == '\n' && lineLength <1){
          makeResponse(client);
          break;
        }
        if (thisChar == '\n' || thisChar == '\r'){
          lineLength == 0;
        }
        else{
          lineLength++;
        }
        
      }
    }
    delay(1);
    client.stop();
  }
}

void makeResponse(EthernetClient thisClient){
  thisClient.print("HTTP/1.1 200 OK\n");
  thisClient.print("Content-Type: text/html\n\n");
  thisClient.print("Hello Arduino </head><body>\n");
  thisClient.println("</body></html>\n");
  
}
     

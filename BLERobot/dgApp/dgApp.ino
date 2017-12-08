/*********************************************************************
 * DFMobile GoBLE_APP
 *********************************************************************
 * This example is aimed to control DFMobile basic motion by APP GoBle
 * Created 2015-3-12
 * By Gavin
 * 
 * Button ID:
 * SWITCH_UP      -- 1
 * SWITCH_RIGHT   -- 2
 * SWITCH_DOWN    -- 3
 * SWITCH_LEFT    -- 4
 * SWITCH_SELECT  -- 5
 * SWITCH_START   -- 6
 ********************************************************************/
#include "DFMobile.h"
DFMobile Robot (4,5,7,6);
#include "Metro.h"
// Speed is modified by mapping vlaue of GamePad Stick
int LeftWheelSpeed;
int RightWheelSpeed;

//GoBle configuration library, help user to identify control button and stick on Gamepad
#include "GoBLE.h"
int joystickX, joystickY;
int buttonState[6];

int ledPin = 13;

void setup (){
  Robot.Direction (LOW,HIGH);// (left direction,right direction); 
  pinMode(ledPin,OUTPUT);
  Goble.begin();
  Serial.begin(115200);
}

void loop (){
  if(Goble.available()){
    joystickX = Goble.readJoystickX();  
    joystickY = Goble.readJoystickY();
    Serial.print("joystickX: ");
    Serial.print(joystickX);
    Serial.print("joystickY: ");
    Serial.println(joystickX);

    buttonState[SWITCH_UP]     = Goble.readSwitchUp();
    buttonState[SWITCH_LEFT]   = Goble.readSwitchLeft();
    buttonState[SWITCH_RIGHT]  = Goble.readSwitchRight();
    buttonState[SWITCH_DOWN]   = Goble.readSwitchDown();
    buttonState[SWITCH_SELECT] = Goble.readSwitchSelect();
    buttonState[SWITCH_START]  = Goble.readSwitchStart();

    //enable to map the value from (1~255) to (-255~255)
    bool upSwitch=buttonState[SWITCH_UP];
    bool downSwitch=buttonState[SWITCH_DOWN];
    bool lSwitch=buttonState[SWITCH_LEFT];
    bool rSwitch=buttonState[SWITCH_RIGHT];
    
    Serial.print("Switch: ");
    Serial.print(upSwitch);
    Serial.print("  ");
    Serial.print(downSwitch);
    Serial.print("  ");
    Serial.print(lSwitch);
    Serial.print("  ");
    Serial.println(rSwitch);
    int lSpeed = 0; //initialize to stop
    int rSpeed = 0; //initialize to stop

    if (upSwitch == 0){
      lSpeed = -200;
      rSpeed = -200; 
      Robot.Speed (lSpeed,rSpeed);
    } else if (downSwitch == 0){
      lSpeed = 200;
      rSpeed = 200;    
    } else if (lSwitch == 0){
      lSpeed = 200;
      rSpeed = -200;
    } else if (rSwitch == 0){
      lSpeed = -200;
      rSpeed = 200;
    }else{
      lSpeed = 0;
      rSpeed = 0;
    }
    Serial.print("Speed: ");
    Serial.print(lSpeed);
    Serial.print("  ");
    Serial.println(rSpeed);
    Robot.Speed(lSpeed,rSpeed);
    delay(200);
    Robot.Speed(0,0);
    
    
//
//    if (SpeedX>200 || SpeedX<-200){           //when joystick X is pushed up
//      LeftWheelSpeed=SpeedX;                 
//      RightWheelSpeed=SpeedX;
//      Robot.Speed (LeftWheelSpeed,RightWheelSpeed);
//    }         
//    else if (SpeedY>200 || SpeedY<-200){           
//      LeftWheelSpeed=SpeedY-80;               //when joystick Y is pushed up
//      RightWheelSpeed=-SpeedY-80;
//      Robot.Speed(LeftWheelSpeed,RightWheelSpeed);
//    }
//    else if (SpeedX==0 && SpeedY==0){
//      Robot.Speed(0,0);
//    }
//    
//    if (buttonState[1] == PRESSED){
//        digitalWrite(ledPin,HIGH);  
//    }
//    if (buttonState[1] == RELEASED){
//        digitalWrite(ledPin,LOW);
//    }
  }
}

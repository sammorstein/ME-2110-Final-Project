#include <myDuino.h>

myDuino robot(1);

bool button1=false;
bool run1=true;
int IR_Sensor=0;
int encCount=0;
int encDir=0;
int basketball=12;
int enc1=50;
int encMax=50;

//Create Encoder Handler
void encHandler() {
  robot.doEncoder();
}

void setup() {
  // put your setup code here, to run once:
  robot.digital(1,0);
  robot.digital(2,0);
  robot.digital(3,0);
  robot.digital(4,0);
  //Serial.begin(9600);
  //Attach handler to Encoder Channels
  attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encHandler, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (run1==true){
  button1=robot.readButton(1);
  if (button1==1){
    robot.digital(1,1); //activate actuator
    delay(500);
    robot.digital(1,0); //reset actuator
    delay(500);
   //drop next arrow
    robot.digital(3,1); //activate arrow solenoid
    delay(2000);
   //fire second arrow
    robot.digital(1,1); //activate actuator
    delay(500);
    robot.digital(1,0); //reset actuator
    delay(500);
    robot.digital(1,1); //activate actuator
    delay(500);
    robot.digital(1,0); //reset actuator
    delay(500);
    robot.digital(1,1); //activate actuator
    delay(500);
    robot.digital(1,0); //reset actuator
    delay(500);
    robot.digital(1,1); //activate actuator
    delay(500);
    robot.digital(1,0); //reset actuator
    delay(500);
    robot.digital(1,1); //activate actuator
    delay(500);  
    robot.digital(1,0); //reset actuator
    delay(500);
    robot.digital(1,1); //activate actuator
    delay(500);       
    while (encCount<enc1){
      if(basketball==6) enc1=7;
      if(basketball==12) enc1=14;
      if(basketball==18) enc1=24;
        IR_Sensor=robot.readIR();
        robot.moveMotor(1,2,150);
        encCount = robot.encoderCount();
        encDir = robot.encoderDir();
//      if(encCount>=50){
//        break;
//      }
//      Serial.println(String(encCount)+"     "+String(encDir)+"     "+String(IR_Sensor));
    }
    robot.moveMotor(1,2,0);
    robot.digital(2,1); //activate actuator
    delay(500);
    robot.digital(2,0); //reset actuator
    delay(500);
    //drop next basketball
    robot.digital(4,1); //activate basketball solenoid
    delay(1000);    
    robot.digital(2,1); //activate actuator
    delay(500);
    robot.digital(2,0);
    delay(500);
//    while (IR_Sensor<=250){
//      IR_Sensor=robot.readIR();
//      robot.moveMotor(1,2,150);
//      encCount = robot.encoderCount();
//      encDir = robot.encoderDir();
//      if(encCount>=50){
//        break;
//      }
//
    robot.moveMotor(1,2,0);
    //fire second basketball
//    robot.digital(2,1); //activate actuator
//    delay(500);
//    robot.digital(2,0);
//    delay(500);
    while (encCount<encMax){
      if(basketball==6) encMax=11;
      if(basketball==12) encMax=23;
      if(basketball==18) encMax=33;
      IR_Sensor=robot.readIR();
      robot.moveMotor(1,2,150);
      encCount = robot.encoderCount();
      encDir = robot.encoderDir();
//      if(encCount>=50){
//        break;
//      }
//      Serial.println(String(encCount)+"     "+String(encDir)+"     "+String(IR_Sensor));
     } 
    robot.moveMotor(1,2,0);  
    delay(500);
    robot.moveMotor(2,2,255);
    delay(1000);
    robot.moveMotor(2,2,100);
    delay(750);
    //robot.moveMotor(2,2,100);
    //delay(2000);
    robot.moveMotor(2,1,255);
    delay(1500);
    robot.moveMotor(2,2,0);
    robot.digital(2,1);
    delay(500); 
    while (encCount!=-2){
      robot.moveMotor(1,1,150);
      encCount = robot.encoderCount();
      encDir = robot.encoderDir();    
//      Serial.println(String(encCount)+"     "+String(encDir));  
    }
    robot.moveMotor(1,1,0);
    run1=false;
    robot.digital(3,0);
    robot.digital(4,0);         
  }
}
}

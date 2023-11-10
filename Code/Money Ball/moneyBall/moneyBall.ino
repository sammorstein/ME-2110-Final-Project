#include <myDuino.h>

myDuino robot(1); 

unsigned long stopeTime = 0;
int mspd = 100;         // may need calibration
int retrieve = 0;
int retract = 0;
int moveTime = 200;    // will need to be calibrated
int IRVal = 0;
int distance = 0;
boolean inPos = true;
boolean finish = false;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 

}
void loop() {
  // put your main code here, to run repeatedly:

   turnTime = millis();
   stopTime = turnTime + 5000; 
    
if (inPos && retrieve == 0 && retract == 0) {
  retrieve = 1;
  robot.moveMotor(1,1,mspd)
  delay(moveTime);
}

if (retrieve == 1) {
  robot.moveMotor(1,1,0);
  delay(moveTime);
  retrieve = 0;
  retract = 1;
}

if (retract == 1) {
  robot.moveMotor(1,2,mspd);
  delay(moveTime);
  finish = true;
}

if (finish) {
  robot.moveMotor(1,2,0);
  inPos = 0;
}


}

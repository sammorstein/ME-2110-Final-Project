#include <myDuino.h>

myDuino robot(1);

bool button1=false;
bool run1=true;

void setup() {
  // put your setup code here, to run once:
  robot.digital(1,0);
  robot.digital(2,0);
  robot.digital(3,0);
  robot.digital(4,0);
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
    //robot.moveMotor(1,2,255);
   // delay(20000);
   // robot.moveMotor(1,2,0);
   // delay(500);
    delay(2000);
    robot.digital(2,1); //activate actuator
    delay(500);
    robot.digital(2,0); //reset actuator
    delay(500);
    //drop next basketball
    robot.digital(4,1); //activate basketball solenoid
    delay(1000);
    //fire second basketball
    robot.digital(2,1); //activate actuator
    delay(500);   
    //robot.moveMotor(1,1,255);
    //delay(20000);
   //robot.moveMotor(1,1,0);
   //delay(500);

    run1=false;
    robot.digital(3,0);
    robot.digital(4,0);
    //robot.digital(1,0);
    //robot.digital(2,0);
  }
  }
}

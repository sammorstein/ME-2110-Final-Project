#include <myDuino.h>

myDuino robot(1);



void setup() {
  // put your setup code here, to run once:
  robot.digital(1,0); //sets the first valve to off
  robot.digital(2,0); //sets the first valve to off
}

void loop() {
  // put your main code here, to run repeatedly:
  //fires arrows 

 robot.digital(1,1);
 delay(100);
 robot.digital(1,0);
 delay(1000);
 robot.digital(1,1);

  //fires basketballs
 robot.digital(2,1);
 delay(100);
 robot.digital(2,0);
 delay(1000);
 robot.digital(2,1);
 delay(100);
 robot.digital(2,0);

  //fires moneybaall
 robot.digital(2,1);
}

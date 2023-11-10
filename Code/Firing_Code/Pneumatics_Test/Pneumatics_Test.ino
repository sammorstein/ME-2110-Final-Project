#include <myDuino.h>

myDuino robot(1);



void setup() {
  // put your setup code here, to run once:
  robot.digital(1,0); //sets the first valve to off
  robot.digital(2,0); //sets the first valve to off

    //Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //fires arrows 
  Serial.println(robot.readButton(1));
  if (robot.readButton(1)==1){
    delay(3000);
     robot.digital(1,1);
     delay(100);
     robot.digital(1,0);
     delay(3000);
    // robot.digital(1,1);
  

  //fires basketballs
  robot.digital(2,1);
  delay(100);
  robot.digital(2,0);
  delay(3000);
  //robot.digital(2,1);
  //delay(100);
 // robot.digital(2,0);

  //fires moneybaall
  //robot.digital(2,1);

  }
}

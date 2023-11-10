#include <myDuino.h>

myDuino robot(1);
int IR_Sensor=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  IR_Sensor=robot.readIR();
  Serial.println(String(IR_Sensor));
  if (IR_Sensor>475){
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
  }
}

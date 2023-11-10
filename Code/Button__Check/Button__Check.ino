#include <myDuino.h>

myDuino robot(1);
bool button1=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   button1=robot.readButton(1);
   Serial.println(String(button1));
} 

#include <myDuino.h> // open library

myDuino robot(1); // initialize robot

// Declare Variables
int currentLocation = 0; // tracks current location
int moneyball = 6; // caculated distance from start to money ball
int turnsPerInch = 0.5; // calculated full encoder rotations made per foot

int encCount = 0; // encoder clicks
int encTurns = 0; // full encoder rotations
int mDir = 1; // motor direction
int mSpeed = 255; // motor speed

// Create Encoder Handler
void encHandler() {
  robot.doEncoder(); // creating the encoder handler so we can use the input from the encoder
}

void setup() {
  // put your setup code here, to run once: 
  
  // Attach handler to Encoder Channel
  attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE); // attatch handler to read encoder channel 2
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Calculate the current location of the robot while traveling to money ball. Move accordingly
  while (currentLocation < moneyball) {
    robot.moveMotor(1,mDir,mSpeed); // run motor forward at max speed
    encCount = robot.encoderCount(); // read how many clicks the encoder has turned
    encTurns=encCount/16; // 16 clicks per full turn, so divide total clicks by 16
    currentLocation = encTurns * turnsPerInch; // determine current location
  }

  // Stop motor once money ball has been reached
  
  robot.moveMotor(1, mDir, 0);

  // Delay to load money ball
  
  // Delay to launch basketballs
  delay(15000); // 15 seconds

  // ** BASKETBALL LAUNCH CODE HERE ** //

  // Calculate the current location the robot while returning to start position. Move accordingly

  encCount = 0; // reset encoder value
  currentLocation = 0; // reset location
  
  mDir = 2; // move motor backwards
  
  while (currentLocation < moneyball) {
    robot.moveMotor(1,mDir,mSpeed); // run motor forward at max speed
    encCount = robot.encoderCount(); // read how many clicks the encoder has turned
    encTurns=encCount/16; // 16 clicks per full turn, so divide total clicks by 16
    currentLocation = encTurns * turnsPerInch; // determine current location
  }

  // Stop motor
  robot.moveMotor(1,mDir,0);
  //break // escape loop

}

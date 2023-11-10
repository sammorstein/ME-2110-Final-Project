#include <myDuino.h> // open library

myDuino robot(1); // initialize robot

// Declare Variables
bool button1=0; //state of button

int currentLocation = 0; // tracks current location
int moneyballLocation=0; // caculated distance from start to money ball
int totalDistance = 0; // total distance from start to basketball launch line
int turnsPerFoot = 0; // calculated full encoder rotations made per foot--NEEDS WHEEL MEASUREMENTS

int encCount = 0; // encoder clicks
int encTurns = 0; // full encoder rotations
int mForward = 1; // forward motor direction
int mBack = 2; // backward motor direction
int mSpeed = 255; // motor speed

int irReading=0; // voltage reading from IR sensor

int moneySpeed=0; //NEED TO DETERMINE SPEED FOR MONEYBALL MOTOR
int moneyTime=0; // NEED TO DETERMINE RUN TIME FOR MONEYBALL MOTOR


// Create Encoder Handler
void encHandler() {
  robot.doEncoder(); // creating the encoder handler so we can use the input from the encoder
}

//Setup
void setup() {
  // put your setup code here, to run once:

  //Initialize Serial Monitor
  Serial.begin(9600);

  // Attach handler to Encoder Channel
  attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE); // attatch handler to read encoder channel 2

  //Set digital outputs to off
  robot.digital(1,0); //sets the arrow valve to off
  robot.digital(2,0); //sets the basketball valve to off
  robot.digital(3,0); //turns off arrow solenoid
  robot.digital(4,0); // turns off basketball solenoid
}

void loop() {
  // put your main code here, to run repeatedly:
button1=robot.readButton(1); //check state of the button
Serial.println(button1);

if (button1==1){ //start entire process when button1 is pushed 

//ARROWS
   //fire first arrow
   robot.digital(1,1); //activate actuator
   delay(100);
   robot.digital(1,0); //reset actuator
   delay(500);

   //drop next arrow
   robot.digital(3,1); //activate arrow solenoid

   //fire second arrow
   delay(2000);
   robot.digital(1,1); //activate actuator

//BASKETBALL - might need to move closer for basketballs
   //fire first basketball
   robot.digital(2,1); //activate actuator
   delay(100);
   robot.digital(2,0); //reset actuator

   //drop next basketball
   robot.digital(4,1); //activate basketball solenoid

   //fire second basketball
   delay(1000);
   robot.digital(2,1); //activate actuator
   delay(100);
   robot.digital(2,0); //reset actuator
//
////MOVE TO MONEYBALL POSITION
//
//  while(irReading < SELECTED DISTANCE DETERMINED FROM TESTING) {
//    robot.moveMotor(1,mForward,mSpeed); // run motor forward at max speed
//    encCount = robot.encoderCount(); // read how many clicks the encoder has turned
//    encTurns=encCount/16; // 16 clicks per full turn, so divide total clicks by 16
//    currentLocation = encTurns * turnsPerFoot; // determine current location
//    irReading=robot.readIR(); //update current reading from IR sensor
//  }
//
//    // Stop motor once money ball has been reached
//    robot.moveMotor(1, mForward, 0)
//    delay(1000);
//    
////COLLECT MONEYBALL
//
//    //rotate arm inward for predetermined amount of time
//    robot.moveMotor(2,mForward, moneySpeed);
//    delay(moneyTime);
//
//    //rotate arm outward for same amount of time
//    robot.moveMotor(2,mBack, moneySpeed);
//    delay(moneyTime);
//
//   // Stop motor once arm is back in place
//    robot.moveMotor(2, mBack, 0);
//    delay(1000);
//
////LAUNCH MONEYBALL
//
//   robot.digital(2,1); //activate actuator
//   delay(1000);
//
////RETURN HOME
//  while(encCount > 0){ //when the encoder turns the other way, it subtracts numbers from its count
//    robot.moveMotor(1,mBack,mSpeed); // run motor back at max speed
//    encCount = robot.encoderCount(); // read how many clicks the encoder has turned     
//  }
//
//    // Stop motor once we get home
//    robot.moveMotor(1, mForward, 0)
//    delay(1000);

    //Set digital outputs to off
    delay(1000);
    button1=0;
    robot.digital(1,0); //sets the arrow valve to off
    robot.digital(2,0); //sets the basketball valve to off
    robot.digital(3,0); //turns off arrow solenoid
    robot.digital(4,0); // turns off basketball solenoid

} // closes button if statement    
} //closes void loop

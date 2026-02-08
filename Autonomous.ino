
// TETRIX PRIZM & PRIZM Teleop Library, when you will download and then include the library

#include <PRIZM.h>    
#include <TELEOP.h>  

PRIZM prizm;          // Create an instance within the PRIZM Library class named prizm

void setup() {

  prizm.PrizmBegin();        // Intializes the PRIZM controller and waits here for press of green start button
  prizm.setMotorInvert(1,1); // invert so when you push two sticks forward the robot goes forward

 // Autonomous: 

  prizm.setMotorPowers(1, 20, 2, 20); // first motor voltage 20, second motor voltage 20. Robot will go forward
  delay(3000); // do the task for 3000 milis = 3000 s
  prizm.setMotorPowers(1, -20, 2, -20); // first motor voltage -20, second motor voltage -20. Robot will go backwards
  delay(3000);
  prizm.setMotorPowers(1, 20, 2, -20); // first motor voltage 20, second motor voltage -20. Robot will turn right
  delay(3000);
  prizm.setMotorPowers(1, -20, 2, 20); // first motor voltage -20, second motor voltage 20. Robot will turn left
}

void loop() {

  // not necessary because we are working with autonomous. 

}
``` 

#include <Arduino.h>

#include <AccelStepper.h>

#define ONBOARD_LED 13

#define X_STEP_PIN                            2
#define X_DIR_PIN                             3
#define X_ENABLE_PIN                          4

#define Y_STEP_PIN                            5
#define Y_DIR_PIN                             6
#define Y_ENABLE_PIN                          7

#define INCREMENT 50000
#define SPEED 1600
#define RATIO 2

AccelStepper xStepper(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper yStepper(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);



void setup() {
  pinMode(ONBOARD_LED,OUTPUT);

   xStepper.setMaxSpeed(SPEED);
   xStepper.setAcceleration(2000);
   xStepper.setEnablePin(X_ENABLE_PIN);
   xStepper.setPinsInverted(false, false, true);
   xStepper.moveTo(INCREMENT);
   xStepper.enableOutputs();
  
   yStepper.setMaxSpeed(SPEED/RATIO);
   yStepper.setAcceleration(2000);
   yStepper.setEnablePin(Y_ENABLE_PIN);
   yStepper.setPinsInverted(false, false, true);
   yStepper.moveTo(-INCREMENT/RATIO);
   yStepper.enableOutputs();
  
}

void loop() {
  xStepper.run();
  yStepper.run();
 

  if ( xStepper.distanceToGo() == 0  )
   {
     xStepper.moveTo(xStepper.currentPosition()+INCREMENT);
   }

if ( yStepper.distanceToGo() == 0  )
   {
     yStepper.moveTo(yStepper.currentPosition()-INCREMENT/RATIO);
   }

}
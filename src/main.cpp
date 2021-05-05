#include <Arduino.h>

#include <AccelStepper.h>

#define ONBOARD_LED 13

#define X_STEP_PIN                            54
#define X_DIR_PIN                             55
#define X_ENABLE_PIN                          38

#define Y_STEP_PIN                            60
#define Y_DIR_PIN                             61
#define Y_ENABLE_PIN                          56

#define Z_STEP_PIN                            46
#define Z_DIR_PIN                             48
#define Z_ENABLE_PIN                          62


AccelStepper xStepper(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper yStepper(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper zStepper(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);

void setup() {
  pinMode(ONBOARD_LED,OUTPUT);

   xStepper.setMaxSpeed(5000);
   xStepper.setAcceleration(5000);
   xStepper.setEnablePin(X_ENABLE_PIN);
   xStepper.setPinsInverted(false, false, true);
   xStepper.moveTo(10000);
   xStepper.enableOutputs();
  
   yStepper.setMaxSpeed(5000);
   yStepper.setAcceleration(5000);
   yStepper.setEnablePin(Y_ENABLE_PIN);
   yStepper.setPinsInverted(false, false, true);
   yStepper.moveTo(10000);
   yStepper.enableOutputs();

   zStepper.setMaxSpeed(5000);
   zStepper.setAcceleration(5000);
   zStepper.setEnablePin(Z_ENABLE_PIN);
   zStepper.setPinsInverted(false, false, true);
   zStepper.moveTo(10000);
   zStepper.enableOutputs();
  
}

void loop() {
  xStepper.run();
  yStepper.run();
  zStepper.run();

  if ( xStepper.distanceToGo() == 0  )
   {
     xStepper.moveTo(-xStepper.currentPosition());
   }

if ( yStepper.distanceToGo() == 0  )
   {
     yStepper.moveTo(-yStepper.currentPosition());
   }

if ( zStepper.distanceToGo() == 0  )
   {
     zStepper.moveTo(-zStepper.currentPosition());
   }

}
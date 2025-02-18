#include <AccelStepper.h>
#include <math.h>


#define MOTOR_INTERFACE_TYPE 1
#define Right_DIR_PIN 14
#define Right_STEP_PIN 12
#define Wheel_Diametre 79
#define Wheel_Perimeter M_PI * Wheel_Diametre   //=245 mm
#define Left_DIR_PIN 32
#define Left_STEP_PIN 25
#define Pami_Track  133 //135
#define STEPS_PER_REVOLUTION 200 // 200->one rotate
AccelStepper RightStepper(MOTOR_INTERFACE_TYPE, Right_STEP_PIN, Right_DIR_PIN);
AccelStepper LeftStepper(MOTOR_INTERFACE_TYPE, Left_STEP_PIN, Left_DIR_PIN);
void setup() {
    pinMode(Right_DIR_PIN, OUTPUT);
  pinMode(Right_STEP_PIN, OUTPUT);
  pinMode(Left_DIR_PIN, OUTPUT);
  pinMode(Left_STEP_PIN, OUTPUT);


  LeftStepper.setMaxSpeed(1000);
  LeftStepper.setAcceleration(450);
  LeftStepper.setSpeed(600);

  RightStepper.setMaxSpeed(1000);
  RightStepper.setAcceleration(450);
  RightStepper.setSpeed(600);

}

void loop() {
  delay(2000);
  RightStepper.move(-2000);
  LeftStepper.move(2000);
  while (LeftStepper.isRunning() || RightStepper.isRunning()) {
    LeftStepper.run();
    RightStepper.run();
  }

}

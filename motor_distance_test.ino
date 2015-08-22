// works best with sainsmart driver. Excitation double.


#include <MyLidarCamera.h>
#include <MyAccelStepper.h>

int Distance = 0;  // Record the number of steps we've taken

int stepTime = 700;

unsigned long pulse_width;

#define EN_PIN_AXIS_MOTOR 4
#define STEP_PIN_AXIS_MOTOR 2
#define DIR_PIN_AXIS_MOTOR 3

//MyAccelStepper axisStepper(STEP_PIN_AXIS_MOTOR, DIR_PIN_AXIS_MOTOR);

int totalSteps = 200;
int axisStepperPosition = 1;

boolean cameraStepperFinished = false;
boolean axisStepperFinishedCircle = false;
boolean axisStepperFinishStep = false;

void setup() {     

   Serial.begin(9600); 
  // axisStepper.setSpeed(100);
   setUpAxisMotor();
}

void loop() {
   motorRun();
}

void motorRun(){
  digitalWrite(EN_PIN_AXIS_MOTOR,HIGH);
    digitalWrite(STEP_PIN_AXIS_MOTOR,HIGH);
    digitalWrite(DIR_PIN_AXIS_MOTOR,LOW);
    delayMicroseconds(stepTime);
    digitalWrite(STEP_PIN_AXIS_MOTOR,LOW);
    digitalWrite(DIR_PIN_AXIS_MOTOR,LOW);
    delayMicroseconds(stepTime);
}



void setUpAxisMotor(){
   pinMode(DIR_PIN_AXIS_MOTOR, OUTPUT);
   pinMode(STEP_PIN_AXIS_MOTOR, OUTPUT);
   
   digitalWrite(DIR_PIN_AXIS_MOTOR,LOW);
}



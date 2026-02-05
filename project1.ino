
#include <Stepper.h>
#include "SR04.h"
#define TRIG_PIN 5
#define ECHO_PIN 6

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 17;         // 28BYJ-48 stepper 0~17 rpm
long a;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(rolePerMinute);
  Serial.begin(9600);
}

void loop() {  
  a = sr04.Distance();
  if (a > 5) {
    myStepper.step(10);
  }
  Serial.println(a);
}

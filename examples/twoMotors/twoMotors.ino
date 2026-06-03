#include <makeduinoDCMotor.h>

makeduinoDCMotor motor;

void setup() {
  motor.motorTurnOn("M1", 70, 3000);
  motor.motorTurnOn("M2", -50, 5000);

  motor.motorTurnOn("M1", 100, 4000);
  motor.motorTurnOn("M2", -80, 6000);

  motor.motorTurnOffAll();
}

void loop() {
}

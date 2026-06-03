#include <makeduinoDCMotor.h>

makeduinoDCMotor motor;

void setup() {
  // M1 al 100%
  motor.motorTurnOn("M1");
  delay(2000);
  motor.motorTurnOff("M1");

  // M1 al 50% endavant
  motor.motorTurnOn("M1", 50);
  delay(2000);
  motor.motorTurnOff("M1");

  // M1 al 50% enrere
  motor.motorTurnOn("M1", -50);
  delay(2000);
  motor.motorTurnOff("M1");

  // M2 al 80% durant 5 segons
  motor.motorTurnOn("M2", 80, 5000);
}

void loop() {
}

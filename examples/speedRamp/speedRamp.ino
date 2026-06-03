#include <makeduinoDCMotor.h>

makeduinoDCMotor motor;

void setup() {
  // El motor accelera a poc a poc.
  for (int speed = 0; speed <= 100; speed = speed + 10) {
    motor.motorTurnOn("M1", speed);
    delay(300);
  }

  // El motor frena a poc a poc.
  for (int speed = 100; speed >= 0; speed = speed - 10) {
    motor.motorTurnOn("M1", speed);
    delay(300);
  }

  motor.motorTurnOff("M1");
}

void loop() {
}

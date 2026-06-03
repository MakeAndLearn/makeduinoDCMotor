#include <makeduinoDCMotor.h>

makeduinoDCMotor motor;

void forward(int speed, unsigned long time) {
  motor.motorTurnOn("M1", speed);
  motor.motorTurnOn("M2", speed);
  delay(time);
  motor.motorTurnOffAll();
}

void backward(int speed, unsigned long time) {
  motor.motorTurnOn("M1", -speed);
  motor.motorTurnOn("M2", -speed);
  delay(time);
  motor.motorTurnOffAll();
}

void turnRight(int speed, unsigned long time) {
  motor.motorTurnOn("M1", speed);
  motor.motorTurnOn("M2", -speed);
  delay(time);
  motor.motorTurnOffAll();
}

void turnLeft(int speed, unsigned long time) {
  motor.motorTurnOn("M1", -speed);
  motor.motorTurnOn("M2", speed);
  delay(time);
  motor.motorTurnOffAll();
}

void setup() {
  forward(60, 2000);
  delay(500);

  turnRight(50, 800);
  delay(500);

  backward(40, 1500);
  delay(500);

  turnLeft(50, 800);
}

void loop() {
}

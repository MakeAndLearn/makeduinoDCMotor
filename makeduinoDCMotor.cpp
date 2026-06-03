#include "makeduinoDCMotor.h"
#include <string.h>

makeduinoDCMotor::makeduinoDCMotor() {
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor1DirectionPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(motor2DirectionPin, OUTPUT);

  motorTurnOffAll();
}

void makeduinoDCMotor::motorTurnOn(const char* motor) {
  setMotor(motor, 100);
}

void makeduinoDCMotor::motorTurnOn(const char* motor, int speed) {
  setMotor(motor, speed);
}

void makeduinoDCMotor::motorTurnOn(const char* motor, int speed, unsigned long time) {
  setMotor(motor, speed);
  delay(time);
  motorTurnOff(motor);
}

void makeduinoDCMotor::motorTurnOff(const char* motor) {
  if (isMotor(motor, "M1")) {
    analogWrite(motor1SpeedPin, 0);
    digitalWrite(motor1DirectionPin, LOW);
  } else if (isMotor(motor, "M2")) {
    analogWrite(motor2SpeedPin, 0);
    digitalWrite(motor2DirectionPin, LOW);
  }
}

void makeduinoDCMotor::motorTurnOffAll() {
  motorTurnOff("M1");
  motorTurnOff("M2");
}

void makeduinoDCMotor::setMotor(const char* motor, int speed) {
  int limitedSpeed = constrain(speed, -100, 100);
  int pwm = map(abs(limitedSpeed), 0, 100, 0, 255);

  if (limitedSpeed == 0) {
    motorTurnOff(motor);
    return;
  }

  if (isMotor(motor, "M1")) {
    digitalWrite(motor1DirectionPin, limitedSpeed < 0 ? HIGH : LOW);
    analogWrite(motor1SpeedPin, pwm);
  } else if (isMotor(motor, "M2")) {
    digitalWrite(motor2DirectionPin, limitedSpeed < 0 ? HIGH : LOW);
    analogWrite(motor2SpeedPin, pwm);
  }
}

bool makeduinoDCMotor::isMotor(const char* motor, const char* expected) {
  return motor != NULL && strcmp(motor, expected) == 0;
}

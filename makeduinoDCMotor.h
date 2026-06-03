#ifndef makeduinoDCMotor_h
#define makeduinoDCMotor_h

#include "Arduino.h"

class makeduinoDCMotor {
  public:
    makeduinoDCMotor();

    void motorTurnOn(const char* motor);
    void motorTurnOn(const char* motor, int speed);
    void motorTurnOn(const char* motor, int speed, unsigned long time);

    void motorTurnOff(const char* motor);
    void motorTurnOffAll();

  private:
    const int motor1SpeedPin = 10;
    const int motor1DirectionPin = 12;
    const int motor2SpeedPin = 11;
    const int motor2DirectionPin = 13;

    void setMotor(const char* motor, int speed);
    bool isMotor(const char* motor, const char* expected);
};

#endif

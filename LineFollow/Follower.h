#include <Servo.h>
#include <Arduino.h>
#include "Sensor.h"

#ifndef FOLLOWER_H
#define FOLLOWER_H

enum Directions {left, right, straight};

uint8_t readSensorsBinary(Sensor*, uint8_t);
uint16_t readSensorsAnalog(Sensor*, uint8_t);

bool lineFollower(Servo*, Sensor*, uint8_t);
bool exitBoundary(Servo*, Sensor*, uint8_t);
bool enterBoundary(Servo*, Sensor*, uint8_t);
bool junctionTurn(Servo*, Sensor*, uint8_t);

#endif

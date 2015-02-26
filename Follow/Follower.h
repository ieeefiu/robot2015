#include <Servo.h>
#include <Arduino.h>
#include "Sensor.h"

#define left -1
#define right 1
#define straight 0

uint8_t readSensorsBinary(Sensor*, uint8_t);
uint16_t readSensorsAnalog(Sensor*, uint8_t);
uint16_t setServos(Servo*, uint8_t, uint16_t);
uint8_t lineFollower(Servo*, Sensor*, uint8_t);


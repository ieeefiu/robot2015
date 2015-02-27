#include <stdint.h>
#include <Arduino.h>

#ifndef SENSOR_H
#define SENSOR_H

#define numCalibs 100
#define unattached -1

#ifdef ARDUINO_UNO
	#define upperAnalogPin 5
	#define upperDigitalPin 13
#else 	
	#define upperAnalogPin 15
	#define upperDigitalPin 53
#endif

#define validAnalogPin(pin) ((pin) >= 0 && (pin) <= upperAnalogPin)
#define validDigitalPin(pin) ((pin) >= 0 && (pin) <= upperDigitalPin)
 	
class Sensor {
private:
	uint16_t threshold;		
	uint16_t val;
	uint8_t pin;

public:
	Sensor();
	Sensor(uint8_t);

	uint8_t attach(uint8_t);	
	uint8_t detach();

	uint8_t calibrate();
	uint16_t read();

	uint8_t getBit();
	uint16_t getThreshold();
	uint16_t getVal();
};

#endif

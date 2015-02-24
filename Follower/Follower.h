#include <Servo.h>
#include <Arduino.h>
#include "Sensor.h"

#define left -1
#define right 1
#define straight 0

uint8_t readSensorsBinary(Sensor*, uint8_t);
uint16_t readSensorsAnalog(Sensor*, uint8_t);
uint16_t setServos(Servo*, uint8_t, uint16_t);

uint8_t lineFollower(Servo* servos, Sensor* sensors, uint8_t numSensors) {
	uint8_t sensorBinary = readSensorsBinary(sensors, numSensors);
	switch(sensorBinary) { 

		// left junction
		case B01111100: {
			while(!readSensorsBinary(sensors, numSensors) != B01111111)
				setServos(servos, left, 0);
			break;
		}
		// right junction
		case B01111110: {
			while(!readSensorsBinary(sensors, numSensors) != B01111111)
				setServos(servos, right, 0);
			break;
		}
		// straight line
		case B01001100: 
		case B01011110:
	
		// left turn
		case B00111100:
		case B00111110:

		// right turn
		case B00001111:
		case B00011111: {
			float Kp = 0.5, Kd = 1;
			uint16_t lastError = 0;
			uint16_t thisError = 0;
			uint16_t delta = 0;
				
			uint16_t rightAnalog = readSensorsAnalog(sensors, (uint8_t) (numSensors / 2));
			uint16_t leftAnalog = readSensorsAnalog(sensors + (uint8_t) (numSensors / 2), (uint8_t) (numSensors / 2));
			
			thisError = leftAnalog - rightAnalog;
			delta = Kp * thisError + Kd * (thisError - lastError);
			lastError = thisError;				
			
			setServos(servos, straight, delta);
			break;
		}
		default:
			break;			
	}
}

uint16_t setServos(Servo* servos, uint8_t direction, uint16_t delta) {
	switch(direction) {
		case left: {
			servos[right].write(10);	
			servos[left].write(90);
			break;
		}
		case right: {
			servos[right].write(90);	
			servos[left].write(170);
			break;
		}
		case straight: {
			servos[right].write(45 - delta);
			servos[left].write(135 - delta);
			break;
		}
		default:
			break;
	}
}

/*	Precondition: Sensors in "sensors" array have been calibrated.
	Postcondition: Writes binary state of the nth sensor in "sensor" array
	to the nth bit of "sensorBinary" and returns it.
*/

uint8_t readSensorsBinary(Sensor* sensors, uint8_t numSensors) {
	uint8_t sensorBinary = B00000000;
	for(uint8_t i = 0; i < numSensors; i++) 
		bitWrite(sensorBinary, i, sensors[i].getBit());

	return sensorBinary;
}

uint16_t readSensorsAnalog(Sensor* sensors, uint8_t numSensors) {
	uint16_t sensorAnalog = 0;
	for(uint8_t i = 0; i < numSensors; i++)
		sensorAnalog += sensors[i].read();

	return sensorAnalog;
}

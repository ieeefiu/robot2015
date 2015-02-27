#include "Follower.h"
#include <stdint.h>

uint8_t lineFollower(Servo* servos, Sensor* sensors, uint8_t numSensors) {
	Directions direction;

	uint8_t sensorBinary = readSensorsBinary(sensors, numSensors);

	switch(sensorBinary) { 

		// left junction
		case B01111100: {
			direction = left;
			while(!readSensorsBinary(sensors, numSensors) != B01111111)
				setServos(servos, direction, 0);
			break;
		}
		// right junction
		case B01111110: {
			direction = right;
			while(!readSensorsBinary(sensors, numSensors) != B01111111)
				setServos(servos, direction, 0);
			break;
		}
		
		// follow line
		default: {
			float Kp = 0.5, Kd = 1;
			uint16_t lastError = 0;
			uint16_t thisError = 0;
			uint16_t delta = 0;
			
			// read sensors on right half of array				
			uint16_t rightAnalog = readSensorsAnalog(sensors, (uint8_t) (numSensors / 2));
			
			// read sensors on left half of array
			uint16_t leftAnalog = readSensorsAnalog(sensors + (uint8_t) (numSensors / 2), (uint8_t) (numSensors / 2));
			
			thisError = leftAnalog - rightAnalog;
			delta = Kp * thisError + Kd * (thisError - lastError);
			lastError = thisError;				
			
			direction = straight;
			setServos(servos, direction, delta);
			break;
		}		
	}
}

uint16_t setServos(Servo* servos, Directions direction, uint16_t delta) {
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
			servos[right].write(45 - delta);
			servos[left].write(135 - delta);
			break;
	}
}

/*	Precondition: Sensors in "sensors" array have been calibrated.
	Postcondition: Writes binary state of the nth sensor in "sensor" array
	to the nth bit of "sensorBinary" and returns it.
*/

uint8_t readSensorsBinary(Sensor* sensors, uint8_t numSensors) {
	uint8_t sensorBinary = B00000000;
	for(uint8_t i = 0; i < numSensors; i++) {
		sensors[i].read();
		bitWrite(sensorBinary, i, sensors[i].getBit());
	}

	return sensorBinary;
}

/*	Precondition: Sensors in "sensors" array have been calibrated.
	Postcondition: Returns sum of all sensor readings up to "numSensors" 
*/

uint16_t readSensorsAnalog(Sensor* sensors, uint8_t numSensors) {
	uint16_t sensorAnalog = 0;
	for(uint8_t i = 0; i < numSensors; i++)
		sensorAnalog += sensors[i].read();

	return sensorAnalog;
}

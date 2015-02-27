#include "Sensor.h"
#include <Arduino.h>
#include <stdint.h>

Sensor::Sensor() {
	this->threshold = 0;
	this->val = 0;
	this->pin = unattached;
}

Sensor::Sensor(uint8_t pin) {
	this->threshold = 0;
	this->val = 0;
	this->attach(pin);
}

/*	Precondition: "pin" is within Arduino's valid range.
	Postcondition: Sensor's pin is assigned parameter, returns 0.
	Error: Sensor pin is set to "unattached", returns 1. */

uint8_t Sensor::attach(uint8_t  pin) {
	if(!validAnalogPin(pin)) {
		this->pin = unattached;
		return 1;
	}

	this->pin = pin;	
	return 0;	
}

uint8_t Sensor::detach() {
	this->pin = unattached;
}

/*	Precondition: Sensor's pins are assigned.
	Postcondition: Sensor's threshold value is calculated
	by reading "numCalibs" number of readings and finding
	the average of max and min.
	Error: No error checks are made; however, Sensor's threshold
	may need to be offset by a bias during actual testing. */

uint8_t Sensor::calibrate() {

	uint16_t max, min; 
	uint16_t vals[numCalibs] = {};
        
	for(uint16_t i = 0; i < numCalibs; i++) {
		vals[i] = this->read();
		if(vals[i] > max || i < 1)
			max = vals[i];
	 	if(vals[i] < min || i < 1)
     	min = vals[i];
	}
        
	this->threshold = (max + min) / 2;        
   
	return 0;
}

/*	Precondition: Sensor's pin is assigned.
	Postcondition: Sensor takes its pins analog reading.
	Error: If Sensor's pin is unattached, returns 0. */

uint16_t Sensor::read() {
	
	if(this->pin == unattached)
		return 0;

	this->val = analogRead(this->pin);

	return this->val;
}

/*	Precondition: Sensor has been calibrated, and reading made.
	Postcondition: If Sensor's reading is above threshold, returns 1.
	Returns 0 otherwise. */

uint8_t Sensor::getBit() {
	if(this->val > this->threshold)
		return 1;
	return 0;
}

uint16_t Sensor::getVal() {
	return this->val;
}

uint16_t Sensor::getThreshold() {
	return this->val;
}

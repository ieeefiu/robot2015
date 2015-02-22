#include <stdint.h>
#include <Arduino.h>

#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
private:
	uint16_t threshold;		
	uint16_t val;

	uint8_t bit;
	uint8_t pin;
	uint8_t emitterPin;

public:
	Sensor();
	Sensor(uint8_t);
	Sensor(uint8_t, uint8_t);

	uint8_t attach(uint8_t);	
	uint8_t attach(uint8_t, uint8_t);
	uint8_t detach();

	uint8_t calibrate();
	uint16_t read();
	uint8_t readBit();
};

Sensor::Sensor() {
	this->threshold = 0;
	this->bit = 0;
	this->val = 0;
	this->pin = 0;
	this->emitterPin = 0;
}

Sensor::Sensor(uint8_t pin) {
	this->threshold = 0;
	this->bit = 0;
	this->val = 0;
	this->attach(pin);
}

Sensor::Sensor(uint8_t pin, uint8_t emitterPin) {
	this->threshold = 0;
	this->bit = 0;
	this->val = 0;
	this->attach(pin, emitterPin);
}


/*	If pin index is within range attaches Sensor variable
	is attached pin, and returns 1. Returns 0 otherwise
	and pin is set to 0.
	Emitter is defaulted to 0.
 */
uint8_t Sensor::attach(uint8_t  pin) {
	this->emitterPin = 0;

	// analogRead() can only be called on pins 14-19 (A0-A5).
	if(pin < 14 || pin > 19) {
		this->pin = 0;
		return 1;
	}

	this->pin = pin;

	return 0;	
}

uint8_t Sensor::attach(uint8_t pin, uint8_t emitterPin) {
	if(pin < 14 || pin > 19) {
		this->pin = 0;
		return 1;
	}

	/*	digitalWrite() can only be called on pins 0-19.
		avoids using Sensor pin as emitterPin		
	*/
	if(emitterPin < 0 || emitterPin > 19 || emitterPin == this->pin) {
		this->emitterPin = 0;
		return 1;
	}

	this->pin = pin;
	this->emitterPin = emitterPin;
	
	return 0;
}

uint8_t Sensor::detach() {
	this->pin = 0;
	this->emitterPin = 0;
}

/*	Maximum and minimum values of sensor is found.
	Readings are adjusting for ambient reflections,
	and used to obtain threshold.
	If calibrated returns true, else false.
 */

uint8_t Sensor::calibrate() {
	if(!this->pin)
		return 1;

	const uint8_t NUMCALIBS = 100;

	uint16_t max, min; 
	uint16_t vals[NUMCALIBS] = {};

	for(uint16_t i = 0; i < NUMCALIBS; i++) {
		vals[i] = this->read();
							
		// get boundary sensor values
		if(vals[i] > max || i < 1)
			max = vals[i];
		if(vals[i] < min || i < 1)
			min = vals[i];
		
		this->threshold = min + ((max - min) / 2);	
	}

	return 0;
}

/*	Reads analog value from the "sensor" IR emitter in ON state. 
	A second readings is taken with the IR emitters in OFF state. 
	This method of reading sensors reduces the effect of 
	ambient light. If the analog value for sensor is above its
	threshold, then a binary 1 is written. In all other case a binary
	0 is written.	
 */
uint16_t Sensor::read() {
	if(!this->pin)
		return this->val;

	if(!this->emitterPin) {
		this->val = analogRead(this->pin);
		return this->val;
	}

	uint16_t ambientVal = 0;

	// take reading with emitters on
	digitalWrite(this->emitterPin, HIGH);	
	this->val = analogRead(this->pin);

	// take another with emitters off
	digitalWrite(this->emitterPin, LOW);	
	ambientVal = analogRead(this->pin);

	// adjust reading for ambient reflections
	this->val -= ambientVal;	
	
	if(this->val > this->threshold)
		this->bit = 1;
	else
		this->bit = 0;

	return this->val;
}

/*	Returns bit representation of Sensor value.
	If the analog value for sensor is above its	threshold,
	then a binary 1 is written. In all other case a binary
	0 is written.	
	*/
uint8_t Sensor::readBit() {
	this->read();

	return this->bit;
}

#endif
#include <Arduino.h>
#include <Servo.h>
#include "Sensor.h"
#include "Follower.h"

const uint8_t emitterPin = 12;
const uint8_t ledPin = 13;

const uint8_t numSensors = 7;
const uint8_t sensorPins[numSensors] = {0, 1, 2, 3, 4, 5, 6};

Sensor sensors[numSensors];
uint8_t sensorBinary = B00000000;

const uint8_t rightServoPin = 10;
const uint8_t leftServoPin = 11;

Servo servos[2];

uint8_t error = 0;
String errorMessage;

void setup() {
  Serial.begin(9600);

	servos[right].attach(rightServoPin);
	servos[left].attach(leftServoPin);
	
	for(uint8_t pin = 0; pin < numSensors; pin++) {
		error =	sensors[pin].attach(sensorPins[pin], emitterPin);		
		if(error) {
			errorMessage = "Error: cannot attach Sensor pin:" + sensorPins[pin];
			break;
		}		

		error = sensors[pin].calibrate();
		if(error) {
			errorMessage = "Error: cannot calibrate Sensor pin:" + sensorPins[pin];
			break;
		}	
	}

	if(error)
		Serial.println(errorMessage);
}


void loop() {
	lineFollower(servos, sensors, numSensors);
}



#include <Arduino.h>
#include <stdint.h>
#include <Servo.h>
#include "Sensor.h"
#include "Follower.h"

const uint8_t ledPin = 13;
const uint8_t numSensors = 7;
const uint8_t numServos = 2;
const uint8_t sensorPins[numSensors] = {0, 1, 2, 3, 4, 5, 6};
const uint8_t rightServoPin = 10;
const uint8_t leftServoPin = 11;

Sensor sensors[numSensors];
Servo servos[numServos];

uint8_t error = 0;
String errorMessage = "Error: ";

void setup() {
  Serial.begin(9600);

	digitalWrite(ledPin, HIGH);

	servos[right].attach(rightServoPin);
	servos[left].attach(leftServoPin);
	
	for(uint8_t pin = 0; pin < numSensors; pin++) {
		error =	sensors[pin].attach(sensorPins[pin]);		
		if(error) {
			errorMessage += "cannot attach Sensor pin: " + sensorPins[pin];
			break;
		}		

		error = sensors[pin].calibrate();
		if(error) {
			errorMessage += "cannot calibrate Sensor pin: " + sensorPins[pin];
			break;
		}	
	}

	digitalWrite(ledPin, LOW);

	if(error)
		Serial.println(errorMessage);
}

void loop() {
	lineFollower(servos, sensors, numSensors);
}


#include <Arduino.h>
#include <stdint.h>
#include <Servo.h>
#include "Sensor.h"
#include "Follower.h"

const uint8_t ledPin = 13;
const uint8_t numSensors = 6;
const uint8_t numServos = 2;
const uint8_t sensorPins[numSensors] = {0, 1, 2, 3, 4, 5};
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
		digitalWrite(ledPin, HIGH);

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

		uint16_t threshold = sensors[pin].getThreshold();

		Serial.print("threshold ");
		Serial.print(pin);
		Serial.print(": ");
		Serial.println(threshold);

	}

	digitalWrite(ledPin, LOW);

	if(error)
		Serial.println(errorMessage);
}

void loop() {
	uint16_t sensorsAnalog = readSensorsAnalog(sensors, numSensors);
	uint8_t sensorsBinary = readSensorsBinary(sensors, numSensors);

	Serial.println(sensorsAnalog);
	Serial.println(sensorsBinary, BIN);

	lineFollower(servos, sensors, numSensors);

	delay(250);
}


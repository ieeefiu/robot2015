#ifndef sensors
#define sensors

#define NUMCALIBS	 	500
#define EMITTERPIN	2

#ifndef NUMSENSORS
#define	NUMSENSORS	6
#endif

class Sensors {
	private:
		uint16_t	readSensor(uint8_t sensor);
		
		uint16_t	threshold[NUMSENSORS];
		uint8_t		pins[NUMSENSORS];

	public:
		Sensors(uint8_t[]);

		void calibrate();
		void read();

		uint16_t 	vals[NUMSENSORS];
		uint8_t 	bits;
};

Sensors::Sensors(uint8_t pins[]) {
	this->pins = pins;
	this->threshold = {};
	this->vals = {};
	this->bits = B00000000;
}

/*	Maximum and minimum values of each sensor is found.
		Readings are adjusting for ambient reflections,
		and used to obtain individual thresholds.
 */
void Sensors::calibrate() {
	uint16_t	maxVals[NUMSENSORS] = {}, 
						minVals[NUMSENSORS]	= {}, 
						emitterVals[NUMCALIBS][NUMSENSORS] = {};

	for(uint16_t i = 0; i < NUMCALIBS; i++) {
		for(uint8_t j = 0; j < NUMSENSORS; j++) {
			emitterVals[i][j] = this->readSensor(this->pins[j]);
							
			// get boundary sensor values
			if(emitterVals[i][j] > maxVals[j] || j < 1)
				maxVals[j] = emitterVals[i][j];
			if(emitterVals[i][j] < minVals[j] || j < 1)
				minVals[j] = emitterVals[i][j];
		}
	}

	for(uint8_t i = 0; i < NUMSENSORS; i++)
		this->threshold[i] = minVals[i] 
					+ ((maxVals[i] - minVals[i]) / 2);	
}


/*	Reads analog values from sensors and converts them into binary.
 		If the analog value for a sensor is above its threshold, then 
 		a binary 1 is written. In all other case a binary 0 is written.
 */
void Sensors::read() {
	for(uint8_t i = 0; i < NUMSENSORS; i++) {
		this->vals[i] = this->readSensor(this->pins[i]);
		if(this->vals[i] > this->threshold[i])
			bitSet(this->bits, i);
	}	
}

/*	Reads analog value from the "sensor" IR emitter in ON state. 
		A second readings is taken with the IR emitters in OFF state. 
		The difference of the two values is stored in "emitterVal".
		This method of reading sensors reduces the effect of 
		ambient light.
 */
uint16_t Sensors::readSensor(uint8_t sensor) {
	uint16_t emitterVal, ambientVal;

	// take reading with emitters on
	digitalWrite(EMITTERPIN, HIGH);	
	emitterVal = analogRead(sensor);

	// take another with emitters off
	digitalWrite(EMITTERPIN, LOW);	
	ambientVal = analogRead(sensor);

	// adjust reading for ambient reflections
	emitterVal -= ambientVal;	

	return emitterVal;
}

#endif

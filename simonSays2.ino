#define ONESEC 1000

#define GREEN 1
#define RED 2
#define BLUE 3
#define YELLOW 4

#define NUMLEDS 4
#define NUMPHOTO 5
#define COUNT 1

const int leds[NUMLEDS] = {13, 12, 11, 10};
const int photoRes[NUMPHOTO] = {0, 1, 2, 3, 4};
int colors[100] = {};
int currPos = 0;

boolean run = TRUE;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < NUMLEDS; i++) {
    pinMode(leds[i], OUTPUT);
	}
}

void loop() {
	for(int i = 0; i < COUNT; i++) {
    record(currPos);
    delay(ONESEC);
    currPos++;
  }

  for(int i = 0; i < COUNT; i++) {
		switch(colors[i]) {
		case GREEN:
			flashLed(leds[0]); break;
		case RED:
			flashLed(leds[1]); break;
		case BLUE:
			flashLed(leds[2]); break;
		case YELLOW:
			flashLed(leds[3]); break;
	}

  currPos = 0;
}

void record(int currPos) {
	while(TRUE) {
	  Serial.print("1: ");
    Serial.println(analogRead(photoRes[0]));
    if (analogRead(photoRes[0]) >= 1000) {
      colorRead[currPos] = GREEN;
      break;
    }
    Serial.print("2: ");
    Serial.println(analogRead(photoRes[1]));    
    if (analogRead(photoRes[1]) >= 1000) {
      colorRead[currPos] = RED;
      break;
    }
    Serial.print("3: ");
    Serial.println(analogRead(photoRes[2]));
    if (analogRead(photoRes[2]) >= 1000) {
      colorRead[currPos] = GREEN;
      break;
    }
    Serial.print("4: ");
    Serial.println(analogRead(photoRes[3]));
    if (analogRead(photoRes[3]) >= 1000) {
      colorRead[currPos] = YELLOW;
      break;
    }
  }
}

void flashLed(const int led) {
	digitalWrite(led, HIGH);
	delay(1000);
	digitalWrite(led, LOW);
}

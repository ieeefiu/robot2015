#include <Arduino.h>
#include <Servo.h>
#include "Simon.h"

Simon::Simon()
{}

Simon::Simon(uint8_t servos[6], uint8_t sensors[4])
{
    // set pin values for servos
    // in order of appearance:
    // 0 r 1 g 2 y 3 b 4 c 5 a
    red_servo = new Servo();
    green_servo = new Servo();
    yellow_servo = new Servo();
    blue_servo = new Servo();
    center = new Servo();
    arm = new Servo;
    red_servo->attach(servos[0]);
    green_servo->attach(servos[1]);
    yellow_servo->attach(servos[2]);
    blue_servo->attach(servos[3]);
    center->attach(servos[4]);
    arm->attach(servos[5]);
    // set pin values for sensors
    // in order of appearance:
    // 0 r 1 g 2 y 3 b
    red = sensors[0];
    green = sensors[1];
    yellow = sensors[2];
    blue = sensors[3];
    // initial position
    position = 0;
}

void Simon::init()
{
    red_servo->writeMicroseconds(UP);
    green_servo->writeMicroseconds(UP);
    yellow_servo->writeMicroseconds(UP);
    blue_servo->writeMicroseconds(UP);
    center->writeMicroseconds(UP);
}

int Simon::ave(int a, int b, int c)
{
    return ((analogRead(a) + analogRead(b) + analogRead(c)) / 3) + 150;
}

void Simon::record(int pos)
{
    while(1) {
	Serial.print("1: ");
	Serial.println(analogRead(red));
	if (analogRead(red) >= ave(green, yellow, blue)) {
	    colors[pos] = RED;
	    break;
	}
	Serial.print("2: ");
	Serial.println(analogRead(green));
	if (analogRead(green) >= ave(red, yellow, blue)) {
	    colors[pos] = GREEN;
	    break;
	}
	Serial.print("3: ");
	Serial.println(analogRead(yellow));
	if (analogRead(yellow) >= ave(red, green, blue)) {
	    colors[pos] = YELLOW;
	    break;
	}
	Serial.print("4: ");
	Serial.println(analogRead(blue));
	if (analogRead(blue) >= ave(red, green, yellow)) {
	    colors[pos] = BLUE;
	    break;
	}
    }
}

void Simon::run()
{
    int i = 0;
    while(true) {
	for (i = 0; i < count; i++) {
	    record(position);
	    delay(1000);
	    position++;
	}
	for (i = 0; i < count; i++) {
	    if (colors[i]==RED){
		red_servo->writeMicroseconds(PRESS);
		delay(1000);
		red_servo->writeMicroseconds(UP);
	    }
	    if (colors[i]==GREEN){
		green_servo->writeMicroseconds(PRESS);
		delay(1000);
		green_servo->writeMicroseconds(UP);
	    }
	    if (colors[i]==YELLOW){
		yellow_servo->writeMicroseconds(PRESS);
		delay(1000);
		yellow_servo->writeMicroseconds(UP);
	    }
	    if (colors[i]==BLUE){
		blue_servo->writeMicroseconds(PRESS);
		delay(1000);
		blue_servo->writeMicroseconds(UP);
	    }
	}

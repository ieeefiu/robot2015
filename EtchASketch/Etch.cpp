#include <Arduino.h>
#include <Servo.h>
#include "Etch.h"

Etch::Etch()
{
}


Etch::Etch(int a, int b, uint8_t x, uint8_t y)
{
    // set pin values for servos
    left_knob = new Servo();
    right_knob = new Servo();
    left_knob->attach(a);
    right_knob->attach(b);
    // set initial position
    pos_x = x;
    pos_y = y;
    // set servos to whatever value works for not moving
    // it's supposed to be 90 but i'm using cheap servos
    // please adjust this to whatever your servos are happy with
    Serial.println("Etch init");
}

void Etch::attach(int a, int b)
{
    left_knob->attach(a);
    right_knob->attach(b);
    stop();
}

void Etch::setPosition(uint8_t a, uint8_t b)
{
    pos_x = a;
    pos_y = b;
}

void Etch::moveForward(uint8_t a)
{
    // tell left knob to move forward
    left_knob->writeMicroseconds(CLOCKWISE);
    Serial.println("Left knob CLOCKWISE");
    Serial.println(left_knob->read());
    // let the thing move forward for whatever unit delay() takes
    delay(DELAY * a);
    // stop the left knob
    left_knob->writeMicroseconds(STOP);
    Serial.println("Left knob STOP");
    Serial.println(left_knob->read());
}

void Etch::moveBackward(uint8_t a)
{
    // tell left knob to move backward
    left_knob->writeMicroseconds(COUNTER_CLOCKWISE);
    Serial.println("Left knob COUNTER_CLOCKWISE");
    Serial.println(left_knob->read());
    // let the thing move forward for whatever unit delay() takes
    delay(DELAY * a);
    // stop the left knob
    left_knob->writeMicroseconds(STOP);
    Serial.println("Left knob STOP");
    Serial.println(left_knob->read());
}

void Etch::moveUp(uint8_t a)
{
    // tell right knob to move up
    right_knob->writeMicroseconds(CLOCKWISE);
    Serial.println("Right knob CLOCKWISE");
    Serial.println(right_knob->read());
    // let the thing move forward for whatever unit delay() takes
    delay(DELAY * a);
    // stop the right knob
    right_knob->writeMicroseconds(STOP);
    Serial.println("right knob STOP");
    Serial.println(right_knob->read());
}

void Etch::moveDown(uint8_t a)
{
    // tell right knob to move backward
    right_knob->writeMicroseconds(COUNTER_CLOCKWISE);
    Serial.println("Right knob COUNTER_CLOCKWISE");
    Serial.println(right_knob->read());
    // let the thing move forward for whatever unit delay() takes
    delay(DELAY * a);
    // stop the left knob
    right_knob->writeMicroseconds(STOP);
    Serial.println("Right knob STOP");
    Serial.println(right_knob->read());
}

int Etch::getX()
{
    return pos_x;
}

int Etch::getY()
{
    return pos_y;
}

void Etch::forward(uint8_t a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveForward(a);
}

void Etch::backward(uint8_t a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveBackward(a);
}

void Etch::up(uint8_t a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveUp(a);
}

void Etch::down(uint8_t a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveDown(a);
}

void Etch::stop()
{
    Serial.println("Stopping both knobs");
    left_knob->writeMicroseconds(STOP);
    Serial.println("Left knob STOP");
    Serial.println(left_knob->read());
    right_knob->writeMicroseconds(STOP);
    Serial.println("Right knob STOP");
    Serial.println(right_knob->read());
}

#include <Arduino.h>
#include <Servo.h>
#include "Etch.h"

Etch::Etch(int a, int b, int x, int y)
{
    // set pin values for servos
    left_knob.attach(a);
    right_knob.attach(b);
    // set initial position
    pos_x = x;
    pos_y = y;
    // set servos to whatever value works for not moving
    // it's supposed to be 90 but i'm using cheap servos
    // please adjust this to whatever your servos are happy with
    left_knob.writeMicroseconds(STOP);
    right_knob.writeMicroseconds(STOP);
}

void Etch::moveForward(int a)
{
    // tell left knob to move forward
    left_knob.write(CLOCKWISE);
    // let the thing move forward for whatever unit delay() takes
    int t = DELAYCONSTANT * a;
    delay(t);
    // stop the left knob
    left_knob.writeMicroseconds(STOP);
}

void Etch::moveBackward(int a)
{
    // tell left knob to move backward
    left_knob.write(COUNTER_CLOCKWISE);
    // let the thing move forward for whatever unit delay() takes
    int t = DELAYCONSTANT * a;
    delay(t);
    // stop the left knob
    left_knob.writeMicroseconds(STOP);
}

void Etch::moveUp(int a)
{
    // tell right knob to move up
    right_knob.write(COUNTER_CLOCKWISE);
    // let the thing move forward for whatever unit delay() takes
    int t = DELAYCONSTANT * a;
    delay(t);
    // stop the right knob
    right_knob.writeMicroseconds(STOP);
}

void Etch::moveDown(int a)
{
    // tell right knob to move down
    right_knob.write(CLOCKWISE);
    // let the thing move forward for whatever unit delay() takes
    int t = DELAYCONSTANT * a;
    delay(t);
    // stop the right knob
    right_knob.writeMicroseconds(STOP);
}

int Etch::getX()
{
    return pos_x;
}

int Etch::getY()
{
    return pos_y;
}

void Etch::forward(int a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveForward(a);
}

void Etch::backward(int a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveBackward(a);
}

void Etch::up(int a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveUp(a);
}

void Etch::down(int a)
{
    // takes a number in millimeters
    // will need to adjust for whatever your servo is happy with
    // TODO: have this check to see if it's going to move past the boundaries
    moveDown(a);
}

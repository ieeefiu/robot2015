#ifndef Etch_h
#define Etch_h

#include <Arduino.h>
#include <Servo.h>

class Etch
{
private:
    // constants for moving clockwise, counter-clockwise, and stop
    // will need to adjust for whatever your servo is
    // i don't know what this should be for the servo i'm using yet
    // please adjust this!
    // this value will be multiplied by a variable to provide a delay
    // that will keep the servo running for whatever distance
    static const uint16_t CLOCKWISE = 2000;
    static const uint16_t COUNTER_CLOCKWISE = 1000;
    static const uint16_t STOP = 1500;
    static const uint16_t DELAY = 50;
    Servo left_knob;
    Servo right_knob;
    unsigned int pos_x;
    unsigned int pos_y;
    void moveForward(int);
    void moveBackward(int);
    void moveUp(int);
    void moveDown(int);
    int getX();
    int getY();
public:
    Etch();
    Etch(int,int,int,int);
    void forward(int);
    void backward(int);
    void up(int);
    void down(int);
    void stop();
};

#endif

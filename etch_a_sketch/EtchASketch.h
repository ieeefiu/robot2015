#ifndef EtchASketch_h
#define EtchASketch_h

#include <Arduino.h>
#include <Servo.h>

// constants for moving clockwise, counter-clockwise, and stop
// will need to adjust for whatever your servo is

#define CLOCKWISE 180
#define COUNTER_CLOCKWISE 0
#define STOP 100
// i don't know what this should be for the servo i'm using yet
// please adjust this!
// this value will be multiplied by a variable to provide a delay
// that will keep the servo running for whatever distance
#define DELAYCONSTANT 5

class EtchASketch
{
private:
    Servo left_knob;
    Servo right_knob;
    int position[2];
    void moveForward(int);
    void moveBackward(int);
    void moveUp(int);
    void moveDown(int);
public:
    EtchASketch(int,int,int,int);
    void forward(int);
    void backward(int);
    void up(int);
    void down(int);
};

#endif

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
    static const uint16_t CLOCKWISE = 1000;
    static const uint16_t COUNTER_CLOCKWISE = 2000;
    static const uint16_t STOP = 1500;
    static const uint16_t DELAY = 100;
    Servo* left_knob;
    Servo* right_knob;
    unsigned int pos_x;
    unsigned int pos_y;
    void moveForward(uint8_t);
    void moveBackward(uint8_t);
    void moveUp(uint8_t);
    void moveDown(uint8_t);
    int getX();
    int getY();
public:
    Etch();
    Etch(int,int,uint8_t,uint8_t);
    void attach(int,int);
    void setPosition(uint8_t,uint8_t);
    void forward(uint8_t);
    void backward(uint8_t);
    void up(uint8_t);
    void down(uint8_t);
    void stop();
};

#endif

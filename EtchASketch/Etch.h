#ifndef Etch_h
#define Etch_h

#include <Arduino.h>
#include <Servo.h>

class Etch
{
private:
    // constants for moving clockwise, counter-clockwise, and stop
    // will need to adjust for whatever your servo is
    // please adjust these!
    static const uint16_t CLOCKWISE = 1300;
    static const uint16_t COUNTER_CLOCKWISE = 1700;
    static const uint16_t STOP = 1500;
    // this value will be multiplied by a variable to provide a delay
    // so the thing moves in mm (or at least that's my goal)
    static const uint16_t DELAY = 120;
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
    void forward(uint8_t);
    void backward(uint8_t);
    void up(uint8_t);
    void down(uint8_t);
    void stop();
};

#endif

#ifndef Rubiks_h
#define Rubiks_h

#include <Arduino.h>
#include <Servo.h>

class Rubiks
{
private:
    // servos
    Servo* arm;
    Servo* cube;

public:
    Rubiks();
    Rubiks(uint8_t,uint8_t);
    void turn();
    void down();
    void up();
};

#endif

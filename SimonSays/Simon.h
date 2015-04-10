#ifndef Simon_h
#define Simon_h

#include <Arduino.h>
#include <Servo.h>

class Simon
{
private:
    // constants for button presses
    // holy shit will i adjust the fuck out of these
    static const uint16_t UP = 1500;
    static const uint16_t PRESS = 1200;
    // constants for color values
    static const uint8_t RED = 1;
    static const uint8_t GREEN = 2;
    static const uint8_t YELLOW = 3;
    static const uint8_t BLUE = 4;
    // servos for simon
    Servo* red_servo;
    Servo* green_servo;
    Servo* yellow_servo;
    Servo* blue_servo;
    Servo* center;
    Servo* arm;
    // sensors
    uint8_t red;
    uint8_t green;
    uint8_t yellow;
    uint8_t blue;
    // other junk
    int colors[100];
    int position;
    // average the values
    int ave(int,int,int);
public:
    Simon();
    Simon(uint8_t[6],uint8_t[4]);
    void init();
    void record(int);
    void run();
};

#endif

#include <Servo.h>
#include "Etch.h"

// test sketch for Etch class. pay attention to the serial monitor
// to make sure the thing is doing what it's supposed to

// make a new etch-a-sketch
Etch* etch;

void setup()
{
    // assign etch-a-sketch to pins A0 and A1 at initial position 0,0
    etch = new Etch(A0,A1,0,0);
}

void loop()
{
    // test out the etch-a-sketch class
    etch->forward(10);
    delay(1000);
    etch->backward(10);
    delay(1000);
    etch->up(10);
    delay(1000);
    etch->down(10);
    delay(1000);
    // test the stop method
    etch->stop();
    delay(1000);
}

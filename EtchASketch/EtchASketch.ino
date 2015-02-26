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
    delay(5000);
    // start I
    etch->forward(6);
    delay(500);
    etch->backward(3);
    delay(500);
    etch->down(6);
    delay(500);
    etch->backward(3);
    delay(500);
    etch->forward(9);
    // start e1
    delay(500);
    etch->up(3);
    delay(500);
    etch->backward(3);
    delay(500);
    etch->down(9);
    delay(500);
    // start e2
    etch->forward(6);
    delay(500);
    etch->up(3);
    delay(500);
    etch->backward(3);
    delay(500);
    etch->down(9);
    delay(500);
    // start e3
    etch->forward(6);
    delay(500);
    etch->up(3);
    delay(500);
    etch->backward(3);
    delay(500);
    etch->down(9);
    delay(500);
    etch->forward(3);
    delay(500);
    etch->up(3);
    delay(5000);
}

#include <Servo.h>
#include "Etch.h"

// make a new etch-a-sketch with pins at 38 and 39 and position 0, 0
Etch* etch = new Etch(38,39,0,0);

void setup()
{
    etch->stop();
}

void loop()
{
    // test out the etch-a-sketch class
    /* etch->forward(10); */
    /* delay(1000); */
    /* etch->backward(10); */
    /* delay(1000); */
    /* etch->up(10); */
    /* delay(1000); */
    /* etch->down(10); */
    /* delay(1000); */
}

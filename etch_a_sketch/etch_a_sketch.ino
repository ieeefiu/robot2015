#include <Servo.h>
#include "EtchASketch.h"

EtchASketch etch(38, 39);

void setup()
{
    
}

void loop()
{
    // test out the etch-a-sketch class
    etch.forward(10);
    etch.backward(10);
    etch.up(10);
    etch.down(10);
}

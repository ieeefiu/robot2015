#include <Arduino.h>
#include <Servo.h>
#include "Rubiks.h"

Rubiks::Rubiks()
{}

Rubiks::Rubiks(uint8_t a, uint8_t b)
{
    // set pin values for servos
    arm = new Servo();
    cube = new Servo();
    arm->attach(a);
    cube->attach(b);
    arm->writeMicroseconds(STOP);
    cube->writeMicroseconds(STOP);
}

void Rubiks::turn()
{
    cube->writeMicroseconds(1800);
    delay(2000);
    cube->writeMicroseconds(STOP);
}

void Rubiks::down()
{
    arm->writeMicroseconds(1800);
    delay(3000);
    arm->writeMicroseconds(STOP);
}

void Rubiks::up()
{
    arm->writeMicroseconds(1200);
    delay(3000);
    arm->writeMicroseconds(STOP);
}

#include <Servo.h>


Servo left_knob;
// Servo right_knob;
int position = 0;

void setup()
{
    left_knob.attach(A0);
    // right_knob.attach(A1);
}

void loop()
{
    for(pos = 0; pos < 180; pos++) {
	left_knob.write(pos);
	delay(15);
    }

    for(pos = 180; pos >= 1; pos--) {
	left_knob.write(pos);
	delay(15);
    }
}

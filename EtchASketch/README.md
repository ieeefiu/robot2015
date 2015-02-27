etch-a-sketch
=============

a class for an etch-a-sketch

what is an etch-a-sketch?
-------------------------

an etch-a-sketch is defined by three things:
- a left knob
- a right knob
- initial position

some notes
----------

- knobs are continuous motion servos
- the constants in Etch.h work well with the AR-3606HB servos
- delay constant is currently arbitrary, will need to test on an etch-a-sketch soon
- before using this, test and modify the constants to work properly with whatever servos you are actually using
- open the serial monitor and make sure the servos are doing the right thing at the right time

how do i
--------

EtchASketch has four fields:
- pin for left knob
- pin for right knob
- x position
- y position

Public methods:
- Etch: empty constructor
- Etch with arguments: constructor that sets pins and initial position
- forward, backward, up, down: moves the cursor in whatever direction. measured in mm. will eventually check position and not work if the thing is going to go out of bounds
- stop: stops both knobs

to-do list
----------

- add methods to set and get current position
- figure out what to set the DELAY constant to so the argument moves the thing in mm
- add a check to see if the cursor is going to move out of bounds
- actually make this thing work on an etch-a-sketch

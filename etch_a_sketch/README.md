* etch-a-sketch

a class for an etch-a-sketch

** what is an etch-a-sketch?

an etch-a-sketch is defined by three things:
- a left knob
- a right knob
- initial position

** some notes

- knobs are continuous motion servos
- the constants in EtchASketch.h are defined for the servos i have at home, which are [these](http://www.amazon.com/gp/product/B00KA393PK/ref=oh_aui_detailpage_o00_s00) modified to be continuous motion. they're cheap so the numbers might be off
- before using this, test and modify the constants to work properly with whatever servos you are actually using

** how do i

EtchASketch has four fields:
- pin for left knob
- pin for right knob
- x position
- y position

Public methods:
- forward, backward, up, down: moves the cursor in whatever direction. measured in mm. *TODO* add a check to see if the cursor is going to move out of bounds

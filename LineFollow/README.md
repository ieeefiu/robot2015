# Follower

## Usage

* Follow line using IR sensors. Identifies and turns into left and right junctions; otherwise, follows line using PD control.
* Is defined assuming a line array of 6 sensors and 1 sensor.
* 8 bit number used to represent sensors where the nth bit is the nth sensor *counting from the right. e.g. B000101010 - odd numbered sensors on.*

## Methods

### `readSensorsBinary()`
Returns 8 (`uint8_t`) bit representation of `sensors`
* `readSensorsBinary(sensors, numSensors)`

### `readSensorsAnalog()`
Returns the sum of analog values in `sensors`
* `readSensorsAnalog(sensors, numSensors)`

### `setServos()`
Sets the speed and `direction` of `servos` with PD offset.
* `setServos(servos, direction, offset)`

### `lineFollower()`
Main line follower function called by robot
* `lineFollower(servos, sensors, numSensors)`

# Sensor

## Usage

* Calibrate and read general sensors with the Arduino.
* Assumes sensor is connected to Arduino analog pins. *For now, assumes sensor is initialized with channel numbers (0-5  on the UNO, 0-15 MEGA)*

## Members

### `uint16_t threshold`
Analog readings below this value are considered noise.
### `uint16_t val`
Analog reading from sensor.
### `uint8_t pin`
Analog pin on Arduino that sensor is mapped to.

## Methods

### Sensor() 
Constructor
* `Sensor()`
* `Sensor(pin)`

### `attach()`
Associates sensors pin with Arduino pin.
* `attach(pin)`

### `detach()`
Unlinks sensor from arduino pin.
* `detach()`

### `calibrate()`
Sensors threshold value is calculated to adjust for ambient noise.
* `calibrate()`

### `read()`
Uses `analogRead()` to get sensor values, returns `val` of type `uint16_t`.
* `read()`

### `getBit()`
If `val` read is above `threshold` returns 1, else 0 of type `uint8_t`.
* `getBit()`

### `getThreshold()`
Returns `uint16_t threshold`
* `getThreshold()`

### `getVal()`
Returns `uint16_t val`
* `getVal()`

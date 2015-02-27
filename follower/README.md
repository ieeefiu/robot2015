# Follower

## Usage

* Follow line using IR sensors. Identifies and turns into left and right junctions; otherwise, follows line using PD control.
* Is defined assuming a line array of 6 sensors and 1 sensor.
* 8 bit number used to represent sensors where the nth bit is the nth sensor *counting from the right. e.g. B000101010 - odd numbered sensors on.*

## Methods

### `readSensorsBinary()`
* `readSensorsBinary(sensors, numSensors)`
Returns 8 (`uint8_t`) bit representation of `sensors`

### `readSensorsAnalog()`
* `readSensorsAnalog(sensors, numSensors)`
Returns the sum of analog values in `sensors`

### `setServos()`
* `setServos(servos, direction, offset)`
Sets the speed and `direction` of `servos` with PD offset.

### `lineFollower()`
* `lineFollower(servos, sensors, numSensors)`
Main line follower function called by robot

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

### Sensor() *Constructor*
* `Sensor()`
* `Sensor(pin)`

### `attach()`
Associates sensors pin with Arduino pin.
* `attach(pin)`

### `detach()`
Unlinks sensor from arduino pin.

### `calibrate()`
Sensors threshold value is calculated to adjust for ambient noise.

### `read()`
Uses `analogRead()` to get sensor values, returns `val` of type `uint16_t`.

### `getBit()`
If `val` read is above `threshold` returns 1, else 0 of type `uint8_t`.

### `getThreshold()`
Returns `uint16_t threshold`

### `getVal()`
Returns `uint16_t val`

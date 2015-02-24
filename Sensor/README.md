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
### `uint8_t emitterPin`
Digital pin on Arduino that turns emitter associated with sensor on/off. 

## Methods

### Sensor() *Constructor*
* `Sensor()`
* `Sensor(pin)`
* `Sensor(pin, emitterPin)`

### `attach()`
* `attach(pin)`
* `attach(pin, emitterPin)`

### `detach()`
Unlinks sensor from arduino pins.

### `calibrate()`
Sensors threshold value is calculated to adjust for ambient noise.

### `read()`
Uses `analogRead()` to get sensor values, returns `val` of type `uint16_t`.

### `getBit()`
If `val` read is above `threshold` returns 1, else 0 of type `uint8_t`.

### `getThreshold()`

### `getVal()`

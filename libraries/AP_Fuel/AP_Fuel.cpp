#include <AP_HAL/AP_HAL.h>

#define ARDUINO_I2C_ADDR 42  //0x2A

#define ARDUINO_I2C_BUS 1


// probe and initialise the sensor
bool AP_Fuel::init()
{
    //NOTE we use the exact same template from AP_Airspeed_I2C
    //TODO test the init and read code. Forget everything else.

    _dev = hal.i2c_mgr->get_device(ARDUINO_I2C_BUS, ARDUINO_I2C_ADDR);

    // take i2c bus semaphore
    if (!_dev || !_dev->get_semaphore()->take(200)) {
	return false;
    }

    
}

void read() 
{
    //NOTE created simple i2c transfer which will store data in
    //     variable resistor.
    //TODO find a way to test the read() function.
    
    uint8_t data[2];

    _measurement_started_ms = 0;

    if (!_dev->transfer(nullptr, 0, data, sizeof(data))) {
	return;
    }

    int16_t resistor;
    resistor = (data[0] << 8) + data[1];
    _current_data = resistor;
}


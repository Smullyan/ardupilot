#include "AP_Fuel.h"


#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/I2CDevice.h>
#include <AP_Math/AP_Math.h>
#include <GCS_MAVLink/GCS.h>
#include <utility>


extern const AP_HAL::HAL &hal;

#define ARDUINO_I2C_ADDR 42  //0x2A

#define ARDUINO_I2C_BUS 1

// Constructor
AP_Fuel::AP_Fuel(){}

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
    
    return false;
}

void AP_Fuel::read(void) 
{
    //NOTE created simple i2c transfer which will store data in
    //     variable resistor.
    //TODO find a way to test the read() function.
    
    uint8_t data[2];


    if (!_dev->transfer(nullptr, 0, data, sizeof(data))) {
	return;
    }

    int16_t resistor;
    resistor = (data[0] << 8) + data[1];
    _current_data = resistor;
}


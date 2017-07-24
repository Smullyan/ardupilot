#include "AP_Fuel.h"


#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/I2CDevice.h>
#include <AP_Math/AP_Math.h>
#include <GCS_MAVLink/GCS.h>
#include <utility>
#include <stdio.h>

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

    //_dev->register_periodic_callback(50000,
    //				     FUNCTOR_BIND_MEMBER()
    
    return false;
}

void AP_Fuel::read_resistor(void) 
{
    //NOTE created simple i2c transfer which will store data in
    //     variable resistor.
    //DONE find a way to test the read() function.
    //TODO find a way to read multiple registers from the same device
    
    uint8_t data[1];

    uint8_t cmd2 = 2;  // 2 is enumerated to send A0 in range 0 to 100
    
    if (!_dev->transfer(&cmd2, 1, nullptr, 0)) {
	return;
    }
    
    // read 1 byte of data from arduino
    if (!_dev->transfer(nullptr, 0, data, sizeof(data))) {
    	return;
    }

    int8_t resistor;
    resistor = (data[0]);
    _resistor_data = resistor;

    
    hal.console->println("Testing yo!");
}


void AP_Fuel::read_id(void) 
{
    //NOTE created simple i2c transfer which will store data in
    //     variable resistor.
    //DONE find a way to test the read() function.
    //TODO find a way to read multiple registers from the same device
    
    uint8_t data[1];

    uint8_t cmd1 = 1;  // 1 is enumerated to send 0x55
    
    if (!_dev->transfer(&cmd1, 1, nullptr, 0)) {
	return;
    }
    
    // read 1 byte of data from arduino
    if (!_dev->transfer(nullptr, 0, data, sizeof(data))) {
    	return;
    }

    int8_t id;
    id = (data[0]);
    _id_data = id;

    
    hal.console->println("Testing 2 yo!");
}

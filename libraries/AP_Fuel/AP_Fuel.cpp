#include "AP_Fuel.h"

// NOTE I don't think we need all these libraries

#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/I2CDevice.h>
#include <AP_Math/AP_Math.h>
#include <GCS_MAVLink/GCS.h>
#include <utility>
#include <stdio.h>

extern const AP_HAL::HAL &hal;

#define ARDUINO_I2C_ADDR 42  //0x2A, this is the set slave address on the Arduino

#define ARDUINO_I2C_BUS 1

// Constructor
AP_Fuel::AP_Fuel(){}

// probe and initialise the sensor
bool AP_Fuel::init()
{
    //NOTE we use the exact same template from AP_Airspeed_I2C
    //DONE test the init and read code. Forget everything else.

    _dev = hal.i2c_mgr->get_device(ARDUINO_I2C_BUS, ARDUINO_I2C_ADDR);

    return false;
}

void AP_Fuel::read_resistor(void) 
{
    // NOTE created simple i2c transfer which will store data in
    //      variable resistor.
    // DONE find a way to test the read() function.
    // DONE find a way to read multiple registers from the same device

    // TODO I still think that there's something wrong with the threading.
    //      There's no use of semaphores etc. I suggest reading the section
    //      on threading in the ardupilot dev website. We'll need to be familiar
    //      with the nsh console to debug this problem.


    uint8_t data[1];

    uint8_t cmd2 = 2;  // 2 is a command value to send A0 value in range 0 to 100
    
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

    // This is for the example sketch
    // hal.console->println("Testing yo!");
}


void AP_Fuel::read_id(void) 
{
    //NOTE created simple i2c transfer which will store data in
    //     variable resistor.
    //DONE find a way to test the read() function.
    //DONE find a way to read multiple registers from the same device

    //_measurement_started_ms = 0;
    
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

   
    // This is for the example sketch
    // hal.console->println("Testing 2 yo!");
}

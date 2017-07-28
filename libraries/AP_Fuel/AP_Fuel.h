#pragma once

// NOTE I don't think we need all these libraries.

#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_Param/AP_Param.h>
#include <AP_Vehicle/AP_Vehicle.h>
#include <GCS_MAVLink/GCS_MAVLink.h>


class AP_Fuel
{
public:

    /// Constructor
    AP_Fuel();

    // DONEish: once you've finished creating the basic
    // frontend, create the backend driver
    
    // TODO technically, this IS the backend (in addition to the calls below
    // being the frontend). The backend will be necessary to write if we have
    // multiple fuel tanks or multiple methods to communicate to the fuel tanks.
    // Here, we simply communicate using Arduino's I2C method.

    // Initialise
    bool init(void);

    // Read the data sent from the arduino
    // TODO might want to consider adding additional parameters
    // where we extend the arduino send routine by filling the twi
    // data register and sending the data with multiple variables.
    void read_resistor(void);

    void read_id(void);
    
    // return the current data
    int8_t get_resistor(void) const {
	return _resistor_data;
    }

    // return the id data
    int8_t get_id(void) const {
	return _id_data;
    }
    
    
private:
    int8_t          _resistor_data;
    int8_t          _id_data;
    AP_HAL::OwnPtr<AP_HAL::I2CDevice> _dev;
};

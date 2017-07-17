#pragma once

class AP_Fuel
{
public:

    /// Constructor
    AP_Fuel();

    // TODO: once you've finished creating the basic
    // frontend, create the backend driver

    // Initialise
    void init(void);

    // Read the data sent from the arduino
    // TODO might want to consider adding additional parameters
    // where we extend the arduino send routine by filling the twi
    // data register and sending the data with multiple variables.
    void read();

    
    // return the current data
    int16_t get_data(void) const {
	return _current_data;
    }

private:
    int16_t          _current_data;

}

/*
 *   Fuel.cpp - fuel example sketch
 *
 */

#include <AP_ADC/AP_ADC.h>
#include <AP_Fuel/AP_Fuel.h>
#include <AP_HAL/AP_HAL.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

// TODO double check what the variable type is for
// the fuel

AP_Fuel fuel; // the AP_Fuel object

void setup()
{
    hal.scheduler->delay(10000);
    hal.console->println("At least something works...");
    fuel.init();
    // NOTE add AP_Param?

    }

void loop(void)
{
    fuel.read_id();
    int data1 = fuel.get_id();
    fuel.read_resistor();
    int data2 = fuel.get_resistor();

    hal.console->println(data1);
    hal.console->println(data2);
    
    hal.scheduler->delay(1000);
}

AP_HAL_MAIN();

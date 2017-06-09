#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_Param/AP_Param.h>

#define MY_NEW_PARAM_DEFAULT    100

class AP_Arduino
{
public:
    // constructor
    AP_Arduino();

    //settable parameters
    static const struct AP_Param::GroupInfo var_info[];

protected:
    AP_Int16 _my_new_lib_parameter;
};

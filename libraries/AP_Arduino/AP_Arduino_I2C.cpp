#include "AP_Arduino_I2C.h"

const AP_Param::GroupInfo AP_Arduino_I2C::var_info[] = {
    // @Param: MY_NEW_P
    // @DisplayName: My New Library Parameter
    // @Description: The new library parameter description goes here
    // @Range: -32768 32767
    // @User: Advanced
    AP_GROUPINFO("MY_NEW_P", 0, Fuel, _my_new_lib_parameter, MY_NEW_PARAM_DEFAULT),

    AP_GROUPDEND
};

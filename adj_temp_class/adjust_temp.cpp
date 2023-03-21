
#include "adjust_temp.h"

#include <iostream>

int adjust_temp::read_sensor_and_act(const float current_temp) {
    std::cout << "current room temperature is " << current_temp << '\t';
    if(current_temp <= min_temp)
        return increase_temp();
    else if(current_temp >= max_temp)
        return decrease_temp();
    else {
        std::cout << "Room temperature is ok" << std::endl;
        return 0; // no action needed
    }
}

int adjust_temp::decrease_temp() {
    std::cout << "Start cooling ..." << std::endl;
    return -1;
}

int adjust_temp::increase_temp() {
    std::cout << "Start heating ..." << std::endl;
    return 1;
}
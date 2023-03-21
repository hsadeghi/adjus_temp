#include <iostream>
#include "../adj_temp_class/adjust_temp.h"
#include <vector>

int main() {
    adjust_temp controller(0, 30);
    std::vector<float> sample_temp {5, -3.5, 10.2, 15, 35, -8};

    for(const auto& tmp : sample_temp){
        controller.read_sensor_and_act(tmp);
    }
    return 0;
}

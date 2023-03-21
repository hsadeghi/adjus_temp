#include <iostream>
#include "../adj_temp_class/adjust_temp.h"
#include <vector>

int main() {
    adjust_temp controller(0, 30);
    std::vector<int> sample_temp {5, -3, 10, 15, 35, -8};

    for(const auto& tmp : sample_temp){
        controller.read_sensor_and_act(tmp);
    }
    return 0;
}

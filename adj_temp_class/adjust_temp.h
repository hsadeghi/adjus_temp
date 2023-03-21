
#ifndef ADJUST_ROOM_TEMP_ADJUST_TEMP_H
#define ADJUST_ROOM_TEMP_ADJUST_TEMP_H


class base_adj_temp {
public:
    virtual ~base_adj_temp() = default;
    virtual int read_sensor_and_act(float current_temp) = 0;
    virtual int increase_temp() = 0;
    virtual int decrease_temp() = 0;
};

class adjust_temp:base_adj_temp {
public:
    // constructor
    explicit adjust_temp(float min_temp=0, float max_temp=30): min_temp(min_temp), max_temp(max_temp){}
    ~adjust_temp() override = default;

    // reads sensor data and acts if needed, return value 0 means no action, 1 indicates heating and -1 indicates cooling
    int read_sensor_and_act(float current_temp) override;
    int increase_temp() override; // returns 1 which indicates heating
    int decrease_temp() override; // returns -1 which indicates cooling

    void set_min_temp(float new_min) {min_temp = new_min;}
    void set_max_temp(float new_max) {max_temp = new_max;}
    [[nodiscard]] float get_min_temp() const {return min_temp;}
    [[nodiscard]] float get_max_temp() const {return max_temp;}

private:
    float min_temp;
    float max_temp;
};

//class Mock
#endif //ADJUST_ROOM_TEMP_ADJUST_TEMP_H

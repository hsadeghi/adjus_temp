#include <adjust_temp.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::AtLeast;
using testing::Return;

class TestCalls{
    base_adj_temp& base_obj;
public:
    explicit TestCalls(base_adj_temp& b_obj): base_obj(b_obj) {}
    int call_read_act(float  current_tmp){ return base_obj.read_sensor_and_act(current_tmp);}
    int call_inc_temp() { return base_obj.increase_temp(); }
    int call_dec_temp() { return base_obj.decrease_temp(); }
};
class MockAdjTemp:  public base_adj_temp {
public:
    MOCK_METHOD(int, read_sensor_and_act, (float current_temp), (override));
    MOCK_METHOD(int, increase_temp,(), (override));
    MOCK_METHOD(int, decrease_temp,(), (override));
};

TEST(adjTempTest, call_inc_temp){
    MockAdjTemp mock_adj_temp;
    TestCalls test_calls(mock_adj_temp);
    EXPECT_CALL(mock_adj_temp, increase_temp())
            .Times(1)
            .WillOnce(Return(1));

    auto ret_val = test_calls.call_inc_temp();
    EXPECT_EQ(1, ret_val);
}

TEST(adjTempTest, call_dec_temp){
    MockAdjTemp mock_adj_temp;
    TestCalls test_calls(mock_adj_temp);
    EXPECT_CALL(mock_adj_temp, decrease_temp())
            .Times(1)
            .WillOnce(Return(-1));

    auto ret_val = test_calls.call_dec_temp();
    EXPECT_EQ(-1, ret_val);
}


TEST(adjTempTest, TestHeating){
    adjust_temp adj_tmp(15, 25);
    const auto actual = adj_tmp.read_sensor_and_act(-3);
    ASSERT_EQ(1, actual);
}

TEST(adjTempTest, TestCooling){
    adjust_temp adj_tmp(15, 25);
    const auto actual = adj_tmp.read_sensor_and_act(36);
    ASSERT_EQ(-1, actual);
}

TEST(adjTempTest, TestNoAction){
    adjust_temp adj_tmp(15, 25);
    const auto actual = adj_tmp.read_sensor_and_act(22);
    ASSERT_EQ(0, actual);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
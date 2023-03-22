add_executable(class_tests unit_tests.cpp)
add_test(g_tests class_tests)
target_link_libraries(class_tests PUBLIC gtest gmock adjust_temp)

add_library(adjust_temp adjust_temp.cpp ../g_tests/unit_tests.cpp)

target_include_directories (adjust_temp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
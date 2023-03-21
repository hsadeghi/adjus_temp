cmake_minimum_required(VERSION 3.18)
project(adjust_room_temp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(adj_temp_class)
add_subdirectory(demo)
add_subdirectory(g_tests)
#add_executable(adjust_room_temp demo/main.cpp)

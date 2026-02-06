cmake_minimum_required(VERSION 3.10.0)
project(sim_b_plus VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main src/main.cpp src/b_list.cpp)

target_include_directories(main PUBLIC include)
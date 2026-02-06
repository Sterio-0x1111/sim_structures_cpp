cmake_minimum_required(VERSION 3.10.0)
project(sim_b_plus VERSION 0.1.0 LANGUAGES C CXX)

target_include_directories(sim_b_plus PUBLIC include)

add_executable(sim_b_plus src/main.cpp)
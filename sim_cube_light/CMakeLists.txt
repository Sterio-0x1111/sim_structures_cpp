cmake_minimum_required(VERSION 3.10)

project(SimCubeLight VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(SimCubeLight PUBLIC include)

add_executable(SimCubeLight 
    main.cpp
)
cmake_minimum_required(VERSION 3.10)
project(SimCubeLight VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW Einbinden
add_subdirectory(external/glfw-3.4)

# GLAD Einbinden
add_library(glad external/glad_khr/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad_khr)
target_include_directories(glad PUBLIC external/glad_khr/KHR)

add_executable(SimCubeLight src/main.cpp)

target_include_directories(SimCubeLight PUBLIC include)

target_link_libraries(SimCubeLight glad glfw opengl32)
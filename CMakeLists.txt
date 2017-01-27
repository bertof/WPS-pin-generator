cmake_minimum_required(VERSION 3.7)
project(WPS_pin_generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GeneratorInterface.h Generator.h Generator.cpp Pin.cpp Pin.h)
add_executable(WPS_pin_generator ${SOURCE_FILES} GeneratorInterface.h Generator.h Generator.cpp)
cmake_minimum_required(VERSION 3.7)
project(WPS_pin_generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Generator/GeneratorInterface.h Pin/Pin.h Generator/Generator.h Exceptions/NotImplementedException.h Generator/Generator.cpp)
add_executable(WPS_pin_generator ${SOURCE_FILES})
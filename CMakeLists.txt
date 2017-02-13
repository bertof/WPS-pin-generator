cmake_minimum_required(VERSION 3.7)
project(WPS_pin_generator)

set(CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 COMPONENTS filesystem date_time)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    set(SOURCE_FILES main.cpp Pin/Pin.h Generator/bertofGenerator/Generator.h Exceptions/NotImplementedException.h Generator/bertofGenerator/Generator.cpp Logger/ScreenLogger/ScreenLogger.h Logger/ScreenLogger/ScreenLogger.cpp Exceptions/InvalidInputException.h Generator/GeneratorInerface.h Logger/Logger.cpp Logger/Logger.h Logger/TextLogger/TextLogger.cpp Logger/TextLogger/TextLogger.h)
    add_executable(WPS_pin_generator ${SOURCE_FILES})


    target_link_libraries(WPS_pin_generator ${Boost_LIBRARIES})
endif ()


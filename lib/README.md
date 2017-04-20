# rang [![Build Status](https://travis-ci.org/agauniyal/rang.svg?branch=master)](https://travis-ci.org/agauniyal/rang) [![Build status](https://ci.appveyor.com/api/projects/status/jqpdoelli38h2a7w?svg=true)](https://ci.appveyor.com/project/agauniyal/rang) [![Coverage Status](https://coveralls.io/repos/github/agauniyal/rang/badge.svg?branch=master)](https://coveralls.io/github/agauniyal/rang?branch=master)

##### Colors for your Terminal.

![rang-demo](https://cloud.githubusercontent.com/assets/7630575/13501282/0bd00074-e18c-11e5-9848-5bd1f20566d9.gif)
![rang-windows-demo](https://cloud.githubusercontent.com/assets/11349690/19836886/8134975e-9ebe-11e6-9ee4-c4657784ff3b.gif)

------
## How to use it
#### No build system/package manager
1. You just need [rang.hpp](https://raw.githubusercontent.com/agauniyal/rang/master/include/rang.hpp) from include directory, use it as `#include "rang.hpp"`
2. Check out the [wiki](https://github.com/agauniyal/rang/wiki) ~~& maybe glance inside ***`test`*** directory to see some usage~~
3. ???
4. Profit!!

#### Using Meson build system
- Use wrapdb to find rang dependency
- Place this code inside your primary `meson.build` - `rang_dep = dependency('rang', fallback : ['rang', 'rang_dep'])`
- Make sure to include `rang_dep` as dependency wherever you need it.

#### Using Conan package manager
- search for rang package or goto - https://conan.io/source/rang/2.0/agauniyal/stable
- install the latest release - `conan install rang/2.0@agauniyal/stable`
- setup your **conanfile.txt** with - 
```
[requires]
rang/2.0@agauniyal/stable

...
```
and **CMakeLists.txt** with -
```
INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

ADD_EXECUTABLE(executable_name main.cpp)
TARGET_LINK_LIBRARIES(executable_name ${CONAN_LIBS})
```
- create build directory - `mkdir build && cd build`
- install package and build - `conan install .. && cmake .. && make`

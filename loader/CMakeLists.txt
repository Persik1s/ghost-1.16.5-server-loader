cmake_minimum_required( VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_GENERATOR_PLATFORM x64)

#NAEM PROJECT
project(Loader)

add_executable(Loader 
    src/main.cpp
    src/math/crypt.cpp
    src/utils/system.cpp
    src/inject/injector.cpp
    src/dbg/dbg.cpp
)



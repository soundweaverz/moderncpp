cmake_minimum_required(VERSION 3.12)
project(moderncxx VERSION 1.0.0)

set(CMAKE_C_FLAGS "-std=c11 -Wall -pedantic")
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic")
add_executable(moderncxx src/modern1230.cpp)
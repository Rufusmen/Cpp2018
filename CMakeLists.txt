cmake_minimum_required(VERSION 3.9)
project(Cpp2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cpp2018 Date/main.cpp Date/date.cpp Date/date.h Date/timePoint.cpp Date/timePoint.h Date/event.cpp Date/event.h)
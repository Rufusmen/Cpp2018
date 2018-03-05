cmake_minimum_required(VERSION 3.9)
project(Cpp2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cpp2018 line/Point.cpp line/Point.h line/Vector.cpp line/Vector.h line/Straight.cpp line/Straight.h line/test.cpp)
cmake_minimum_required(VERSION 3.9)
project(Cpp2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cpp2018 bst/main.cpp bst/Bst.h bst/BstCStr.h bst/BstPtr.h)
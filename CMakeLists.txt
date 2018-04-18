cmake_minimum_required(VERSION 3.9)
project(Cpp2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cpp2018 Matrix/main.cpp Matrix/Matrix.cpp Matrix/Matrix.h Matrix/Invalid_size_exception.h Matrix/Wrong_index_exception.h Matrix/Not_square_matrix_exception.h Matrix/Reverse_exception.h Matrix/Matrix_exception.h)
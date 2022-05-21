cmake_minimum_required(VERSION 3.21)
project(casual)

set(CMAKE_CXX_STANDARD 14)

add_executable(casual main.cpp source/Matrix.cpp source/Matrix.h source/Gauss.cpp source/Gauss.h)

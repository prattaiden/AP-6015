cmake_minimum_required(VERSION 3.27)
project(assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment2 main.cpp
        expr.cpp
        expr.h
        cmdline.cpp
)

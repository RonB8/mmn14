cmake_minimum_required(VERSION 3.23)
project(q1 C)

set(CMAKE_C_STANDARD 99)

add_executable(q1 main.c functions.c cmake-build-debug/data.h data.h)

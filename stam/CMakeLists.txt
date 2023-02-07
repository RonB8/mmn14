cmake_minimum_required(VERSION 3.23)
project(stam C)

set(CMAKE_C_STANDARD 99)

add_executable(stam main.c functions.c data.h my_rottate.c)

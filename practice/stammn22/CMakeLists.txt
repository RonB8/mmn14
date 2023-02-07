cmake_minimum_required(VERSION 3.23)
project(stammn22 C)

set(CMAKE_C_STANDARD 99)

add_executable(stammn22 main.c comands.c data.h textProcessing.c readFields.c)

cmake_minimum_required(VERSION 3.23)
project(mmn22 C)

set(CMAKE_C_STANDARD 90)

add_executable(mmn22 main.c commands.c data.h textProcessing.c readFields.c)

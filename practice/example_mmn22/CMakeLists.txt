cmake_minimum_required(VERSION 3.23)
project(example_mmn22 C)

set(CMAKE_C_STANDARD 99)

add_executable(example_mmn22 main.c messages.c mymat.c analyze.c messages.h mymat.h analyze.h)

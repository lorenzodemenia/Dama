cmake_minimum_required(VERSION 3.17)
project(doit C)

set(CMAKE_C_STANDARD 99)

add_executable(doit main.c function.h function.c Create_free.c)
cmake_minimum_required(VERSION 3.24)
project(final)

set(CMAKE_CXX_STANDARD 17)

add_executable(final executable.cpp)

enable_testing()
add_executable(tests test.cpp doctest.h)
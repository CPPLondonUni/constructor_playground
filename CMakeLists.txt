cmake_minimum_required(VERSION 3.8)
project(constructor_playground)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp example.cpp example.hpp)
add_executable(constructor_playground ${SOURCE_FILES})
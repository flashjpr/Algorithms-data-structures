cmake_minimum_required(VERSION 3.3)
project(euler12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(euler12 ${SOURCE_FILES})
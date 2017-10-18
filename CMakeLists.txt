set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 2.8)

project(ocvCMake)

add_executable(ocvCMake main.cpp parameter.cpp)

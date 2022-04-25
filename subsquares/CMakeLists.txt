cmake_minimum_required(VERSION 3.8)
project(subsquares)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug)
endif()

add_executable(subsquares main.cpp subsquares.cpp subsquares.h)

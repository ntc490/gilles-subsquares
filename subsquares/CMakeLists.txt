cmake_minimum_required(VERSION 3.8)
project(subsquares)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug)
endif()

add_executable(main1 main1.cpp)
add_subdirectory(subsquares1)
target_link_libraries(main1 subsquares1)

add_executable(main2 main2.cpp)
add_subdirectory(subsquares2)
target_link_libraries(main2 subsquares2)

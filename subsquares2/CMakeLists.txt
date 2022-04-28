cmake_minimum_required(VERSION 3.14)

add_library(subsquares2 subsquares.cpp include/subsquares/subsquares.h)
target_include_directories(subsquares2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/subsquares>
  $<INSTALL_INTERFACE:include/subsquares>
)


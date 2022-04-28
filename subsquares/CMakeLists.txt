cmake_minimum_required(VERSION 3.14)
project(subsquares)

set(CMAKE_CXX_STANDARD 11)
set(COMPILE_TESTS YES CACHE BOOL "Compile test framework")

if(NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug)
endif()

# Simple driver programs for the libraries
add_executable(main1 main1.cpp)
add_subdirectory(subsquares1)
target_link_libraries(main1 subsquares1)

add_executable(main2 main2.cpp)
add_subdirectory(subsquares2)
target_link_libraries(main2 subsquares2)

# Google tests
if(COMPILE_TESTS)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(subsquares1_test subsquares1_test.cpp)
target_link_libraries(subsquares1_test subsquares1 gtest_main)

add_executable(subsquares2_test subsquares2_test.cpp)
target_link_libraries(subsquares2_test subsquares2 gtest_main)

include(GoogleTest)
gtest_discover_tests(subsquares1_test)
gtest_discover_tests(subsquares2_test)

endif()

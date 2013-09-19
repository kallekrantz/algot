cmake_minimum_required(VERSION 2.6)
project(algot)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)


include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(sll "${PROJECT_CXX_DIR}/SLL.cpp")
add_library(sll_node "${PROJECT_CXX_DIR}/SLLNode.cpp")

target_link_libraries(sll sll_node)

ADD_SUBDIRECTORY("ext/gtest-1.6.0")
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FILE(GLOB tests "${PROJECT_SOURCE_DIR}/test/*.cpp")
message(tests)
add_executable(runUnitTests
    ${tests}
)
target_link_libraries(runUnitTests gtest gtest_main sll_node sll)

add_test(
  test
  runUnitTests
)

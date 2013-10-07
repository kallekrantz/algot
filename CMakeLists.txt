cmake_minimum_required(VERSION 2.6)
project(algot)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)


include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
add_definitions(-std=c++11)
add_definitions(-m64 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual --coverage)

SET (CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS_INIT} $ENV{LDFLAGS} CACHE STRING "-lgcov")
SET (CMAKE_STATIC_LINKER_FLAGS ${CMAKE_STATIC_LINKER_FLAGS_INIT} $ENV{LDFLAGS} CACHE STRING "-gcov")

#Singly linked lists
add_library(sll "${PROJECT_CXX_DIR}/SLL.cpp")

#Doubly linked lists
add_library(dll "${PROJECT_CXX_DIR}/DLL.cpp")

ADD_SUBDIRECTORY("ext/gtest-1.6.0")
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FILE(GLOB tests "${PROJECT_SOURCE_DIR}/test/*.cpp")

add_executable(runUnitTests
    ${tests}
)

set_target_properties(runUnitTests PROPERTIES COMPILE_FLAGS "--coverage")
target_link_libraries(runUnitTests gtest gtest_main  sll  dll  gcov)


add_test(
  test
  runUnitTests
)

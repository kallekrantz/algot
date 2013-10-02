cmake_minimum_required(VERSION 2.6)
project(algot)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)


include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
add_definitions(-std=c++11 -m64 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual)
#General node class
add_library(base_node "${PROJECT_CXX_DIR}/BASENode.cpp")


#Single Linked List Node
add_library(sll_node "${PROJECT_CXX_DIR}/SLLNode.cpp")
target_link_libraries(sll_node base_node)

#Singly linked lists
add_library(sll "${PROJECT_CXX_DIR}/SLL.cpp")
target_link_libraries(sll sll_node)

#Double linked List node
add_library(dll_node "${PROJECT_CXX_DIR}/DLLNode.cpp")
target_link_libraries(dll_node base_node)

#Doubly linked lists
add_library(dll "${PROJECT_CXX_DIR}/DLL.cpp")
target_link_libraries(dll dll_node)


ADD_SUBDIRECTORY("ext/gtest-1.6.0")
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FILE(GLOB tests "${PROJECT_SOURCE_DIR}/test/*.cpp")

add_executable(runUnitTests
    ${tests}
)
set_target_properties(runUnitTests PROPERTIES COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
set_target_properties(runUnitTests PROPERTIES COMPILE_FLAGS "-lcgov")
target_link_libraries(runUnitTests gtest gtest_main sll_node sll dll_node dll dll_node)


add_test(
  test
  runUnitTests
)

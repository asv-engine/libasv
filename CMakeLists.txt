
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

add_definitions(-std=c++11)

project(libasv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_TESTS 0 CACHE BOOL "Build the unit tests")

if(${BUILD_TESTS})
  add_subdirectory(test)
endif(${BUILD_TESTS})

add_subdirectory(src)
add_subdirectory(example)


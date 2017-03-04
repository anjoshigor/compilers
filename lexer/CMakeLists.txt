cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(lexer)

add_executable(
    lexer
    src/parser.cpp
    src/lexer.cpp
)
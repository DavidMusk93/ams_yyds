cmake_minimum_required(VERSION 3.10)

project(asm_yyds C)

include_directories(${CMAKE_SOURCE_DIR})
set(SRC "integer/bit_scan.c")

add_executable(rotate ${SRC})

cmake_minimum_required(VERSION 3.10)

project(asm_yyds C)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(rotate integer/rotate.c)
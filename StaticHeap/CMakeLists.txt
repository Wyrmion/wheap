cmake_minimum_required(VERSION 3.22)

set(LIB_NAME sheap)

add_library(${LIB_NAME} STATIC sheap.c)


target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
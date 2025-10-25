# CMakeLists.txt for the static library
cmake_minimum_required (VERSION 3.2...4.2)

set(LIB_NAME wheap)

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
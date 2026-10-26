cmake_minimum_required(VERSION 3.22)

set(LIB_NAME wheap)


add_library(${LIB_NAME} INTERFACE)


target_include_directories(${LIB_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/StaticHeap
)

get_directory_property(CURRENT_DEFS COMPILE_DEFINITIONS)

if("USE_MY_STATIC_MEMORY" IN_LIST CURRENT_DEFS)
    add_subdirectory(StaticHeap)
    target_link_libraries(${LIB_NAME} INTERFACE sheap)
endif()
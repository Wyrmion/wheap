cmake_minimum_required(VERSION 3.22)

set(LIB_NAME wheap)

# Создаем интерфейсную библиотеку (для совместимости с вашими проектами на FreeRTOS)
add_library(${LIB_NAME} INTERFACE)

# Пути к заголовкам для обертки и для самой кучи пробрасываем всегда
target_include_directories(${LIB_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/StaticHeap
)

get_directory_property(CURRENT_DEFS COMPILE_DEFINITIONS)

if("USE_MY_STATIC_MEMORY" IN_LIST CURRENT_DEFS OR USE_MY_STATIC_MEMORY)
    add_subdirectory(StaticHeap)
    target_link_libraries(${LIB_NAME} INTERFACE sheap)
endif()
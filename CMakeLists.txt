cmake_minimum_required(VERSION 2.8)

if(WIN32)
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/win) 
endif()

add_subdirectory(tools)
add_subdirectory(src)
add_subdirectory(unit)
add_subdirectory(xddl)
add_subdirectory(examples)
add_subdirectory(perf)
enable_testing()

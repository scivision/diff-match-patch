cmake_minimum_required(VERSION 3.15...3.21)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
endif()

project(DMP
LANGUAGES CXX
VERSION 1.0.0)

enable_testing()

add_library(dmp dmp.cpp)
target_include_directories(dmp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS dmp)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/dmp.h TYPE INCLUDE)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()

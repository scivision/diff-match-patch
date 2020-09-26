cmake_minimum_required(VERSION 3.1)

project(DMP)

set(DMP_SRCS
	dmp.cpp
	dmp.h
	)

add_library(dmp SHARED ${DMP_SRCS})
target_include_directories(dmp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(dmp PUBLIC NOMINMAX)

enable_testing()
add_subdirectory(tests)

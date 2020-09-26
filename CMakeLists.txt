cmake_minimum_required(VERSION 3.1)

project(DMP)

add_definitions(-DNOMINMAX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(diff-match-patch)

set(DMP_SRCS
	dmp.cpp
	dmp.h
	)

add_library(dmp SHARED ${DMP_SRCS})
target_include_directories(dmp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(tests)

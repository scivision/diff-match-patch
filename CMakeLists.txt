cmake_minimum_required(VERSION 3.15...3.21)

project(DMP
LANGUAGES CXX
VERSION 1.0.0)

enable_testing()

add_library(dmp dmp.cpp)
target_include_directories(dmp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(dmp PRIVATE cxx_std_11)

install(TARGETS dmp)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/dmp.h TYPE INCLUDE)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()

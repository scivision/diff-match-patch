CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project(diff-match-patch)

ADD_DEFINITIONS(-DNOMINMAX)

ADD_EXECUTABLE(diff-match-patch-test
  diff_match_patch.cpp
  diff_match_patch.h
  diff_match_patch_test.cpp
  diff_match_patch_test.h
  Definitions.h
  Timer.h)

find_package(Qt5 COMPONENTS Core REQUIRED)
TARGET_LINK_LIBRARIES(diff-match-patch-test Qt5::Core)
include_directories(.)

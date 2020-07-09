CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project(diff-match-patch)

ADD_EXECUTABLE(diff-match-patch-test
  diff_match_patch_test.cpp
  diff_match_patch_test.h
  Definitions.h
  Timer.h)

TARGET_LINK_LIBRARIES(diff-match-patch-test diff-match-patch)
set_target_properties(diff-match-patch-test PROPERTIES FOLDER "Tests")
set_property(TARGET diff-match-patch-test PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}\\$(Configuration)")

include_directories(.)

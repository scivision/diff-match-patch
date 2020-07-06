CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project(diff-match-patch)

ADD_LIBRARY(diff-match-patch
  diff_match_patch.cpp
  diff_match_patch.h)

TARGET_INCLUDE_DIRECTORIES(diff-match-patch PUBLIC .)

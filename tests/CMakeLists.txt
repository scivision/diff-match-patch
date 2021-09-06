add_executable(dmp-test dmp_test.cpp)
target_link_libraries(dmp-test PRIVATE dmp)

add_test(NAME dmp-test
  COMMAND dmp-test
  WORKING_DIRECTORY $<TARGET_FILE_DIR:dmp-test>
  )

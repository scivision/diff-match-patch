add_executable(dmp-test dmp_test.cpp dmp_test.h)
target_link_libraries(dmp-test dmp)

add_test(NAME dmp-test COMMAND dmp-test)
set_property(TARGET dmp-test PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}\\$(Configuration)")


project(unit_test)

set(EXE_SOURCES
	tests.cpp
)

add_executable(custom_unit_test ${EXE_SOURCES})

target_link_libraries(custom_unit_test PRIVATE custom_lib)
set_target_properties(custom_unit_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(NAME custom_unit_test COMMAND custom_unit_test)

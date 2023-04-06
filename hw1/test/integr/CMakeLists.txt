project(integr_test)

set(EXE_SOURCES
	tests.cpp
)

add_executable(custom_integr_test ${EXE_SOURCES})

target_link_libraries(custom_integr_test PRIVATE custom_lib)
set_target_properties(custom_integr_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(NAME custom_integr_test COMMAND custom_integr_test)

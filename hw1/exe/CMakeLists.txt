project(homework)

set(EXE_SOURCES
	main.cpp
)

add_executable(exec ${EXE_SOURCES})

target_link_libraries(exec PRIVATE custom_lib)
set_target_properties(exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

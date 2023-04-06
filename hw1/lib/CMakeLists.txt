project(custom_library)

set(LIB_SOURCES
	modifications.cpp
)

add_library(custom_lib STATIC ${LIB_SOURCES})

message(STATUS ${CMAKE_SOURCE_DIR} ${SOME_VAL})
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(custom_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

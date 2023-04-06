cmake_minimum_required(VERSION 3.16)

project(hometask1)

message(STATUS ${CMAKE_BINARY_DIR})

set(
        CXX_STANDARD 17
)


add_compile_options(-Wall -Wpedantic -Werror )

add_subdirectory(lib/)
add_subdirectory(exe/)
add_subdirectory(test/unit)
add_subdirectory(test/integr)

enable_testing()

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(custom_unit_test PUBLIC gtest gtest_main)
target_link_libraries(custom_integr_test PUBLIC gtest gtest_main)

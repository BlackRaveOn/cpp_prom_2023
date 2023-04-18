cmake_minimum_required(VERSION 3.16)

project(hometask1)

message(STATUS ${CMAKE_BINARY_DIR})

set(
        CMAKE_CXX_STANDARD 17
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_compile_options(-Wall -Wpedantic -Werror )

add_subdirectory(lib/)
add_subdirectory(exe/)
add_subdirectory(test/unit)
add_subdirectory(test/integr)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(custom_unit_test PUBLIC gtest gtest_main)
target_link_libraries(custom_integr_test PUBLIC gtest gtest_main)

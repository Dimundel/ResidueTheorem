cmake_minimum_required(VERSION 3.10)
project(ResidueTheorem)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

find_package(GTest REQUIRED)

add_subdirectory(src/math)
add_subdirectory(test)

add_executable(main src/main.cpp)

target_link_libraries(main math)
cmake_minimum_required(VERSION 3.16.8)
project(big_int_support_library
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Big Integer Support For C++"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## library directory
add_subdirectory(big-int)

## test directory
add_subdirectory(tests)
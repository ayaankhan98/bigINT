cmake_minimum_required(VERSION 3.16.8)
project(big_int_support_library
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Big Integer Support For C++"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_STANDARD 17)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
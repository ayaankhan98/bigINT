add_library(
    big-int
    src/bigint.hpp

    ## operators
    src/operators/assignment_operator.cpp
    src/operators/divide_equal.cpp
    src/operators/divide.cpp
    src/operators/equal_to.cpp
    src/operators/greater_equal.cpp
    src/operators/greater_than.cpp
    src/operators/istream_operator.cpp
    src/operators/less_equal.cpp
    src/operators/less_than.cpp
    src/operators/minus_equal.cpp
    src/operators/minus.cpp
    src/operators/modulo_equal.cpp
    src/operators/modulo.cpp
    src/operators/multiply_equal.cpp
    src/operators/multiply.cpp
    src/operators/not_equal_to.cpp
    src/operators/ostream_operator.cpp
    src/operators/plus_equal.cpp
    src/operators/plus.cpp
    src/operators/pre_post_addition.cpp
    src/operators/pre_post_minus.cpp

    ## operations
)

target_include_directories(big-int PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
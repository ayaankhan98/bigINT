#include <cassert>
#include <iostream>

#include "../../big-int/src/bigint.hpp"
using namespace libbig;

int main()
{

    largeInt bigIntVarA, bigIntVarB, bigIntVarC, bigIntVarD;
    int intVarA = 1000000;
    int64_t int64_tVarA = 1000000000000000011;

    // Assigning int value to largeInt variable
    bigIntVarA = 1928374;
    assert(bigIntVarA == std::string("1928374"));

    // Assigning one largeInt variable to another largeInt variable
    bigIntVarB = bigIntVarA;
    assert(bigIntVarB == std::string("1928374"));

    // Assigning int variable to largeInt variable
    bigIntVarC = intVarA;
    assert(bigIntVarB == std::string("1000000"));

    // Assigning int64_t variable to largeInt variable
    bigIntVarD = int64_tVarA;
    assert(bigIntVarD == std::string("1000000000000000011"));

    return 0;
}

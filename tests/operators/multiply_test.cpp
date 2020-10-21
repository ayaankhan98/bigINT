#include <bigint.hpp>
#include <iostream>
#include <cassert>

int main() 
{
    /// Tests for multiplication of largeInt to largeInt (largeInt * largeInt)
    /// Test 1
    libbig::largeInt a("1");
    libbig::largeInt b("1");
    libbig::largeInt c = a * b;
    assert(c == libbig::largeInt("1"));

    /// Test 2
    a = libbig::largeInt("999");
    b = libbig::largeInt("99999");
    c = a * b;
    assert(c == libbig::largeInt("99899001"));

    /// Test 3
    a = libbig::largeInt("325168432978012983908430177777777777777298721390128391230");
    b = libbig::largeInt("0");
    c = a * b;
    assert(c == libbig::largeInt("0"));

    /// Test 4
    a = libbig::largeInt("666666666666666666666666666666666666666666666666666666666");
    b = libbig::largeInt("58723619378");
    c = a * b;
    assert(c == libbig::largeInt("39149079585333333333333333333333333333333333333333333333294184253748"));

    // Test 5
    a = libbig::largeInt("333333333333333333333333333333333333333333333333333333333");
    b = libbig::largeInt("-2");
    c = a * b;
    assert(c == libbig::largeInt("-666666666666666666666666666666666666666666666666666666666"));

    // Test 6
    a = libbig::largeInt("78239823648904375892093486734");
    b = libbig::largeInt("1273898653482713986555329869218730278549273409");
    c = a * b;
    assert(c == libbig::largeInt("99669605995064286555692172954873309646061179037232089862584737657080456206"));
    
    return 0;
}
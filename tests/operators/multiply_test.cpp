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
    a = libbig::largeInt("32516889472103571029388908423975");
    b = libbig::largeInt("0");
    c = a * b;
    assert(c == libbig::largeInt("0"));

    /// Test 4
    a = libbig::largeInt("6666666666666");
    b = libbig::largeInt("58723619378");
    c = a * b;
    assert(c == libbig::largeInt("391490795853294184253748"));

    // Test 5
    a = libbig::largeInt("33");
    b = libbig::largeInt("-2");
    c = a * b;
    assert(c == libbig::largeInt("-66"));

    // Test 6
    a = libbig::largeInt("78239823648904375");
    b = libbig::largeInt("1273898653482713986555");
    c = a * b;
    assert(c == libbig::largeInt("99669583064888522730377914524230678125"));

    return 0;
}
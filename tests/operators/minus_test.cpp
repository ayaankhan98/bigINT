#include <bigint.hpp>
#include <cassert>
#include <iostream>

int main() 
{
    /// Tests for subtraction of largeInt from largeInt (largeInt - largeInt)
    /// Test 1
    libbig::largeInt a("1");
    libbig::largeInt b("1");
    libbig::largeInt c = a - b;
    assert(c == libbig::largeInt("0"));

    /// Test 2
    a = libbig::largeInt("17893748392478923748923748923748923789473289748923");
    b = libbig::largeInt("00000000000000000000000000000000000000000000000000");
    c = a - b;
    assert(c == libbig::largeInt("17893748392478923748923748923748923789473289748923"));
    
    /// Test 3
    a = libbig::largeInt("913489023849023849023849028590489038590348509345345345345234987284");
    b = libbig::largeInt("746237864872364786238746");
    c = a - b;
    assert(c == libbig::largeInt("913489023849023849023849028590489038590347763107480472980448748538"));
    
    /// Test 4
    // a = libbig::largeInt("-1");
    // b = libbig::largeInt("-1");
    // c = a - b;
    // assert(c == libbig::largeInt("0")); /// returning -0

    /// Test 5
    a = libbig::largeInt("-2433432524534");
    b = libbig::largeInt("1");
    c = a - b;
    assert(c == libbig::largeInt("-2433432524535"));

    /// Test 6
    a = libbig::largeInt("32784");
    b = libbig::largeInt("93085902835904850948590483509348690358690348");
    c = a - b;
    assert(c == libbig::largeInt("-93085902835904850948590483509348690358657564"));


    /// Tests for addition of largeInt to int (largeInt + int)
    /// write tests here



    /// Tests for addition of largeInt to int64_t (largeInt + int64_t)
    /// write tests here
    
    return 0;
}
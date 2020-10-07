#include <iostream>
#include <cassert>
#include <bigint.hpp>

int main()
{
    std::string s1 = "1234";
    std::string s2 = "-1234";
    
    int i1 = 1234;
    int i2 = -1234;

    libbig::largeInt a(s1), b(s2);
    libbig::largeInt c(i1), d(i2);

    assert(a == c);
    assert(b == d);

    return 0;
}
#include<iostream>
#include<cassert>
#include<random>
#include<bigint.hpp>

int main()
{  
    libbig::largeInt a,b;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-2147483648, 2147483647); // define the range

    for(int i=0;i<100;i++)
    {
        int i1 = distr(gen);
        int i2 = distr(gen);
        a = i1;
        b = i2;
        assert((a>b) == (i1>i2));
    }
}
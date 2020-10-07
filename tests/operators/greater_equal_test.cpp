#include<iostream>
#include<cassert>
#include<fstream>
#include<bigint.hpp>

int main()
{  
    std::fstream fin;
    fin.open("./greater_equal_input.txt", std::fstream::in);
    
    libbig::largeInt a,b;
    bool chk;
    
    while(fin>>a)
    {
        fin>>b;
        fin>>chk;
        
        assert((a>=b) == chk);
    }
    fin.close();
}
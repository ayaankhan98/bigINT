#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

#include <bigint.hpp>

int main()
{
    std::ifstream f("input.txt");
    std::string line;

    if (f.is_open())
    {
        while (std::getline(f, line, ','))
        {
            std::stringstream buffer;
            libbig::largeInt a;
            
            buffer << line; 
            buffer >> a;
            assert(a == libbig::largeInt(line));
            buffer.str(std::string());
        }
        f.close();
    } else {
        throw std::runtime_error("Couldn't open input.txt");
    }

    return 0;
}
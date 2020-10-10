#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

#include <bigint.hpp>

int main()
{
    std::ifstream f;

    try
    {
        f.open("input.txt");
        std::string line;

        while (std::getline(f, line, ','))
        {
            libbig::largeInt a;
            std::stringstream buffer;
            
            buffer << line; 
            buffer >> a;

            assert(a == libbig::largeInt(line));
        }
        f.close();
    }
    catch(const std::ifstream::failure& e)
    {
        // Failure to open file stream essentially means 
        // something is wrong somewhere. So assert.
        f.close();
        assert(false);
    }

    return 0;
}
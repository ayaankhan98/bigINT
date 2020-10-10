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

            a = libbig::largeInt(line);
            buffer << a;

            assert(buffer.str().compare(std::string(line)) == 0);
        }
        f.close();
    }
    catch(const std::ifstream& e)
    {
        // Failure to open file stream essentially means 
        // something is wrong somewhere. So assert.
        f.close();
        assert(false);
    }
    return 0;
}

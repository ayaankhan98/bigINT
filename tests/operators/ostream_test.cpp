#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

#include <bigint.hpp>

int main()
{
    libbig::largeInt a;
    std::stringstream buffer;
    std::ifstream f("input.txt");
    std::string line;

    if (f.is_open())
    {
        while (std::getline(f, line))
        {
            a = libbig::largeInt(line);
            buffer << a;
            assert(buffer.str().compare(std::string(line)) == 0);
            buffer.str(std::string());
        }
        f.close();
    } else {
        throw std::runtime_error("Couldn't open input.txt");
    }

    return 0;
}

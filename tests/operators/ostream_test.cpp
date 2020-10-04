#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

#include "../../src/bigint.hpp"

int main()
{
  libbig::largeInt a;
  std::stringstream buffer;
  std::ifstream f("./tests/operators/input.txt");
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
  }

  return 0;
}

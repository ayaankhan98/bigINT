#include <iostream>
#include <cassert>

#include "../../src/bigint.hpp"

int main() {
  freopen("input.txt", "r", stdin);

  libbig::largeInt num, temp;
  num.number = "10000000000000000000000000";
  int b, c;
  long long d;
  
  std::cin >> b;
  num += b;
  assert(num == std::string("10000000000000000000000002"));

  std::cin >> c;
  num += c;
  assert(num == std::string("10000000000000000000010052"));

  std::cin >> d;
  num += d;
  assert(num == std::string("10000000000000123456710052"));

  std::cin >> temp;
  num += temp;
  assert(num == std::string("10000000000000000000000000000000000000000000000000000000000000000000000000123456932274"));

  return 0;
}

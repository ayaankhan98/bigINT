#include <iostream>
#include <cassert>

#include "../../src/bigint.hpp"

int main() {
  freopen("power_test_input.txt", "r", stdin);

  
  int a, b;
  std::cin >> a,b;
  
  libbig::largeInt * num=pow(a,b);

  assert(num->number == "81");
  
  
  std::cin >> a,b;
  
  libbig::largeInt * num=pow(a,b);

  assert(num->number == "262144");
  
  
  std::cin >> a,b;
  
  libbig::largeInt * num=pow(a,b);

  assert(num->number == "1977326743");

 
  return 0;
}
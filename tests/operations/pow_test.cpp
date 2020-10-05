#include <iostream>
#include <cassert>

#include "../../src/bigint.hpp"

int main() {
// 3 4
// 4 9
// 7 11
  
  libbig::largeInt * num=pow(3,4);

  assert(num->number == "81");
  
  
  
  libbig::largeInt * num=pow(4,9);

  assert(num->number == "262144");
  
  
  libbig::largeInt * num=pow(7,11);

  assert(num->number == "1977326743");

 
  return 0;
}
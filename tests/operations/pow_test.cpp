#include <cassert>
#include <bigint.hpp>

int main() {
  libbig::largeInt * num=libbig::pow(3,4);
  assert(num->number == std::string("81"));

  libbig::largeInt * num=libbig::pow(4,9);
  assert(num->number == std::string("262144"));
  
  libbig::largeInt * num=libbig::pow(7,11);
  assert(num->number == std::string("1977326743"));
  
  return 0;
}
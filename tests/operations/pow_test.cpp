#include <bigint.hpp>
#include <cassert>

int main() {

  libbig::largeInt ans("232");

  libbig::largeInt * num=ans.libbig::largeInt pow(3,4);
  assert(num->getnumber() == std::string("81"));

  num=ans.pow(4,9);
  assert(num->getnumber() == std::string("262144"));
  
  num=ans.pow(7,11);
  assert(num->getnumber() == std::string("1977326743"));
  
  return 0;
}
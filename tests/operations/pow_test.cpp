#include <cassert>
#include <bigint.hpp>

int main() {

  libbig::largeInt ans("232");

  libbig::largeInt * num=ans.pow(3,4);
  assert(num->nugetnumber() == std::string("81"));

  num=libbig::ans.pow(4,9);
  assert(num->getnumber() == std::string("262144"));
  
  num=libbig::ans.pow(7,11);
  assert(num->getnumber() == std::string("1977326743"));
  
  return 0;
}
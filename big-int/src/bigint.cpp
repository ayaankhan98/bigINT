#include "bigint.hpp"
#include <cmath>
#include <regex>

namespace libbig {
  largeInt::largeInt() : sign(true), number("0") {}

  largeInt::largeInt(int x) : sign(x >= 0), number(std::to_string(std::abs(x))) {}

  largeInt::largeInt(int64_t x) : sign(x >= 0), number(std::to_string(std::abs(x))) {}

  largeInt::largeInt(long long x) : sign(x >= 0), number(std::to_string(std::abs(x))) {}

  largeInt::largeInt(std::string x) {
    if (!std::regex_match(x, std::regex("(\\-)?(\\d)+")))
      throw(std::invalid_argument("Invalid syntax."));
    sign = x.at(0) != '-';
    if (x.at(0) == '-')
      number = x.substr(1);
    else
      number = x;
  }
} // namespace libbig

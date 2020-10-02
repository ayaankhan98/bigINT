#include <iostream>
#include <cassert>

#include "../../src/bigint.hpp"

int main() {
  freopen("input.txt", "r", stdin);

  libbig::largeInt a;

  std::cin >> a;
  assert(a == std::string("1"));

  std::cin >> a;
  assert(a == std::string("100"));

  std::cin >> a;
  assert(a == std::string("10000"));

  std::cin >> a;
  assert(a == std::string("100000000"));

  std::cin >> a;
  assert(a == std::string("10000000000000000"));

  std::cin >> a;
  assert(a == std::string("100000000000000000000000000000000"));

  std::cin >> a;
  assert(a == std::string("100000000000000000000000000000000000000000000000000000000000000000"));

  std::cin >> a;
  assert(a == std::string("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"));

  std::cin >> a;
  assert(a == std::string("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));

  std::cin >> a;
  assert(a == std::string("-10000000000000000000000000"));

  std::cin >> a;
  assert(a == std::string("-1122178617862763873649236587264782365872467823"));

  std::cin >> a;
  assert(a == std::string("-149023932491"));

  std::cin >> a;
  assert(a == std::string("-34873298478923748973289476592365782689523657926958326459823659726598237503297598246583657924628934928357891"));

  std::cin >> a;
  assert(a == std::string("-26589237985678256786763278562876389472836578264892365427961"));

  return 0;
}

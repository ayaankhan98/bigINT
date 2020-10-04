#include "../../src/bigint.hpp"

int main() {
	libbig::largeInt a;
	std::cout << a << std::endl;
	libbig::largeInt b(42);
	std::cout << b << std::endl;
	libbig::largeInt c(int64_t(-1234567890123456));
	std::cout << c << std::endl;
	long long cVal = 42;
	libbig::largeInt d(cVal);
	std::cout << d << std::endl;
	libbig::largeInt e("-853829");
	std::cout << e << std::endl;

	return 0;
}
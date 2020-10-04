#include <iostream>
using namespace std;

// Non-member functions:
class largeInt {
  long i;
  largeInt* This() { return this; }
public:
  largeInt(long ll = 0) : i(ll) {}
  friend const largeInt&
    operator+(const largeInt& a);
  friend const largeInt
    operator-(const largeInt& a);
};

// Global operators:
const largeInt& operator+(const largeInt& a) {
  cout << "+Integer\n";
  return a; // Unary + has no effect
}
const largeInt operator-(const largeInt& a) {
  cout << "-Integer\n";
  return largeInt(-a.i);
}

// Show that the overloaded operators work:
void f(largeInt a) {
  +a;
  -a;
}

// Member functions (implicit "this"):
class Byte {
  unsigned char b;
public:
  Byte(unsigned char bb = 0) : b(bb) {}
  // No side effects: const member function:
  const Byte& operator+() const {
    cout << "+Byte\n";
    return *this;
  }
  const Byte operator-() const {
    cout << "-Byte\n";
    return Byte(-b);
  }
};

void g(Byte b) {
  +b;
  -b;
}

int main() {
  largeInt a;
  f(a);
  Byte b;
  g(b);
}

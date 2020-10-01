#ifndef BIG_INT
#define BIG_INT

#include <iostream>
#include <string>

class largeInt {
  private:
    bool sign;
    std::string number;
  public:
    largeInt() {
    }

    largeInt(int) {
    }

    largeInt(int64_t) {
    }

    largeInt(long long) {
    }

    largeInt(std::string) {
    }

    largeInt operator + (largeInt);
    largeInt operator + (int);
    largeInt operator + (int64_t);
    largeInt operator + (long long);

    largeInt operator - (largeInt);
    largeInt operator - (int);
    largeInt operator - (int64_t);
    largeInt operator - (long long);

    largeInt operator * (largeInt);
    largeInt operator * (int);
    largeInt operator * (int64_t);
    largeInt operator * (long long);

    largeInt operator / (largeInt);
    largeInt operator / (int);
    largeInt operator / (int64_t);
    largeInt operator / (long long);

    largeInt operator % (largeInt);
    largeInt operator % (int);
    largeInt operator % (int64_t);
    largeInt operator % (long long);

    largeInt& operator += (largeInt);
    largeInt& operator += (int);
    largeInt& operator += (int64_t);
    largeInt& operator += (long long);

    largeInt& operator -= (largeInt);
    largeInt& operator -= (int);
    largeInt& operator -= (int64_t);
    largeInt& operator -= (long long);

    largeInt& operator *= (largeInt);
    largeInt& operator *= (int);
    largeInt& operator *= (int64_t);
    largeInt& operator *= (long long);

    largeInt& operator /= (largeInt);
    largeInt& operator /= (int);
    largeInt& operator /= (int64_t);
    largeInt& operator /= (long long);

    largeInt operator %= (largeInt);
    largeInt operator %= (int);
    largeInt operator %= (int64_t);
    largeInt operator %= (long long);

    /// PREFIX OPERATORS


    /// POSTFIX OPERATORS

    void operator = (largeInt);
    void operator = (int);
    void operator = (int64_t);
    void operator = (long long);

    bool operator == (largeInt);
    bool operator == (int);
    bool operator == (int64_t);
    bool operator == (long long);

    bool operator != (largeInt);
    bool operator != (int);
    bool operator != (int64_t);

    bool operator < (largeInt);
    bool operator < (int);
    bool operator < (int64_t);
    bool operator < (long long);

    bool operator > (largeInt);
    bool operator > (int);
    bool operator > (int64_t);
    bool operator > (long long);

    bool operator <= (largeInt);
    bool operator <= (int);
    bool operator <= (int64_t);
    bool operator <= (long long);

    bool operator >= (largeInt);
    bool operator >= (int);
    bool operator >= (int64_t);
    bool operator >= (long long);

    friend std::istream& operator >> (std::istream&, largeInt&);
    friend std::ostream& operator << (std::ostream&, largeInt&);
};

#endif


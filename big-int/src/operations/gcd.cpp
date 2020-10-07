#include <iostream>
#include 'bigINT'
using namespace std;

bigINT gcd(bigINT a, bigINT b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    bigINT a = "1231231231232" ,b = "12";
    gcd(a, b);
}

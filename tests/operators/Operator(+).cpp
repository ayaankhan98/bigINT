#include <iostream>
using namespace std;

class largeInt {
   private:
    long int real;
   public:
    largeInt() : real(0) {}

    void input() {
        cin >> real;
    }

    largeInt operator + (const largeInt& obj) {
        largeInt temp;
        temp.real = real + obj.real;
        return temp;
    }

    void output() 
    {
        cout<< real <<endl;
    }
};

int main() {
    largeInt a, b, result;

    a.input();
    b.input();
    result = a + b;
    result.output();

    return 0;
}

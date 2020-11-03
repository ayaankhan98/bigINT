#include<bits/stdc++.h>


using namespace std;


class Integer {
    int sign;
    string value;

public:
    Integer() {
        //Default Empty Constructor::Dont use delegation...
    }
    //positive - negative value separator
    Integer(string passed) {
        if (passed[0] == '0') {
            sign = 0;
            value = "0";
        } else if (passed[0] == '-'){
            sign = -1;
            value = passed.substr(1); // Copy substring after pos 1
        } else {
            sign = +1;
            value = passed;//if positive store as it's
        }
    }
    Integer(string passed, int Sign) {
        value = passed;
        sign = Sign;
    }

    //Day 4: if  integer range numbers  are passed then  only will work fine.....preferably pass string values..
    Integer(int passed) {    //Remember Remove this as we will be passing string as a parameter
        if (passed == 0) {
            sign = 0;
            value = "0";
        } else if (passed < 0) {
            sign = -1;
            value = to_string(-passed);
        } else {
            sign = +1;
            value = to_string(passed);
        }
    }
//operator over-loadings:
    void operator = (string passed) {//check parity in assignment
        if (passed[0] == '0') {
            sign = 0;
            value = "0";
        } else if (passed[0] == '-'){
            sign = -1;
            value = passed.substr(1);
        } else {
            sign = +1;
            value = passed;
        }
    }

    //Day 4 Work: We can remove this as will mention, that we will be using string parameter ..we will mention...
    void operator = (long long passed) {
        value = to_string(passed < 0 ? -passed : passed);
        sign = (passed == 0 ? 0 : (passed > 0 ? 1 : -1));
    }
    string toString(){ // string converter
        if (this->isZero()) {
            return "0";
        } else {
            return (sign == +1 ? "" : "-") + value;
        }
    }
    int get_sign() { // Day 2 Work: sign of the integer
        return sign;
    }
    string getValue() { // Day 2 Work: value part of the integer (without sign)
        return value;
    }
    int length() { // Day 2 Work:length of the value part in decimal
        return (int)value.size(); //Day 2 Work: type-casted to int
    }
    int digitAt(int position) { // digit at specific position
        if (position < this->length()) {
            return value[position] - '0';
        } else {
            return -1;
        }
    }



























    int _compare(string A, string B) {   //For MODULO
        int length_A = (int)A.size();
        int length_B = (int)B.size();
        if (length_A != length_B) {
            return length_A < length_B ? -1 : +1;
        }
        for (int i = 0; i < length_A; i ++) {
            if (A[i] != B[i]) {
                return A[i] < B[i] ? -1 : +1;
            }
        }
        return 0;
    }
    void insertTrailingZeros(string &a, int j) { //for karatsuba
        for (int i = 0; i < j; i ++) {
            a += '0';
        }
    }


    string add(string a, string b) { //Day 4: addition of numbers in linear time
        string sum = "";
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        int r = 0;
        while (i >= 0 || j >= 0) {
            int state = r;
            if (i >= 0) state += a[i] - '0';
            if (j >= 0) state += b[j] - '0';
            if (state > 9) {
                state -= 10;
                r = 1;
            } else {
                r = 0;
            }
            i --;
            j --;
            sum += (char)(state + '0');
        }
        if (r > 0) {
            sum += (char)(r + '0');
        }
        while ((int)sum.size() > 1 && sum.back() == '0') {
            sum.pop_back();
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
    string subtract(string a, string b) { // subtraction of two numbers(strings)
        string diff = "";
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        int k = 0;
        while (i >= 0) {
            int s = a[i] - '0' - k;
            if (j >= 0) {
                s =s-( b[j] - '0');
            }
            if (s < 0) {
                s += 10;
                k = 1;
            } else {
                k = 0;
            }
            i --;
            j --;
            diff =diff + (char)(s + '0');
        }
        while ((int)diff.size() > 1 && diff.back() == '0') {
            diff.pop_back();
        }
        reverse(diff.begin(), diff.end());
        return diff;
    }
    void _break(string &a, string &l, string &r) { // break the number two 2 equal parts
        int length = (int)a.size();
        int half = length >> 1;
        l = a.substr(0, half);
        r = a.substr(half);
    }
    void normalize(string &a, string &b) { // used to make the len equal to two's power
        int length_A = (int)a.size();
        int length_B = (int)b.size();
        int to = -1;
        for (int i = 0; ; i ++) {
            if ((1 << i) >= length_A && (1 << i) >= length_B) {
                to = (1 << i);
                break;
            }
        }
        if (length_A < to) {
            reverse(a.begin(), a.end());
            while (length_A < to) {
                a += '0';
                length_A ++;
            }
            reverse(a.begin(), a.end());
        }
        if (length_B < to) {
            reverse(b.begin(), b.end());
            while (length_B < to) {
                b += '0';
                length_B ++;
            }
            reverse(b.begin(), b.end());
        }

    }
    string defaultMultiplier(string &a, string &b) { // builtin multiplication
        int aValue = stoi(a); //string to int
        int bValue = stoi(b);
        return to_string(1LL * aValue * bValue);
    }

    string multiply(string a, string b) {     //Day 5: Using karatsuba Algorithm...
        if ((int)a.size() < 9 && (int)b.size() < 9) {
            return defaultMultiplier(a, b);
        }

        normalize(a, b);
        string leftA, rightA;
        string leftB, rightB;
        _break(a, leftA, rightA);
        _break(b, leftB, rightB);
        string p1 = multiply(leftA, leftB);
        string p2 = multiply(rightA, rightB);
        string a_sum = add(leftA, rightA);
        string b_sum = add(leftB, rightB);
        string p3 = multiply(a_sum, b_sum);
        string delta31 = subtract(p3, p1);
        string p4 = subtract(delta31, p2);
        insertTrailingZeros(p1, (int)a.size());
        insertTrailingZeros(p4, (int)a.size() >> 1);
        string sum= add(p2, p4);
        return add(p1, sum);
    }



    string _modulo(string a, string b) { // modulo operation of two integers(strings)
        string result = "";
        string current = "";
        for (char ch: a) {
            current += ch;
            if (_compare(current, b) != -1) {
                int wheel = 0;
                while (_compare(current, b) != -1) {
                    wheel ++;
                    current = subtract(current, b);
                }
                result += (char)(wheel + '0');
            }
        }
        reverse(current.begin(), current.end());
        while ((int)current.size() > 1 && current.back() == '0') {
            current.pop_back();
        }
        reverse(current.begin(), current.end());
        return current;
    }
    string fast_modulo(string a, int b) { // faster modulo function
        string result = "";
        int current = 0;
        for (char ch: a) {
            current = (current << 1) + (current << 3) + ch - '0';
            if (current >= b) {
                result += (char)(current / b + '0');
                current %= b;
            }
        }
        return to_string(current);
    }

    string modulo(string a, string b) { // Day 5: modulo of two integers
        if ((int)b.size() > 9) {
            return _modulo(a, b);
        } else {
            return fast_modulo(a, stoi(b));
        }
    }


//OPERATORS
//OVERLOADING
//DAY 5 almost completed
bool operator == (Integer passed) { //Day 4: equal to operator
        return (sign == passed.get_sign() || isZero()) && value == passed.getValue();
    }

    bool operator < (Integer passed) { // less than operator
        if (sign !=passed.get_sign()) {
            return sign < passed.get_sign();
        }
        int length_passed = passed.length();
        int length = this->length();

        if (length < length_passed) {
            return sign == 1;
        } else if (length > length_passed) {
            return sign == -1;
        }
        for (int i = 0; i < length; i ++) {
            if (value[i] - '0' != passed.digitAt(i)) {
                return value[i] - '0' < passed.digitAt(i) && sign == 1;
            }
        }
        return false;
    }

    bool operator <= (Integer passed) { // less or equal operator
        return *this == passed || *this < passed;
    }

    bool operator > (Integer passed) { // greater operator
        return !(*this <= passed);
    }



    void operator = (Integer passed) { // Day 4: assignment for INTEGER VALUE set to new value
        sign = passed.get_sign();
        value = passed.getValue();
    }

    Integer abs() { // take absolute value (positive value)
        return Integer(value, sign == -1 ? 1 : sign);
    }


    Integer operator * (Integer multiplier) { // multiplication of two integers
        if (this->isZero() || multiplier.isZero()) {
            return Integer("0");
        } else {
            string result = multiply(value, multiplier.getValue());
            return Integer(result, (sign == multiplier.get_sign() ? +1 : -1));
        }
    }

    void operator *= (Integer multiplier) {
        *this = *this * multiplier;
    }


    Integer operator % (Integer dividend) { // modulo of two integers
        if (dividend.isZero()) {
            throw runtime_error("Division by zero");
        } else if (isZero()) {
            return Integer("0");
        } else {
            return Integer(modulo(value, dividend.getValue()), (sign == dividend.get_sign() ? +1 : -1));
        }
    }

    void operator %= (Integer dividend) { // modulo operator
        *this = *this % dividend;
    }


    friend istream &operator>>( istream  &input, Integer &D ) {
       string passed;
       input>>passed;
        if (passed[0] == '0') {
            D.sign = 0;
            D.value = "0";
        } else if (passed[0] == '-'){
            D.sign = -1;
            D.value = passed.substr(1); // Copy substring after pos 1
        } else {
            D.sign = +1;
            D.value = passed;//if positive store as it's
        }


        return input;
    }

    bool isZero() { // checking equality to zero
        return (!value.empty() && value[0] == '0') || sign == 0;
    }
    bool isPositive() { // checking positiveness
        return sign == +1;
    }
    bool isNegative() { // checking negativeness
        return sign == -1;
    }

    bool isOdd() { // checking oddness
        return !value.empty() && ((int)value.back() & 1);
    }

};
//Day 5 : Overloading of insertion operator (<<cout>>)
std::ostream &operator << (std::ostream &out, Integer i) {
    return out << i.toString();
}




//IMPLEMENTED MAIN  ASSIGNMENT FUNCTIONS
Integer pow(Integer I, int exponent) {
    Integer result = 1, p = Integer(I);
    while (exponent > 0) {
        if (exponent & 1) {
            result *= p;
        }
        exponent >>= 1;
        p = p * p;
    }
    return result;
}
Integer gcd(Integer A, Integer B) {

    while (B > 0) {
        A %= B;
        if (A == 0) {
            return B;
        }
        B %= A;
    }
    return A;
}

Integer factorial(int number) { // factorial of the integer not passing BIG_INTEGER HERE...as it will be too much..

    if (number < 0) {
        return 0;
    }
    Integer result = 1;
    for (int i = 2; i <= number; i ++) {
        result *= i;
    }
    return result;
}


int main() {
    int q, c;
    Integer a, b;
    int A,B;
    cin >> q;
    while (q--) {
        cin >> c;
        switch (c) {
            case 1: cin>>a;
                    cin>>B;
                     cout << pow(a,B) << endl;
                     break;
            case 2: cin>>a;
                    cin>>b;
                   cout<<gcd(a, b)<<endl;
                    break;


                    case 3: cin>>A;
                    cout<<factorial(A)<<endl;
                    break;
        }

        return 0;
    }
}
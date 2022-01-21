#ifndef MATHPARSER_CORE_H
#define MATHPARSER_CORE_H

#include <iostream>
#include <cmath>

using namespace std;

const short maxEqLength = 256;
bool interfaceMode = false;

struct eqsymbols {
    short digits = 0;
    short pluses = 0;
    short minuses = 0;
    short multipl = 0;
    short divide = 0;
    short brack1 = 0;
    short brack2 = 0;
    short pows = 0;
    short roots = 0;
    short semicolons = 0;
    short others = 0;
    bool status = 0;            // 0 -> ok | 1 -> "Syntax error."
};

double power(double num, double pw) {
    if (interfaceMode == true) {
        cout << "========pow========" << endl;
        cout << "pow(" << num << "; " << pw << ")=" << pow(num, pw) << endl;
    }
    return pow(num, pw);
}

double root(double num) {
    if (interfaceMode == true) {
        cout << "=======root=======" << endl;
        cout << "sqrt(" << num << ")=" << sqrt(num) << endl;
    }
    return sqrt(num);
}

double multiply(double num1, double num2) {
    if (interfaceMode == true) {
        cout << "=====multiply=====" << endl;
        cout << num1 << "*";

        if (num2 < 0) cout << "(";

        cout << num2;

        if (num2 < 0) cout << ")";

        cout << "=" << num1*num2 << endl;
    }
    return num1*num2;
}

double divide(double num1, double num2) {
    if (interfaceMode == true) {
        cout << "======divide======" << endl;
        cout << num1 << "/";

        if (num2 < 0) cout << "(";

        cout << num2;

        if (num2 < 0) cout << ")";

        cout << "=" << double(num1)/num2 << endl;
    }
    return double(num1)/num2;
}

double add(double num1, double num2) {
    if (interfaceMode == true) {
        cout << "========add========" << endl;
        cout << num1 << "+";

        if (num2 < 0) cout << "(";

        cout << num2;

        if (num2 < 0) cout << ")";

        cout << "=" << num1+num2 << endl;
    }
    return num1+num2;
}

double substract(double num1, double num2) {
    if (interfaceMode == true) {
        cout << "=====substract=====" << endl;
        cout << num1 << "-";

        if (num2 < 0) cout << "(";

        cout << num2;

        if (num2 < 0) cout << ")";

        cout << "=" << num1-num2 << endl;
    }
    return num1-num2;
}

#endif // MATHPARSER_CORE_H

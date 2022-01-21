#include <iostream>
#include <cmath>

using namespace std;

struct quadEqArgs {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct quadEqRoots {
    bool areComplex = false;
    double x1 = 0;
    double x2 = 0;
};

void showQuadEq(quadEqArgs args) {
    cout << "Your equation: ";

    if (args.a > 0)
        if (args.a == 1)
            cout << "x^2";
        else
            cout << args.a << "x^2";
    else if (args.a < 0)
        if (args.a == -1)
            cout << "-x^2";
        else
            cout << args.a << "x^2";

    if (args.b > 0)
        if (args.b == 1)
            cout << "x";
        else
            cout << "+" << args.b << "x";
    else if (args.b < 0)
        if (args.b == -1)
            cout << "-x";
        else
            cout << args.b << "x";

    if (args.c > 0)
        cout << "+" << args.c;
    else if (args.c < 0)
        cout << args.c;

    cout << "=0" << endl;
}

double convertStrToNum(char argInput[], int index) {
    double number = 0;
    bool isIntegralPart = true;
    bool isNegative = false;
    double mult = 0.1;

    if (argInput[index-1] == '-') isNegative = true;

    for (; (argInput[index] >= '0' && argInput[index] <= '9') || argInput[index] == '.'; index++) {
        if (argInput[index] >= '0' && argInput[index] <= '9') {
            if (isIntegralPart) {
                number *= 10;
                number += (argInput[index] - '0');
            }
            else {
                number += (argInput[index] - '0')*mult;
                mult /= 10;
            }
        }
        else {
            isIntegralPart = false;
        }
    }

    if (isNegative) number = -number;

    return number;
}

void skipNumInStr(char argInput[], int &resIndex) {
    for(; (argInput[resIndex+1] >= '0' && argInput[resIndex+1] <= '9') || argInput[resIndex+1] == '.'; resIndex++) { }
}

quadEqArgs extractArgs(char argInput[]) {
    double tmpArgs[3] = {0, 0, 0};
    int argIndex = 0;

    for (int inputIndex = 0; argInput[inputIndex] != 0; inputIndex++) {
        if ((argInput[inputIndex] >= '0' && argInput[inputIndex] <= '9') || argInput[inputIndex] == '.') {

            tmpArgs[argIndex] = convertStrToNum(argInput, inputIndex);
            argIndex++;
            skipNumInStr(argInput, inputIndex);

            if(argIndex > 2) break;
        }
    }

    quadEqArgs args = {tmpArgs[0], tmpArgs[1], tmpArgs[2]};
    return args;
}

quadEqRoots findQuadEqRoots(double a, double b) {
    bool isComplex = false;
    double x1 = 0, x2 = 0;
    double D = b*b;

    if (D > 0) {
        x1 = 0;
        x2 = -b/a;
    }
    else if (D == 0){
        x1 = x2 = 0;
    }
    else {
        isComplex = true;
    }

    return {isComplex, x1, x2};
}

quadEqRoots findQuadEqRoots(double a, double b, double c) {
    bool isComplex = false;
    double x1 = 0, x2 = 0;
    double D = b*b-4*a*c;

    if (D > 0) {
        x1 = (-b+sqrt(D)) / (2*a);
        x2 = (-b-sqrt(D)) / (2*a);
    }
    else if (D == 0) {
        x1 = x2 = -b/(2*a);
    }
    else {
        isComplex = true;
    }

    return {isComplex, x1, x2};
}

quadEqArgs getQuadEqArgs() {
    char argInput[32];
    for (int i = 0; i < 32; i++)
        argInput[i] = 0;

    cout << "Enter the arguments (a, b, c) / (a, b): ";
    cin.getline(argInput, 32);

    quadEqArgs args = extractArgs(argInput);
    if (args.a == 0) {
        cout << "Incorrect input. If a = 0, it's not a quadric equation." << endl;
        args = getQuadEqArgs();
    }

    return args;
}

int main() {
    cout << "========== Quadric Equation: ax^2+bx+c=0 ==========" << endl;
    quadEqArgs args = getQuadEqArgs();

    showQuadEq(args);

    quadEqRoots roots;
    if (args.c != 0)
        roots = findQuadEqRoots(args.a, args.b, args.c);
    else
        roots = findQuadEqRoots(args.a, args.b);

    if (roots.areComplex)
        cout << "Roots are complex numbers." << endl;
    else
        cout << "x1 = " << roots.x1 << " | x2 = " << roots.x2 << endl;
}

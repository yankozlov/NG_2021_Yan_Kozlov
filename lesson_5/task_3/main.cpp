#include <mathparser.h>

int main() {
    interfaceMode = true;
    char equation[maxEqLength];

    for(int i = 0; i < maxEqLength; i++) equation[i] = 0;

    if (interfaceMode == true) {
        cout << "==============================================================" << endl
             << "available operations: + , - , * , / , ( ) , sqrt( ), pow( ; )." << endl
             << "enter the equation: ";
    }
    cin.getline(equation, maxEqLength);

    char *result = equationResult(equation);

    if (interfaceMode == true) cout << "=======result=======" << endl;

    cout << result << endl;
}

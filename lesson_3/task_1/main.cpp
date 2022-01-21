#include <iostream>

using namespace std;

int main()
{
    int userArr[10];
    int n = 0;
    cout << "input the array (10 numbers): ";
    for (int i = 0; i < 10; i++) {
        cin >> userArr[i];
    }
    cout << "enter the number to add: ";
    cin >> n;
    cout << "modified array: ";
    for (int i = 0; i < 10; i++) {
        cout << userArr[i] + n << " ";
    }
}

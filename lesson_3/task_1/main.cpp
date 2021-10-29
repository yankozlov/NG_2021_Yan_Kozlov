#include <iostream>
#include <random>

using namespace std;

int main()
{
    int userArr[10], modArr[10];
    int n;
    cout << "input the array (10 numbers): ";
    for (int i = 0; i < 10; i++) {
        cin >> userArr[i];
    }
    cout << "enter the number to add: ";
    cin >> n;
    cout << "modifiesd array: ";
    for (int i = 0; i < 10; i++) {
        modArr[i] = userArr[i] + n;
        cout << modArr[i] << " ";
    }
}

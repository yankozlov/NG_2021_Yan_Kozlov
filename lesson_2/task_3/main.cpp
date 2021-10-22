#include <iostream>

using namespace std;

int main()
{
    int sizeOfSquare;
    cout << "enter the size of square: ";
    cin >> sizeOfSquare;
    for (int i = 0; i < sizeOfSquare; i++) {
        for (int j = 0; j < sizeOfSquare; j++) {
            if (i != 0 && i != sizeOfSquare-1 && j != 0 && j != sizeOfSquare-1)
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;
    }
}

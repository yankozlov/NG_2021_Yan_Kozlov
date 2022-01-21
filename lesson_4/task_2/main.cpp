#include <iostream>

using namespace std;

int main()
{
    bool same = true;
    char str1[256], str2[256];

    cout << "String 1: ";
    cin.getline(str1, 256);
    cout << "String 2: ";
    cin.getline(str2, 256);

    for (int i = 0; str1[i] + str2[i] != 0; i++) {
        if (str1[i] != str2[i]) {
            same = false;
            break;
        }
    }
    if (same == true)
        cout << "The strings are equal.";
    else
        cout << "The strings are not equal";
}

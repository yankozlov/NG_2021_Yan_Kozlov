#include <iostream>

using namespace std;

int main()
{
    char text[256];
    cout << "Enter the message: ";
    cin.getline(text, 256);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'f' && text[i+1] == 'u' && text[i+2] == 'c' && text[i+3] == 'k') {
            cout << "****";
            i+=3;
        }
        else {
            cout << text[i];
        }
    }
}

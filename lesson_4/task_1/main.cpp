#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    char input[256];
    cout << "Enter some text: ";
    cin.getline(input, 256);
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] >= '!' && input[i] <= '@' ||
            input[i] >= '[' && input[i] <= '`' ||
            input[i] >= '{' && input[i] <= '~') counter++;
    cout << "Number of punctuation marks: " << counter;
}

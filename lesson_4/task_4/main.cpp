#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    char text[256];
    char hashstring[128];
    cout << "Enter the text: ";
    cin.getline(text, 256);
    for(int i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' ||
            text[i] == 'o' || text[i] == 'u' || text[i] == 'y' ||
            text[i] == 'A' || text[i] == 'E' || text[i] == 'I' ||
            text[i] == 'O' || text[i] == 'U' || text[i] == 'Y' ) counter++;
        if (text[i] == ' ' || text[i+1] == '\0') {
            hashstring[j] = char('0'+counter);
            hashstring[j+1] = '\0';
            counter = 0;
            j++;
        }
     }
     cout << "The hashstring is: " << hashstring;
}

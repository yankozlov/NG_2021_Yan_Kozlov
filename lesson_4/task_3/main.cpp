#include <iostream>

using namespace std;

int main()
{
    char message[] = {"yt ufxx ymnx yfxp fii dtzw sfrj fx htrrjsy bnym qnsp yt uwtlwfr ns lny"};
    for (int i = 0; i < 26; i++) {
        for (int j = 0; message[j] != '\0'; j++) {
            if (message[j] >= 'a' && message[j] <= 'z') {
                if (message[j]+i > 'z')
                    cout << char(message[j]+i-26);
                else
                    cout << char(message[j]+i);
            }
            else
                cout << message[j];
        }
        cout << endl;
    }
}

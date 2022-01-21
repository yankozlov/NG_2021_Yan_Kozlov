#include <iostream>

using namespace std;

int main()
{
    int num = 0, hashcode = 0;
    cout << "enter the number: ";
    cin >> num;
    for (int tmpNum = num; tmpNum != 0; tmpNum /= 10) {
        if (tmpNum%10 == tmpNum/10%10)
            hashcode += tmpNum%10;
        if (tmpNum == num%10)
            hashcode += tmpNum;
    }
    cout << "the hashcode is " << hashcode;
}

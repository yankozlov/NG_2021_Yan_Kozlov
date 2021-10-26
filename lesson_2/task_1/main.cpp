#include <iostream>

using namespace std;

int main()
{
    int num, tmpNum, sum = 0;
    cout << "enter the number: ";
    cin >> num;
    tmpNum = num;
    while (tmpNum != 0) {
        sum += tmpNum%10;
        tmpNum /= 10;
    }
    cout << "Sum of the digits: " << sum;
}

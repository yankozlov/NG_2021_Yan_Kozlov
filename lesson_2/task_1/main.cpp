#include <iostream>

using namespace std;

int main()
{
    int num = 0, sum = 0;
    cout << "enter the number: ";
    cin >> num;
    for (int tmpNum = num; tmpNum != 0; tmpNum /= 10)
        sum += tmpNum%10;
    cout << "Sum of the digits: " << sum;
}

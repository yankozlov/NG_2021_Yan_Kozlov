#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;
    cout << "enter the number: ";
    cin >> num;
    while (num != 0) {
        sum += num%10;
        num /= 10;
    }
    cout << "Sum of all numbers: " << sum;
}

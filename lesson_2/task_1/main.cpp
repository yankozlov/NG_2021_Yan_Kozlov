#include <iostream>

using namespace std;

int main()
{
    int num;
    int res = 0;
    cout << "enter the number: ";
    cin >> num;
    while (num != 0) {
        res += num%10;
        num /= 10;
    }
    cout << "res: " << res;
}

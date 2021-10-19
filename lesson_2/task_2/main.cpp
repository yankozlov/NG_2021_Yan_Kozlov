#include <iostream>

using namespace std;

int main()
{
    int num, hashcode = 0, tmp;
    cout << "enter the number: ";
    cin >> num;
    tmp = num%10;
    while (num != 0) {
        if (num%10 == num/10%10)
            hashcode += num%10;
        if (num < 10 && num == tmp)
            hashcode += num;
        num /= 10;
    }
    cout << "the hashcode is " << hashcode;
}

#include <iostream>

using namespace std;

int main()
{
    int a = 50;
    int b = 20;
    a += b;
    b = a - b;
    a -= b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

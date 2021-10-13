#include <iostream>

using namespace std;

int main()
{
    int a = 50;
    int b = 20;
    //variant #1
    a += b;
    b = a-b;
    a -= b;
    //variant #2
    a *= b;
    b = a/b;
    a /= b;
    //variant #3
    swap (a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

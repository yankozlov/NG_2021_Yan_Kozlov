#include <iostream>
#include <random>

using namespace std;

int main()
{
    srand(time(0));
    int n = 4;
    int arr1[n], arr2[n];
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        num1 *= 10;
        num2 *= 10;

        arr1[i] = rand()%10;
        arr2[i] = rand()%10;

        num1 += arr1[i];
        num2 += arr2[i];
    }
    cout << "Got: " << num1 << " + " << num2 << endl;
    cout << "Result: " << num1+num2;
}

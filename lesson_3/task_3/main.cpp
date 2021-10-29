#include <iostream>
#include <random>

using namespace std;

int main()
{
    srand(time(0));
    int arr1[4], arr2[4];
    int num1, num2;
    for (int i = 0; i < 4; i++) {
        arr1[i] = rand()%10;
        arr2[i] = rand()%10;
    }
    num1 = arr1[0]*1000 + arr1[1]*100 + arr1[2]*10 + arr1[3];
    num2 = arr2[0]*1000 + arr2[1]*100 + arr2[2]*10 + arr2[3];
    cout << "Got: " << num1 << " + " << num2 << endl;
    cout << "Result: " << num1+num2;
}

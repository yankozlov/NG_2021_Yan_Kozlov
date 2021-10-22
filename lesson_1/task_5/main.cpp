#include <iostream>

using namespace std;

int main()
{
    int mass, fuel;
    cout << "enter ZAZ spaceship's mass, kg: ";
    cin >> mass;
    fuel = mass/3-2;
    cout << "fuel needed: " << fuel << " kg.";
}

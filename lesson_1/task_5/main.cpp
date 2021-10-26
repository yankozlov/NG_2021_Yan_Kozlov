#include <iostream>

using namespace std;

int main()
{
    int mass, fuel;
    cout << "enter ZAZ spaceship's mass, kg: ";
    cin >> mass;
    fuel = (float(mass/3)-2)*300;
    cout << "fuel needed: " << fuel << " kg.";
}

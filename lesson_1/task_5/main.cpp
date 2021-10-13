#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float mass, fuel;
    cout << "enter ZAZ spaceship's mass, kg: ";
    cin >> mass;
    fuel = round(mass/3.0)-2;
    cout << "fuel needed: " << fuel << " kg.";
}

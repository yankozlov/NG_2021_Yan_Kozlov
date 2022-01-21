#include <iostream>

using namespace std;

int main()
{
    int mass = 0;
    cout << "enter ZAZ spaceship's mass, kg: ";
    cin >> mass;
    cout << "fuel needed: " << (float(mass/3)-2)*300 << " kg.";
}

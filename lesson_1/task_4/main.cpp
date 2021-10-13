#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, D, x1, x2;
    cout << "enter a: ";
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    cout << "enter c: ";
    cin >> c;
    D = pow(b, 2)-4*a*c;
    if (D > 0) {
        x1 = (-b+sqrt(D))/(2*a);
        x2 = (-b-sqrt(D))/(2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        x1 = (-b/(2*a));
        cout << "x1 = x2 = " << x1 << endl;
    }
    else {
        double xr, xi;
        xr = (-b/(2*a));
        xi = abs(sqrt(abs(D))/(2*a));
        printf("x1 = %f + %fi\n", xr, xi);
        printf("x2 = %f - %fi", xr, xi);
    }
}

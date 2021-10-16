#include <iostream>

using namespace std;

int main() {
    int msk, num;
    bool rep = 0;
    cout << "netmask: 255.255.255.*" << endl;
    while (rep != 1) {
        rep = 1;
        cout << "enter *: ";
        cin >> msk;
        switch (msk) {
            case 255:
                num = 1;
                break;
            case 254:
                num = 2;
                break;
            case 252:
                num = 2;
                break;
            case 248:
                num = 8;
                break;
            case 240:
                num = 16;
                break;
            case 224:
                num = 32;
                break;
            case 192:
                num = 64;
                break;
            case 128:
                num = 128;
                break;
            case 0:
                num = 256;
                break;
            default:
                cout << "wrong number, try again." << endl;
                rep = 0;
        }
    }
    cout << "number of hosts: " << num;
}

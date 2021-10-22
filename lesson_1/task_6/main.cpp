#include <iostream>

using namespace std;

int main() {
    int mask;
    bool rep = 1;
    cout << "netmask: 255.255.255.*" << endl;
    while (rep != 0) {
        rep = 0;
        cout << "enter *: ";
        cin >> mask;
        switch (mask) {
            case 255: break;
            case 254: break;
            case 252: break;
            case 248: break;
            case 240: break;
            case 224: break;
            case 192: break;
            case 128: break;
            case 0: break;
            default:
                cout << "wrong number, try again." << endl;
                rep = 1;
        }
    }
    cout << "number of hosts: ";
    if (mask < 3) cout << 256-mask;
    else cout << 256-mask-2;
}

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
            case 255: cout << "number of hosts: " << 1; break;
            case 254: cout << "number of hosts: " << 2; break;
            case 252: cout << "number of hosts: " << 4; break;
            case 248: cout << "number of hosts: " << 8; break;
            case 240: cout << "number of hosts: " << 16; break;
            case 224: cout << "number of hosts: " << 32; break;
            case 192: cout << "number of hosts: " << 64; break;
            case 128: cout << "number of hosts: " << 128; break;
            case 0: cout << "number of hosts: " << 256; break;
            default:
                cout << "wrong number, try again." << endl;
                rep = 1;
        }
    }
}

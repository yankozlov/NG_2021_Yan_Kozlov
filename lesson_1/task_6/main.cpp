#include <iostream>

using namespace std;

int main() {
    cout << "netmask: 255.255.255.*" << endl;
    do {
        bool rep = 0;
        cout << "enter *: ";
        int mask = 0;
        cin >> mask;
	cout << "number of hosts: ";
        switch (mask) {
            case 255: cout << "1" << endl; break;
            case 254: cout << "2" << endl; break;
            case 252: cout << "2" << endl; break;
            case 248: cout << "6" << endl; break;
            case 240: cout << "14" << endl; break;
            case 224: cout << "30" << endl; break;
            case 192: cout << "62" << endl; break;
            case 128: cout << "126" << endl; break;
            case 0: cout << "254" << endl; break;
            default:
    	        cout << "undefined." << endl;
                cout << "wrong number, try again." << endl;
                rep = 1;
        } 
    } while (rep == 1);
}

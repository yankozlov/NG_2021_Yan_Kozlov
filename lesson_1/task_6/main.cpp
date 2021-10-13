#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int msk, num, cl, code[8] {0, 0, 0, 0, 0, 0, 0, 0};
    bool m = 0;
    cout << "netmask: 255.255.255.*" << endl;
    while (!m) {
        m = 1;
        cout << "enter *: ";
        cin >> msk;
        if (msk >= 0 && msk <= 255) {
            cl = 0;
            for (int i = 7, msk2 = msk; i >= 0; i--) {
                code[i] = msk2%2;
                msk2 /= 2;
                if (code[i] == 0) cl++;
            }
            for (int i = 0; i < 7; i++)
                if (code[i] < code[i+1]) {
                    m = 0;
                    break;
                }
            if (m != 0) {
                /*cout << "\t* = " << msk << endl; //
                for (int i = 0; i < 8; i++) cout << code[i] << " ";
                cout << endl;
                cout << "\tNetmask" << endl;
                cout << "11111111:11111111:11111111:";
                for (int i = 0; i < 8; i++) cout << code[i];
                cout << endl;*/
                if (msk == 255) num = 1;
                else if (msk == 254) num = 2;
                else num = pow(2, cl) - 2;
                cout << "number of hosts: " << num;
            }
            else cout << "wrong value, try again" << endl;
        }
        else {
            cout << "wrong value, try again" << endl;
            m = 0;
        }
    }
}

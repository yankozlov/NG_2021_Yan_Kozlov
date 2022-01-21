#include <iostream>

using namespace std;

int main()
{
    const int baseSize = 10;

    int accountPIN[baseSize];
    int accountMoney[baseSize];
    for (int i = 0; i < baseSize; i++) {
        accountMoney[i] = 0;
        accountPIN[i] = 0;
    }

    accountPIN[5] = 9876;

    int currentAccount = -1, currentPIN = -1;
    int option = -1, amount = 0;

    while (true) {
        cout << "Bank account: ";
        cin >> currentAccount;
        if (currentAccount < 0 || currentAccount >= baseSize) {
            cout << "The account with this number doesn't exist, try again." << endl;
        }
        else {
            cout << "PIN for account #" << currentAccount << ": ";
            cin >> currentPIN;

            if (currentPIN != accountPIN[currentAccount]) {
                cout << "Wrong PIN, try again." << endl;
            }
            else {
                while (true) {
                    system("clear");
                    cout << "Your money: " << accountMoney[currentAccount] << " $" << endl;
                    cout << "What can I do?" << endl <<
                            "1 - add money" << endl <<
                            "2 - withdraw money" << endl;
                    cin >> option;

                    switch (option) {
                        case 1:
                            while (true) {
                                cout << "Enter the amount: ";
                                cin >> amount;
                                if (amount < 0) {
                                    cout << "Incorrect input, try again." << endl;
                                }
                                else {
                                    accountMoney[currentAccount] += amount;
                                    break;
                                }
                            }
                            break;
                        case 2:
                            while (true) {
                                cout << "Enter the amount: ";
                                cin >> amount;
                                if (amount < 0) {
                                    cout << "Incorrect input, try again." << endl;
                                }
                                else {
                                    if (amount > accountMoney[currentAccount]) {
                                        cout << "Unable to withdraw, not enough money. Try again." << endl;
                                    }
                                    else {
                                        accountMoney[currentAccount] -= amount;
                                        break;
                                    }
                                }
                            }
                            break;
                        default:
                            cout << "Unknown option, try again." << endl;
                    }
                }
            }
        }
    }
}

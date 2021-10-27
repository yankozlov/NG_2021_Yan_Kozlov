#include <iostream>

#define baseSize 10

using namespace std;

int main()
{
    int accountPIN[baseSize];
    int accountMoney[baseSize];
    for (int i = 0; i < baseSize; i++) {
        accountMoney[i] = 0;
        accountPIN[i] = 0;
    }

    int currentAccount, currentPIN;
    int option, amount;

    while (true) {
        cout << "Bank account: ";
        cin >> currentAccount;
        if (currentAccount >= 0 && currentAccount < baseSize) {
            while (true) {
                cout << "PIN for account #" << currentAccount << ": ";
                cin >> currentPIN;
                if (currentPIN == accountPIN[currentAccount]) {
                    system("clear");
                    cout << "Your money: " << accountMoney[currentAccount] << " $" << endl;
                    cout << "What can I do?" << endl <<
                            "1 - add money" << endl <<
                            "2 - withdraw money" << endl <<
                            "3 - change PIN" << endl <<
                            "0 - quit" << endl;
                    cin >> option;
                    system("clear");

                    if (option == 1) {
                        while (true) {
                            cout << "Enter the amount: ";
                            cin >> amount;
                            if (amount >= 0) {
                                accountMoney[currentAccount] += amount;
                                break;
                            }
                            else {
                                cout << "Incorrect input, try again." << endl;
                            }
                        }
                    }

                    else if (option == 2) {
                        while (true) {
                            cout << "Enter the amount: ";
                            cin >> amount;
                            if (amount >= 0) {
                                if (amount < accountMoney[currentAccount]) {
                                    accountMoney[currentAccount] -= amount;
                                    break;
                                }
                                else {
                                    cout << "Unable to withdraw, not enough money. Try again." << endl;
                                }
                            }
                            else {
                                cout << "Incorrect input, try again." << endl;
                            }
                        }
                    }

                    else if (option == 3) {
                        cout << "Enter current PIN: ";
                        cin >> currentPIN;
                        if (currentPIN == accountPIN[currentAccount]) {
                            cout << "Enter new PIN: ";
                            cin >> accountPIN[currentAccount];
                            system("clear");
                        }
                        else {
                            cout << "Wrong PIN, try again later." << endl;
                        }
                    }

                    else if (option == 0) {
                        system("clear");
                        break;
                    }

                    else {
                        cout << "Unknown option, try again." << endl;
                    }
                }
                else {
                    cout << "Wrong PIN, try again." << endl;
                }
            }
        }
        else {
            cout << "The account with this number doesn't exist, try again." << endl;
        }
    }
}

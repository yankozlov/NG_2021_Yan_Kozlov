#include <iostream>

using namespace std;

const int baseSize = 10;

struct accountUnit {
    int PIN = 0;
    int money = 0;
};

int addMoney(int currAmount) {
    while (true) {
        int amount = 0;
        cout << "Enter the amount: ";
        cin >> amount;
        if (amount >= 0)
            return currAmount+amount;
        else
            cout << "Incorrect input, try again." << endl;
    }
    addMoney(currAmount);
}

int withdrawMoney(int currAmount) {
    while (true) {
        int amount = 0;
        cout << "Enter the amount: ";
        cin >> amount;
        if (amount >= 0)
            if (amount < currAmount)
                return currAmount-amount;
            else
                cout << "Unable to withdraw, not enough money. Try again." << endl;
        else
            cout << "Incorrect input, try again." << endl;
    }
    withdrawMoney(currAmount);
}

int changePIN(int currentPIN){
    while (true) {
        int userPIN = -1;
        cout << "Enter current PIN: ";
        cin >> userPIN;
        if (userPIN == currentPIN) {
            cout << "Enter new PIN: ";
            cin >> currentPIN;
            system("clear");
            return currentPIN;
        }
        else {
            cout << "Wrong PIN, try again later." << endl;
        }
    }
    changePIN(currentPIN);
}

bool auth(int accountNum, int accountPIN) {
    int userPIN = -1;
    cout << "PIN for account #" << accountNum << ": ";
    cin >> userPIN;
    if (userPIN >= 0 && userPIN == accountPIN)
        return true;
    else
        cout << "Wrong PIN, try again later." << endl << endl;
    return false;
}

void showBase(accountUnit accounts[]) {
    cout << endl;
    cout << "#\tmoney\tPIN" << endl;
    for (int i = 0; i < baseSize; i++)
        cout << i << "\t" << accounts[i].money << "\t" << accounts[i].PIN << endl;
    cout << endl;
}

accountUnit menu(accountUnit currAccount) {
    system("clear");
    int option = -1;
    cout << "Your money: " << currAccount.money << " $" << endl;
    cout << "What can I do?" << endl <<
            "1 - add money" << endl <<
            "2 - withdraw money" << endl <<
            "3 - change PIN" << endl <<
            "0 - quit" << endl;
    cin >> option;

    system("clear");
    switch (option) {
        case 1: currAccount.money = addMoney(currAccount.money);
                break;
        case 2: currAccount.money = withdrawMoney(currAccount.money);
                break;
        case 3: currAccount.PIN = changePIN(currAccount.PIN);
                break;
        case 0: return currAccount;
        default:cout << "Unknown option, try again." << endl;
    }

    menu(currAccount);
}

void atm(accountUnit accounts[]) {
    int currentAccount = -1;
    cout << "Bank account: ";
    cin >> currentAccount;

    if (currentAccount >= 0 && currentAccount < baseSize) {
        if (auth(currentAccount, accounts[currentAccount].PIN)==true)
            accounts[currentAccount] = menu(accounts[currentAccount]);
    }
    else
        cout << "The account with this number doesn't exist, try again." << endl;
    //showBase(account);

    atm(accounts);
}

int main() {
    accountUnit accounts[baseSize];
    atm(accounts);
}

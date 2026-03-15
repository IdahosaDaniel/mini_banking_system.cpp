#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    string name;
    double balance;
};

vector<Account> accounts;

// Function to find account index
int findAccount(string name) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].name == name) return i;
    }
    return -1;
}

void createAccount() {
    Account acc;
    cout << "Enter Account Name: ";
    cin >> acc.name;
    acc.balance = 0.0;
    accounts.push_back(acc);
    cout << "Account Created Successfully!\n";
}

void deposit() {
    string name;
    cout << "Enter Account Name: ";
    cin >> name;
    int idx = findAccount(name);
    if (idx == -1) { cout << "Account Not Found!\n"; return; }
    double amount;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;
    accounts[idx].balance += amount;
    cout << "Deposit Successful! New Balance: " << accounts[idx].balance << endl;
}

void withdraw() {
    string name;
    cout << "Enter Account Name: ";
    cin >> name;
    int idx = findAccount(name);
    if (idx == -1) { cout << "Account Not Found!\n"; return; }
    double amount;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;
    if (amount > accounts[idx].balance) {
        cout << "Insufficient Balance!\n";
        return;
    }
    accounts[idx].balance -= amount;
    cout << "Withdrawal Successful! New Balance: " << accounts[idx].balance << endl;
}

void checkBalance() {
    string name;
    cout << "Enter Account Name: ";
    cin >> name;
    int idx = findAccount(name);
    if (idx == -1) { cout << "Account Not Found!\n"; return; }
    cout << "Current Balance: " << accounts[idx].balance << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Mini Bank System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid Option!\n";
        }
    } while(choice != 5);
    return 0;
}

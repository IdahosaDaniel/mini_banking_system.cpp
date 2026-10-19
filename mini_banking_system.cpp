
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Account {
    string name;
    double balance;
};

vector<Account> accounts;

// Function to find an account by name
int findAccount(const string& name) {
    for (int i = 0; i < static_cast<int>(accounts.size()); i++) {
        if (accounts[i].name == name) {
            return i;
        }
    }
    return -1;
}

// Function to safely read a positive amount
bool getPositiveAmount(double& amount) {
    cout << "Enter amount: ";

    if (!(cin >> amount)) {
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    if (amount <= 0) {
        cout << "Invalid amount! Enter a positive amount.\n";
        return false;
    }

    return true;
}

// Create a new account
void createAccount() {
    Account acc;

    cout << "Enter Account Name: ";
    cin >> ws;
    getline(cin, acc.name);

    if (acc.name.empty()) {
        cout << "Account name cannot be empty!\n";
        return;
    }

    if (findAccount(acc.name) != -1) {
        cout << "An account with that name already exists!\n";
        return;
    }

    acc.balance = 0.0;
    accounts.push_back(acc);

    cout << "Account Created Successfully!\n";
}

// Deposit money
void deposit() {
    string name;

    cout << "Enter Account Name: ";
    cin >> ws;
    getline(cin, name);

    int idx = findAccount(name);

    if (idx == -1) {
        cout << "Account Not Found!\n";
        return;
    }

    double amount;

    if (!getPositiveAmount(amount)) {
        return;
    }

    accounts[idx].balance += amount;

    cout << fixed << setprecision(2);
    cout << "Deposit Successful! New Balance: "
         << accounts[idx].balance << '\n';
}

// Withdraw money
void withdraw() {
    string name;

    cout << "Enter Account Name: ";
    cin >> ws;
    getline(cin, name);

    int idx = findAccount(name);

    if (idx == -1) {
        cout << "Account Not Found!\n";
        return;
    }

    double amount;

    if (!getPositiveAmount(amount)) {
        return;
    }

    if (amount > accounts[idx].balance) {
        cout << "Insufficient Balance!\n";
        return;
    }

    accounts[idx].balance -= amount;

    cout << fixed << setprecision(2);
    cout << "Withdrawal Successful! New Balance: "
         << accounts[idx].balance << '\n';
}

// Check account balance
void checkBalance() {
    string name;

    cout << "Enter Account Name: ";
    cin >> ws;
    getline(cin, name);

    int idx = findAccount(name);

    if (idx == -1) {
        cout << "Account Not Found!\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Current Balance: "
         << accounts[idx].balance << '\n';
}

int main() {
    int choice;

    cout << fixed << setprecision(2);

    do {
        cout << "\n--- Mini Bank System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Option! Choose a number from 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}

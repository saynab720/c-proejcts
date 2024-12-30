#include <iostream>
#include <string>
#include <map>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Default constructor
    BankAccount()
        : accountHolder(""), accountNumber(0), balance(0.0) {}

    // Parameterized constructor
    BankAccount(string holder, int accNumber, double initialBalance = 0.0)
        : accountHolder(holder), accountNumber(accNumber), balance(initialBalance) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    // Display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Get account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

// Bank system class
class BankingSystem {
private:
    map<int, BankAccount> accounts;

public:
    // Create a new account
    void createAccount(const string& holder, int accNumber, double initialBalance = 0.0) {
        if (accounts.find(accNumber) == accounts.end()) {
            accounts[accNumber] = BankAccount(holder, accNumber, initialBalance);
            cout << "Account created successfully.\n";
        } else {
            cout << "Account number already exists.\n";
        }
    }

    // Access an existing account
    BankAccount* getAccount(int accNumber) {
        if (accounts.find(accNumber) != accounts.end()) {
            return &accounts[accNumber];
        } else {
            cout << "Account not found.\n";
            return nullptr;
        }
    }

    // Display all accounts
    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts available.\n";
        } else {
            for (const auto& pair : accounts) {
                pair.second.displayAccountDetails();
                cout << "-------------------\n";
            }
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\nBasic Banking System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account Details\n";
        cout << "5. Display All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string holder;
            int accNumber;
            double initialBalance;

            cout << "Enter account holder name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, holder);
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            bank.createAccount(holder, accNumber, initialBalance);
            break;
        }
        case 2: {
            int accNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accNumber;

            BankAccount* account = bank.getAccount(accNumber);
            if (account) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
            }
            break;
        }
        case 3: {
            int accNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accNumber;

            BankAccount* account = bank.getAccount(accNumber);
            if (account) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            }
            break;
        }
        case 4: {
            int accNumber;

            cout << "Enter account number: ";
            cin >> accNumber;

            BankAccount* account = bank.getAccount(accNumber);
            if (account) {
                account->displayAccountDetails();
            }
            break;
        }
        case 5:
            bank.displayAllAccounts();
            break;
        case 0:
            cout << "Exiting the system. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

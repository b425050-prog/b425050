#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    long long accountNumber;
    string accountHolderName;
    float balance;

public:
    void input() {
        cout << "Enter account number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter account holder name: ";
        getline(cin, accountHolderName);

        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal unsuccessful.\n";
        } else {
            balance = balance - amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void display() {
        cout << "\nAccount Details\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account;
    float depositAmount;
    float withdrawalAmount;

    account.input();

    cout << "Enter amount to deposit: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter amount to withdraw: ";
    cin >> withdrawalAmount;
    account.withdraw(withdrawalAmount);

    account.display();

    return 0;
}
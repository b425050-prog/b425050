// Lab 7, Problem 4: Banking System - Hierarchical Inheritance
// BankAccount -> SavingsAccount and CurrentAccount

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class BankAccount {
protected:
    string accountNumber; // A string preserves leading zeros.
    double balance;

public:
    BankAccount(const string& number, double amount)
        : accountNumber(number), balance(amount) {}

    double getBalance() const { return balance; }

    void display() const {
        cout << "Account number: " << accountNumber
             << "\nUpdated balance: " << fixed << setprecision(2) << balance << '\n';
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const string& number, double amount, double rate)
        : BankAccount(number, amount), interestRate(rate) {}

    void addInterest() {
        // Apply one period of interest. For example, input 5 means 5 percent.
        balance += balance * (interestRate / 100.0);
    }
};

class CurrentAccount : public BankAccount {
    double minimumBalance;
    double maintenanceCharge;

public:
    CurrentAccount(const string& number, double amount, double minimum, double charge)
        : BankAccount(number, amount), minimumBalance(minimum), maintenanceCharge(charge) {}

    bool deductMaintenanceCharge() {
        // "Below" is a strict comparison; equality does not trigger the charge.
        if (balance < minimumBalance) {
            balance -= maintenanceCharge;
            return true;
        }
        return false;
    }
};

int main() {
    string savingsNumber, currentNumber;
    double savingsBalance, rate, currentBalance, minimum, charge;
    cout << "Enter savings account number: ";
    if (!(cin >> savingsNumber)) return 1;
    cout << "Enter savings balance and interest rate (% for one period): ";
    if (!(cin >> savingsBalance >> rate) || !isfinite(savingsBalance)
        || !isfinite(rate) || savingsBalance < 0 || rate < 0) {
        cerr << "Enter a finite, non-negative balance and interest rate.\n";
        return 1;
    }
    cout << "Enter current account number: ";
    if (!(cin >> currentNumber)) return 1;
    cout << "Enter current balance, minimum balance, and maintenance charge: ";
    if (!(cin >> currentBalance >> minimum >> charge) || !isfinite(currentBalance)
        || !isfinite(minimum) || !isfinite(charge)
        || currentBalance < 0 || minimum < 0 || charge < 0) {
        cerr << "Enter finite, non-negative balances and charge.\n";
        return 1;
    }

    SavingsAccount savings(savingsNumber, savingsBalance, rate);
    CurrentAccount current(currentNumber, currentBalance, minimum, charge);
    savings.addInterest();
    const bool charged = current.deductMaintenanceCharge();
    if (!isfinite(savings.getBalance()) || !isfinite(current.getBalance())) {
        cerr << "A calculated balance is outside the supported numeric range.\n";
        return 1;
    }
    cout << "\nSavings account (interest added once)\n";
    savings.display();
    cout << "\nCurrent account\n";
    cout << (charged ? "Maintenance charge deducted.\n" : "No maintenance charge.\n");
    current.display();
    return 0;
}

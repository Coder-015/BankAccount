#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    static double bankFunds; // Static variable for total bank funds

public:
    // Constructor
    BankAccount(int accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
        bankFunds += initialBalance; // Update total bank funds
    }

    // Deposit function
    double deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            bankFunds += amount;
        }
        return balance;
    }

    // Withdraw function
    double withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            bankFunds -= amount;
        }
        return balance;
    }

    // Static method to get total bank funds
    static double getBankFunds() {
        return bankFunds;
    }
};

// Initialize static variable
double BankAccount::bankFunds = 0;

int main() {
    // Creating bank accounts
    BankAccount acc1(101, "raj", 1000);
    BankAccount acc2(102, "rohan", 2000);

    // Performing transactions
    cout << "New Balance (raj): $" << acc1.deposit(500) << endl;
    cout << "New Balance (rohan): $" << acc2.withdraw(1000) << endl;

    // Display total bank funds
    cout << "Total Bank Funds: $" << BankAccount::getBankFunds() << endl;

    return 0;
}

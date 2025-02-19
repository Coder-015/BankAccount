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
    
    string getHolderName() const{
        return accountHolder;
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
    BankAccount acc1(101, "Mayank", 1000);
    BankAccount acc2(102, "Tushar", 200000);

    // Performing transactions
    cout << "New Balance "<<acc1.getHolderName()<<": ₹" << acc1.deposit(50000) << endl;
    cout << "New Balance "<<acc2.getHolderName()<<": ₹" << acc2.withdraw(10050) << endl;

    // Display total bank funds
    cout << "Total Bank Funds: ₹" << BankAccount::getBankFunds() << endl;

    return 0;
}

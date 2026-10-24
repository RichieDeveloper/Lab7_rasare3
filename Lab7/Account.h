#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Customer.h"
using namespace std;

class Account {
private:
    string accountNumber;
    double balance;
    Customer owner;

    vector<double> deposits;
    vector<double> withdrawals;

    void printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const;

public:
    Account();
    Account(const string& accNum, double initialBalance, const Customer& customer);

    bool deposit(double amount);
    bool withdraw(double amount);

    void closeOfBusiness();

    double getBalance() const;
    string getAccountNumber() const;
    Customer getCustomer() const;

    void printAccountInfo() const;
    void printTransactions() const;
};

#endif

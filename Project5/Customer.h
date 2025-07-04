#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string customerName;
    double customerBalance;

public:
    Customer(string name, double balance)
        : customerName(name), customerBalance(balance) {
    }

    string getName() const {
        return customerName;
    }

    double getBalance() const {
        return customerBalance;
    }

    void deductBalance(double amount) {
        if (amount > customerBalance) {
            throw runtime_error("Insufficient balance.");
        }
        customerBalance -= amount;
    }
};

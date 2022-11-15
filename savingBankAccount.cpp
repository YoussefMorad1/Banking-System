// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "savingBankAccount.h"
#include <iostream>

void savingBankAccount::set_Balance(double b){
    if (b >= minBalance)
        balance = b;
    else {
        std::cout << "Balance must be greater than or equal minimum balance\n";
    }
}

savingBankAccount::savingBankAccount(double minB, double b) : bankAccount(b) {
    if (b >= minB) {
        minBalance = minB;
    } else {
        std::cout << "Wrong Input for Saving Bank Account!\n";
        is_valid = false;
    }
}

int savingBankAccount::withdraw(double amount) {
    if (balance - amount >= minBalance) {
        return bankAccount::withdraw(amount);
    } else {
        std::cout << "Sorry. This is more than what you can withdraw.\n";
        return 0;
    }
}


int savingBankAccount::deposit(double amount) {
    if (amount >= 100) {
        return bankAccount::deposit(amount);
    } else {
        std::cout << "Sorry. This is less than what you can deposit.\n";
        return 0;
    }
}


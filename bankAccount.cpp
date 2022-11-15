// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "bankAccount.h"
#include <iostream>
bankAccount::bankAccount(double b){
    if (b < 0) {
        std::cout << "Wrong Balance Input!\n";
        is_valid = false;
    } else {
        balance = b;
    }
}

void bankAccount::set_Balance(double b) {
    if (b < 0) {
        std::cout << "Wrong input for balance\n";
        is_valid = false;
    } else {
        balance = b;
    }
}

int bankAccount::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Sorry. This is more than what you can withdraw.\n";
        return 0;
    } else if (amount <= balance) {
        std::cout << "Thank you.\n";
        balance -= amount;
        std::cout << "New Balance: " << balance << std::endl;
        return 1;
    }
}

int bankAccount::deposit(double amount) {
    if (amount < 0) {
        std::cout << "Invalid input to deposit.\n";
        return 0;
    }
    balance += amount;
    std::cout << "New Balance: " << balance << std::endl;
    return 1;
}
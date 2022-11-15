#ifndef BANKING_SYSTEM_SAVINGBANKACCOUNT_H
#define BANKING_SYSTEM_SAVINGBANKACCOUNT_H
#include "bankAccount.h"



class savingBankAccount : public bankAccount {
private:
    double minBalance = 1000;

public:
    savingBankAccount() : bankAccount(1000) {}

    savingBankAccount(double b, double minB);

    double get_minBalance() {
        return minBalance;
    }

    virtual void set_Balance(double b);

    void set_minBalance(double minB) {
        minBalance = minB;
    }

    virtual int withdraw(double amount);

    virtual int deposit(double amount);

    virtual bool is_saving(){return true;}
};
#endif //BANKING_SYSTEM_SAVINGBANKACCOUNT_H

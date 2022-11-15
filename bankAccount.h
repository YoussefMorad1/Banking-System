#ifndef BANKING_SYSTEM_BANKACCOUNT_H
#define BANKING_SYSTEM_BANKACCOUNT_H

#include <string>

class client;

class bankAccount {
protected:
    std::string accountID;
    double balance;
    client *myclient = nullptr;
    bool is_valid = true;

public:
    bankAccount(double b);

    bankAccount() {
        balance = 0;
    }

    std::string get_ID() {
        return accountID;
    }

    double get_Balance() {
        return balance;
    }

    bool get_valid() {
        return is_valid;
    }


    void setClient(client &cl) {
        myclient = &cl;
    }

    void set_ID(long long id) {
        std::string tmp = std::to_string(id);
        while(tmp.size() < 3){
            tmp = '0' + tmp;
        }
        accountID = "FCAI-" + tmp;
    }

    virtual void set_Balance(double b);

    virtual int withdraw(double amount);

    int deposit(double amount);

    virtual bool is_saving(){return false;}
};

#endif //BANKING_SYSTEM_BANKACCOUNT_H

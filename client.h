#ifndef BANKING_SYSTEM_CLIENT_H
#define BANKING_SYSTEM_CLIENT_H

#include <string>
#include "bankAccount.h"
#include "savingBankAccount.h"

class client {
private:
    std::string name, address, phone;
    bankAccount *ptr;
public:
    client(std::string n, std::string a, std::string p) {
        name = n;
        address = a;
        phone = p;
    }
    void setAcc(bankAccount *p) {
        ptr = p;
    }
    std::string get_name(){
        return name;
    }
    std::string get_address(){
        return address;
    }
    std::string get_phone(){
        return phone;
    }
    bankAccount* get_account(){
        return ptr;
    }
};

#endif //BANKING_SYSTEM_CLIENT_H

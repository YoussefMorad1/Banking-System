#ifndef BANKING_SYSTEM_BANKAPPLICATION_H
#define BANKING_SYSTEM_BANKAPPLICATION_H
#include "bankAccount.h"
#include "client.h"
#include <vector>
#include <map>
#include <string>
class BankApplication {
private:
    std::vector<client> clients;
    std::vector<bankAccount> basic_accounts;
    std::vector<savingBankAccount> saving_accounts;
    long long id = 1;
    std::map<long long, client*> mp;
    long long idtoint(std::string ID);
    std::string getinput();
    bool showScreen();

    bool createAccount();

    void listAll();

    bool withdraw();

    bool deposit();
public:
    void runapp();
};
#endif //BANKING_SYSTEM_BANKAPPLICATION_H

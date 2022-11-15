<<<<<<< HEAD
// This is a personal academic project. Dear PVS-Studio, please check it.
=======
// 14/11/2022
#include <iostream>
#include <vector>
>>>>>>> 652324fcc4b8244a0ad5101b12d3825dd906c940

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include "BankApplication.h"
using namespace std;

<<<<<<< HEAD
int main() {
    BankApplication bank1;
    while(bank1.showScreen()) {
    ;
    }
}
=======
class client {
private:
    string name, address, phone;
    bankAccount *ptr;
public:
    client(string n, string a, string p) {
        name = n;
        address = a;
        phone = p;
    }

    void setAcc(bankAccount *p) {
        ptr = p;
    }
    string get_name(){
        return name;
    }
    string get_address(){
        return address;
    }
    string get_phone(){
        return phone;
    }
    bankAccount* get_account(){
        return ptr;
    }
};

class bankAccount {
protected:
    string accountID;
    double balance;
    client *myclient = nullptr;
    bool is_valid = true;

public:
    bankAccount(double b) {
        if (b < 0) {
            cout << "Wrong Balance Input!\n";
            is_valid = false;
        } else {
            balance = b;
        }
    }

    bankAccount() {
        balance = 0;
    }

    string get_ID() {
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
        string tmp = tostring(id); 
        while(tmp.size() < 3){
            tmp = '0' + tmp; 
        }
        accountID = "FCAI-" + tmp;
    }

    virtual void set_Balance(double b) {
        if (b < 0) {
            cout << "Wrong input for balance\n";
            is_valid = false;
        } else {
            balance = b;
        }
    }

    virtual int withdraw(double amount);

    int deposit(double amount);

    virtual bool is_saving{return false;}
};

int bankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Sorry. This is more than what you can withdraw.\n";
        return 0;
    } else if (amount <= balance) {
        cout << "Thank you.\n";
        balance -= amount;
        cout << "New Balance: " << Balance << endl;
        return 1;
    }
}

int bankAccount::deposit(double amount) {
    if (amount < 0) {
        cout << "Invalid input to deposit.\n";
        return 0;
    }
    balance += amount;
    cout << "New Balance: " << Balance << endl;
    return 1;
}

class savingBankAccount : public bankAccount {
private:
    double minBalance = 1000;

public:
    savingBankAccount() : bankAccount(1000) {}

    savingBankAccount(double b, double minB);

    double get_minBalance() {
        return minBalance;
    }

    virtual void set_Balance(double b) {
        if (b >= minBalance)
            balance = b;
        else {
            cout << "Balance must be greater than or equal minimum balance\n";
        }
    }

    void set_minBalance(double minB) {
        minBalance = minB;
    }

    virtual int withdraw(double amount);

    virtual int deposit(double amount);

    virtual bool is_saving{return true;}
};

savingBankAccount::savingBankAccount(double b, double minB) : bankAccount(b) {
    if (b >= minB) {
        minBalance = minB;
    } else {
        cout << "Wrong Input for Saving Bank Account!\n";
        is_valid = false;
    }
}

int savingBankAccount::withdraw(double amount) {
    if (balance - amount >= minBalance) {
        return bankAccount::withdraw(amount);
    } else {
        cout << "Sorry. This is more than what you can withdraw.\n";
        return 0;
    }
}


int savingBankAccount::deposit(double amount) {
    if (amount >= 100) {
        return bankAccount::deposit(amount);
    } else {
        cout << "Sorry. This is less than what you can deposit.\n";
        return 0;
    }
}


class BankApplication {

private:
    vector<client> clients;
    vector<bankAccount *> accounts;
    long long id = 0;
    map<long long, client*> mp;
    long long idtoint(string ID);
    string getinput();
public:
    void showScreen();

    bool createAccount();

    void listAll();

    void withdraw();

    void deposit();

};

bool BankApplication::createAccount() {
    string name, address, phone;
    cout << "Please Enter Client Name\n";
    getline(cin, name);
    cout << "Please Enter Client Address\n";
    getline(cin, address);
    cout << "Please Enter Client Phone Number\n";
    cin >> phone;

    client newClient(name, address, phone);
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2:\n";

    string choice;
    cin >> choice;

    if (choice == "1") {
        // fill account -> pair it to client -> save the account
        double balance;
        cout << "Please Enter the Starting Balance\n";
        cin >> balance;
        // create basic account with the balance
        bankAccount newAcc(balance);
        // if account's data is wrong return false
        if(!newAcc.get_valid()){
            cout << "Something wrong happened, Try Again!\n";
            return false;
        }
        // add the newClient data to my dataBase
        clients.push_back(newClient);
        // pair the id to the client
        mp[id] = &clients.back();
        // make the account's pointer refers to -> my dataBase's newClient
        newAcc.setClient(clients.back());
        // add the newAccount to my dataBase
        accounts.push_back(&newAcc);
        // make the dataBase's client pointer refers to -> my dataBase's newAccount
        clients.back().setAcc(accounts.back());
        // put the id inside the client data
        accounts.back().set_ID(id++);
        return true;
    }
    else if (choice == "2") {
        // fill account -> pair it to client -> save the account
        double balance, minBalance;
        cout << "Please Enter the minimum Balance\n";
        cin >> minBalance;
        cout << "Please Enter the Starting Balance\n";
        cin >> balance;
        // create saving account with the balance and minBalance
        savingBankAccount newAcc(minBalance, balance);
        // if account's data is wrong return false
        if(!newAcc.get_valid()){
            cout << "Something wrong happened, Try Again!\n";
            return false;
        }
        // add the newClient data to my dataBase
        clients.push_back(newClient);
        // pair the id to the client
        mp[id] = &clients.back();
        // make the account's pointer refers to -> my dataBase's newClient
        newAcc.setClient(clients.back());
        // add the newAccount to my dataBase
        accounts.push_back(&newAcc);
        // make the dataBase's client pointer refers to -> my dataBase's newAccount
        clients.back().setAcc(accounts.back());
        // put the id inside the client data
        accounts.back().set_ID(id++);
        return true;
    }
    else{
        cout << "No Account was created\n";
        return false;
    }
}

void BankApplication::listAll(){
    for(auto cl : clients){
        cout << cl.get_name() << endl;
        cout << "Address: " << cl.get_address() << endl;
        cout << "Phone: " << cl.get_phone() << endl;
        cout << "Account ID: " << cl.get_account()->get_ID() << "\t";
        if(is_saving)
            cout << '(' << "SavingAccount" << ')' << endl;
        else
            cout << '(' << "Basic" << ')' << endl;
        cout << "Balance: " << cl.get_Balance() << endl;
        cout << string(50, '-') << endl;
    }
}

long long BankingApplication::idtoint(string ID){
    string strt = "FCAI-";
    int ct = 0;
    for(int i = 0; i < min(5, ID.size()); ++i){
        if(ID[i] == strt[i])
            ct++;
    }
    if(ct != 5){
        return -1;
    }
    string num = ID.substr(5, Id.size() - 5);
    for(int i = 0; i < num.size(); ++i){
        if(!isdigit(num[i])){
            return -1;
        }
    }
    return stoll(num);
}


bool BankApplication::withdraw() {
    cout << "Please Enter Account ID\n";
    string ID;
    cin >> ID;
    long long idnum = idtoint(ID);
    
    if(idnum == -1){
       cout << "Withdraw failed!\n";
       return false; 
    }    


    bankAccount* acc = mp[idnum].get_account();

    cout << "Account ID: " << ID << endl;
    if(is_saving)
        cout << "Acocunt Type: " << '(' << "SavingAccount" << ')' << endl;
    else
        cout << "Acocunt Type: " << '(' << "Basic" << ')' << endl;
    cout << "Balance: " << acc->get_Balance() << endl;
    cout << "Please Enter The Amount to Withdraw:\n";
    double amount;
    cin >> amount;
    return acc.withdraw(amount);
}


bool BankApplication::deposit(){
    string ID;
    cout << "Please enter Account ID:";
    cin >> ID;
    
    long long numID = idtoint(ID);
    if(numID == -1){
        cout << "Deposit failed!\n";   
        return false;
    }

    cout << "Account ID: " << ID << endl;
    // map< id, bankAccount* > 
    bankAccount* curAcc = mp[numID]; // pointer to bankAccount 
    
  
    if (curAcc -> is_saving() == 1){
         cout << "Account Type: "<< "Saving\n";
    }
    else{
        cout << "Account Type: "<< "Basic\n";
    }

    cout << "Balance: " << curAcc -> get_Balance() << "\n";
    double amount;
    cout << "Please enter the amount to deposit:\n";
    cin >> amount;
    return curAcc -> deposit(amount);
}


void BankingAccount::showScreen() {
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "5. Exit\n";
    string choice = getinput();
    if(choice == "*"){
        cout << "Invalid Input!\n";
    }
    if(choice == "1")
        createAccount();
    else if(choice == "2")
        listAll();
    else if(choice == "3")
        withdraw();
    else if(choice == "4")
        deposit();
}

string getinput() {
    string choice;
    cin >> choice;
    if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
        return choice;
    else
        return "*";
}

int main() {
    savingBankAccount myAcc("a");
}
>>>>>>> 652324fcc4b8244a0ad5101b12d3825dd906c940

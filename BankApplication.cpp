// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "BankApplication.h"
#include "savingBankAccount.h"
#include <iostream>

using namespace std;

bool BankApplication::createAccount() {
    string name, address, phone;
    cout << "Please Enter Client Name\n";
    getline(cin >> ws, name);
    cout << "Please Enter Client Address\n";
    getline(cin >> ws, address);
    cout << "Please Enter Client Phone Number\n";
    cin >> phone;

    client newClient(name, address, phone);
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2:\n";

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
        if (!newAcc.get_valid()) {
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
        basic_accounts.push_back(newAcc);
        // make the dataBase's client pointer refers to -> my dataBase's newAccount
        clients.back().setAcc(&basic_accounts.back());
        // put the id inside the client data
        basic_accounts.back().set_ID(id++);
        return true;
    } else if (choice == "2") {
        // fill account -> pair it to client -> save the account
        double balance, minBalance;
        cout << "Please Enter the minimum Balance\n";
        cin >> minBalance;
        cout << "Please Enter the Starting Balance\n";
        cin >> balance;
        // create saving account with the balance and minBalance
        savingBankAccount newAcc(minBalance, balance);
        // if account's data is wrong return false
        if (!newAcc.get_valid()) {
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
        saving_accounts.push_back(newAcc);
        // make the dataBase's client pointer refers to -> my dataBase's newAccount
        clients.back().setAcc(&saving_accounts.back());
        // put the id inside the client data
        saving_accounts.back().set_ID(id++);
        return true;
    } else {
        cout << "No Account was created\n";
        return false;
    }
}

void BankApplication::listAll() {
    for (auto cl: clients) {
        cout << "Name: " << cl.get_name() << endl;
        cout << "Address: " << cl.get_address() << endl;
        cout << "Phone: " << cl.get_phone() << endl;
        cout << "Account ID: " << cl.get_account()->get_ID() << "\t";
        if (cl.get_account()->is_saving())
            cout << '(' << "SavingAccount" << ')' << endl;
        else
            cout << '(' << "Basic" << ')' << endl;
        cout << "Balance: " << cl.get_account()->get_Balance() << endl;
        cout << string(50, '-') << endl;
    }
}

long long BankApplication::idtoint(string ID) {
    string strt = "FCAI-";
    int ct = 0;
    for (int i = 0; i < min(5, (int) ID.size()); ++i) {
        if (ID[i] == strt[i])
            ct++;
    }
    if (ct != 5) {
        return -1;
    }
    string num = ID.substr(5, ID.size() - 5);
    for (int i = 0; i < num.size(); ++i) {
        if (!isdigit(num[i])) {
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

    if (idnum == -1) {
        cout << "Withdraw failed!\n";
        return false;
    }


    bankAccount *acc = mp[idnum]->get_account();

    cout << "Account ID: " << ID << endl;
    if (acc->is_saving())
        cout << "Account Type: " << '(' << "SavingAccount" << ')' << endl;
    else
        cout << "Account Type: " << '(' << "Basic" << ')' << endl;
    cout << "Balance: " << acc->get_Balance() << endl;
    cout << "Please Enter The Amount to Withdraw:\n";
    double amount;
    cin >> amount;
    return acc->withdraw(amount);
}


bool BankApplication::deposit() {
    string ID;
    cout << "Please enter Account ID:";
    cin >> ID;

    long long numID = idtoint(ID);
    if (numID == -1) {
        cout << "Deposit failed!\n";
        return false;
    }

    cout << "Account ID: " << ID << endl;
    // map< id, bankAccount* >
    bankAccount *curAcc = mp[numID]->get_account(); // pointer to bankAccount


    if (curAcc->is_saving() == 1) {
        cout << "Account Type: " << "Saving\n";
    } else {
        cout << "Account Type: " << "Basic\n";
    }

    cout << "Balance: " << curAcc->get_Balance() << "\n";
    double amount;
    cout << "Please enter the amount to deposit:\n";
    cin >> amount;
    return curAcc->deposit(amount);
}


bool BankApplication::showScreen() {
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "5. Exit\n";
    string choice = getinput();
    if (choice == "*") {
        cout << "Invalid Input!\n";
    }
    if (choice == "1")
        createAccount();
    else if (choice == "2")
        listAll();
    else if (choice == "3")
        withdraw();
    else if (choice == "4")
        deposit();
    else
        return false;
    return true;
}

string BankApplication::getinput() {
    string choice;
    cin >> choice;
    if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
        return choice;
    else
        return "*";
}

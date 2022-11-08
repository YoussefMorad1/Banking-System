#include <iostream>
#include <vector>

using namespace std;

// write your class client here pls






class BankApplication {

private:
    vector<client> clients;
public:
    bool createAccount();

    void listAll();

    void withdraw();

    void deposit();
};

bool BankApplication::createAccount(){
    string name, string address, string phone;
    cout << "Please Enter Client Name\n";
    cin >> name;
    cout << "Please Enter Client Address\n";
    cin >> address;
    cout << "Please Enter Client Phone Number\n";
    cin >> phone;
    client newClient(name, address, phone);
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2:\n";

    string choice;
    cin >> choice;
    if(choice == "1"){
        bankAccount* basic = new bankAccount;
        cout << "Please Enter the Starting Balance:\n";
        double balance;
        cin >> balance;
        basic->set_Balance(balance);
        if(basic.get_valid()){
            newClient.setAcc(basic);
            clients.push_back(newClient);
            basic->setAcc(client.back());
        }
        else{
            cout << "Something wrong happened, Try Again!\n";
            return false;
        }
    }
    else if(choice == "2"){
        savingBankAccount Saving;
        cout << "Please Enter minBalance:\n";
        double minBalance;
        cin >> minBalance;
        Saving.set_minBalance(minBalance);
        cout << "Please Enter the Starting Balance:\n";
        double balance;
        cin >> balance;
        Saving.set_Balance(balance);
    }
    else{
        cout << "No Account was created\n";
        return 0;
    }
}

void BankApplication::withdraw(){
    bankAccount Acc;
    cout << "Please Enter Account ID\n";
    string ID;
    cin >> ID;
    Acc.set_ID(ID);
    cout << "Account ID: " << ID;
    cout << "Account Type: " <<  ;
    cout << "Balance: " << get_Balance;
    cout << "Please Enter The Amount to Withdraw = ";
    double amount;
    cin >> amount;



}


void showScreen(){
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "5. Exit\n";
}

string getinput(){
    string choice;
    cin >> choice;
    if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
        return choice;
    else
        return "*";
}


class bankAccount {
protected:
    string accountID;
    double balance;
    bool is_valid = true;
    client *myclient = nullptr;

public:
    bankAccount(double b){
        if(b < 0){
            cout << "Wrong Balance Input!\n";
            is_valid = false;
        }
        balance = b;
    }

    bankAccount(){
        balance = 0;
    }

    void setClient(client& cl){
        myclient = &cl;
    }

    string get_ID(){
        return accountID;
    }

    double get_Balance(){
        return balance;
    }

    void set_ID(string id){
        accountID = id;
    }

    virtual void set_Balance(double b){
        if(b < 0){
            cout << "Wrong input for balance\n";
            is_valid = false;
        }
        balance = b;
    }

    bool get_valid(){
        return is_valid;
    }

    virtual int withdraw(double amount);

    int deposit(double amount);
};

int bankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Sorry. This is more than what you can withdraw.\n";
        return 0;
    } else if (amount <= balance) {
        cout << "Thank you.\n";
        balance -= amount;
        return 1;
    }
}

int bankAccount::deposit(double amount) {
    if (amount < 0) {
        cout << "Invalid input to deposit.\n";
        return 0;
    }
    balance += amount;
    return 1;
}

class savingBankAccount : public bankAccount {
private:
    double minBalance;

public:
    savingBankAccount() : bankAccount(1000) {
        minBalance = 1000;
    }

    savingBankAccount(double b, double minB);

    double get_minBalance() {
        return minBalance;
    }

    virtual void set_Balance(double b){
        if(b >= minBalance)
            balance = b;
        else{
            cout << "Balance must be greater than or equal minimum balance\n";
            is_valid = false;
        }
    }

    void set_minBalance(double minB) {
        minBalance = minB;
    }

    virtual int withdraw(double amount);

    virtual int deposit(double amount);

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
int main(){
    savingBankAccount myAcc("a");
}
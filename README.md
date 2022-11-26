# Banking-System
 
We Modeled, Designe and Developed a Banking Application..  

The System is divided into 4 classes:
* Client Class: holds the basic information of a client like his name, address and phone number. It holds a pointer to his bank account.
* BankAccount Class: holds the accountID, the balance in the account and a pointer to the account's client
* SavingBankAccoun Class: it's a BankAccount but has more restrictions when client withdraws and deposits and it has minimum balance
* BankingApplication Class: This is the main class that runs the application. This class displays the main menu and accepts the user's choice. It maintains a list of accounts and clients. It allows the user to perform operations on a bank account.


The banking application allows the user (the bank employee) to:
* Create a bank account for a specific client.
* List all the available bank accounts.
* For each account, it allows him to display the account details, withdraw money and deposit money


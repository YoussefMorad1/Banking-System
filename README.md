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

The Class Diagram
![Untitled (1)](https://user-images.githubusercontent.com/102534922/204098109-eaa1dde2-8dfa-4164-b404-b9f698d00c49.png)

The Goal of this project is to:
* Practice Object-Oriented-Programming concepts using C++ (Inheretance - Composition - Encapsulation - Abstraction - etc..) 
* Practice building systems using OOP modeling and design with C++
* Practice working in a team and integrating the code together to come up with a final working program


## Versions:
Version 1 (current):  
The system saves the clients and accounts only in Run-Time 

Version 2 (upcoming):  
The system uses a dataBase to save the client and accounts data

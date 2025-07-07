#pragma once
#include "Person.h"

class Client : public Person
{
private:
    // Attributes :
    double balance;
public:
    // Default constructor
    Client();

    // Parameterized Constructor
    Client(string name, string password, double balance);
    // Parameterized Constructor
    Client(int id, string name, string password, double balance);
    // Setters
    void setBalance(double balance);

    // Getters
    double getBalance();

    // A method to deposit money into the client's account
    void deposit(double amount);

    // A method to withdraw money from the client's account
    void withdraw(double amount);

    // A method to transfer money from one client's account to another
    void transferTo(double amount, Client &recipient);

    // A method to check the budget after any transfer, withdrawal or deposit
    void checkBalance();

    // Mehode to display client information
    virtual void displayInfo() override;
    // static member
    static vector<Client> allClients;
    static vector<Client>::iterator itClient;
};



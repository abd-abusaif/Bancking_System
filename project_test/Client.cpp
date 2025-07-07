    #include "Client.h"


    // Default constructor
    Client::Client()
        : balance(0)
    {}

    // Parameterized Constructor
    Client::Client(string name, string password, double balance)
        :Person(name, password), balance(0)
    {
        if (Validation::isValidBalance(balance))
        {
            this->balance = balance;
        }
    }
    // Parameterized Constructor
    Client::Client(int id, string name, string password, double balance)
        : Person(id, name, password), balance(0)
    {
        if (Validation::isValidBalance(balance))
        {
            this->balance = balance;
        }
    }

    // Setters
    void Client::setBalance(double balance)
    {
        if (Validation::isValidBalance(balance))
        {
            this->balance = balance;
        }
    }

    // Getters
    double Client::getBalance()
    {
        return balance;
    }

    // A method to deposit money into the client's account
    void Client::deposit(double amount)
    {
        if (amount >= 0) {
            balance += amount;
        }
        else
        {
            cout << "The amount you entered is invalid.\n";
        }
    }

    // A method to withdraw money from the client's account
    void Client::withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. Your remaining balance is: " << balance << ".\n";
        }
        else
        {
            cout << "Insufficient funds in your account to perform this transaction.\n";
        }
    }

    // A method to transfer money from one client's account to another
    void Client::transferTo(double amount, Client& recipient)
    {
        if (amount <= balance)
        {
            balance -= amount;
            recipient.deposit(amount);
            cout << "\nTransfer successful. Your remaining balance is: " << balance << ".\n";
        }
        else
        {
            cout << "Insufficient funds in your account to perform this transaction.\n";
        }
    }

    // A method to check the budget after any transfer, withdrawal or deposit
    void Client::checkBalance()
    {
        cout << "Your account balance is : " << balance << endl;
    }

    // Mehode to display client information
    void Client::displayInfo()
    {
        cout << "\n|=============== Inforamtion Client ===============|\n\n";
        cout << "ID" << setw(9) << ":" << id << endl;
        cout << "Name" << setw(7) << ":" << name << endl;
        cout << "Password" << setw(3) << ":" << password << endl;
        cout << "Balance" << setw(4) << ":" << balance << endl;
    }
    vector<Client>Client::allClients;
    vector<Client>::iterator Client::itClient;
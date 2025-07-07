#pragma once
#include <iostream>
#include "FilesHelper.h"
#include "Validation.h"

class FillData
{
public:


    // A method to ensure that the name entered by the user is valid
    static string enterName()
    {
        string name;
        cout << "Please enter a valid username (8 to 20 letters): ";
        cin.ignore();
        getline(cin, name);

        while (!Validation::isValidName(name))
        {
            cout << "\nInvalid username. It must be between 8 and 20 characters long and contain only letters.\n";
            cout << "\nPlease enter a valid username: ";
            getline(cin, name);
        }
        cout << endl;
        return name;
    }

    // A method to ensure that the password entered by the user is valid
    static string enterPassword()
    {
        string password;
        cout << "Please enter your password (8 to 20 characters, no spaces,\n";
        cout << "at least one uppercase letter, one lowercase letter, and one number): ";
        cin >> password;

        while (!Validation::isValidPassword(password))
        {
            cout << "\nPlease enter your password (8 to 20 characters, no spaces,\n";
            cout << "at least one uppercase letter, one lowercase letter, and one number): ";
            cout << "\nEnter a valid password : ";
            cin >> password;
        }
        cout << endl;
        return password;
    }

    // A method to ensure that the salary entered by the user is valid
    static double enterSalary()
    {
        double salary;

        cout << "\nPlease enter your salary (minimum 5000): ";
        cin >> salary;

        while (!Validation::isValidSalary(salary))
        {
            cout << "\nSalary must be at least 5000.\nPlease enter a valid salary: ";
            cin >> salary;
        }
        cout << endl;
        return salary;
    }

    // A method to ensure that the balance entered by the user is valid
    static double enterBalance()
    {
        double balance;

        cout << "\nPlease enter your balance (minimum 1500): ";
        cin >> balance;

        while (!Validation::isValidBalance(balance))
        {
            cout << "\nBalance must be at least 1500.\nPlease enter a valid balance: ";
            cin >> balance;
        }
        cout << endl;
        return balance;
    }
};
#pragma once
#include <ctype.h>
#include <string>
using namespace std;


class Validation
{
private:
    // Method to check name length
    static bool isLengthName(const string& name)
    {
        return (name.length() >= 5 && name.length() <= 20);
    }

    // A method to verify that the name contains only letters and numbers
    static bool isAlpha(const string& name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            if (!(isalpha(name[i]) || isspace(name[i])))
            {
                return false;
            }
        }
        return true;
    }

    ////Method to check password length
    static bool isLengthPassword(const string& password)
    {
        return (password.length() >= 8 && password.length() <= 20);
    }

    // Method to verify that the password does not contain spaces
    static bool isNotSpace(string c)
    {
        for (int i = 0; i < c.size(); i++)
        {
            if (isspace(c[i]))
            {
                return false;
            }
        }
        return true;
    }

public:
    // A method to verify that the name contains only letters and is between 5 and 20 characters long
    static bool isValidName(string name)
    {
        return (isAlpha(name) && isLengthName(name));
    }

    // Method to verify that the password does not contain spaces and that its length is between 8 and 20
    static bool isValidPassword(string password)
    {
        return (isLengthPassword(password) && isNotSpace(password));
    }

    // Method to check that minimum salary
    static bool isValidSalary(double salary)
    {
        return (salary >= 5000);
    }

    // Method to check that minimum balance
    static bool isValidBalance(double balance)
    {
        return (balance >= 1500);
    }
};



#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Validation.h"
using namespace std;


class Person
{
protected:
    // Attributes
    string name, password;
    int id;

public:
    //Default constructor
    Person() : id(0)
    {}

    Person(string name, string password)
        :id(0)
    {
        if (Validation::isValidName(name))
        {
            this->name = name;
        }

        if (Validation::isValidPassword(password))
        {
            this->password = password;
        }
    }
    // Parametrized constructor
    Person(int id, string name, string password)
        : id(id)
    {
        if (Validation::isValidName(name))
        {
            this->name = name;
        }

        if (Validation::isValidPassword(password))
        {
            this->password = password;
        }
    }

    // Setters

    void setID(int id) {
        this->id = id;
    }
    void setName(string name)
    {
        if (Validation::isValidName(name))
        {
            this->name = name;
        }
    }

    void setPassword(string password)
    {

        if (Validation::isValidPassword(password))
        {
            this->password = password;
        }
    }

    // Getters

    string getName()
    {
        return name;
    }

    string getPassword()
    {
        return password;
    }

    int getID()
    {
        return id;
    }

    //Methods
    virtual void displayInfo() = 0;

};
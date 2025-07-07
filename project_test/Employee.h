#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
using namespace std;
class Employee : public Person
{
protected:
    // Attributes :
    double salary;

public:

    // Default constructor
    Employee();

    // Parameterized constructor :
    Employee(string name,string password, double salary);

    // Parameterized Constructor
    Employee(int id, string name, string password, double salary);
    // Setter salary
    void setSalary(double salary);

    // Setter salary

    double getSalary();
    // Methods
    void addClient(Client &client);
    Client *searchClient(int id);

    void listClient();

    void editClient(int id, string name, string password, double balance);

    // Method A display Inforamtion Employee
    virtual void displayInfo() override;


    // Static member
    static vector<Employee> allEmployees;
    static vector<Employee>::iterator itEmployee;
};




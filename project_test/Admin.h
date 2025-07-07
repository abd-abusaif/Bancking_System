#pragma once
#include "Employee.h"
using namespace std;
class Admin : public Employee
{
public:
 
    //Default Constructor
    Admin();

    // Parameterized Constructor
    Admin(string name, string password, double salary);

    // Parameterized Constructor
    Admin(int id, string name, string password, double salary);

    //Methods
    void addEmployee(Employee& employee);

    Employee* searchEmployee(int id) ;

    void editEmployee(int id, string name, string password, double salary) ;

    void listEmployee() ;


    // Methos Display Inforamtion Admin
    void displayInfo() override;

    // static member
    static vector<Admin> allAdmins;
    static vector<Admin>::iterator itAdmin;

};




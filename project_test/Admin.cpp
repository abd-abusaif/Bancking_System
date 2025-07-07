    #include "Admin.h"

    //Default Constructor
    Admin::Admin()
    {}

    // Parameterized Constructor
    Admin::Admin(string name, string password, double salary)
        :Employee(name, password, salary)
    {}

    // Parameterized Constructor
    Admin::Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary)
    {}
     
    //Methods
    void Admin::addEmployee(Employee& employee) {
        allEmployees.push_back(employee);
    }

    Employee* Admin::searchEmployee(int id) {

        for (itEmployee = allEmployees.begin(); itEmployee != allEmployees.end(); itEmployee++) {

            if (id == itEmployee->getID()) {
                return &(*itEmployee);
            }
        }
        return nullptr;
    }

    void Admin::editEmployee(int id, string name, string password, double salary) {

    Employee* employee = searchEmployee(id);

        employee->setName(name);
        employee->setPassword(password);
        employee->setSalary(salary);
    }
    void Admin::listEmployee() {
        for (itEmployee = allEmployees.begin(); itEmployee != allEmployees.end(); itEmployee++) {
            itEmployee->displayInfo();
        }
    }

    // Methos Display Inforamtion Admin
    void Admin::displayInfo()
    {
        cout << "\n|=============== Inforamtion Admin ===============|\n\n";
        cout << "ID" << setw(9) << ":" << id << endl;
        cout << "Name" << setw(7) << ":" << name << endl;
        cout << "Password" << setw(3) << ":" << password << endl;
        cout << "Salary" << setw(5) << ":" << salary << endl;
        cout << "\n|=====================================================|\n\n";
    }
    // static member
    std::vector<Admin> Admin::allAdmins;
   std::vector<Admin>::iterator Admin::itAdmin;

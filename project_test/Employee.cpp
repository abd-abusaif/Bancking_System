    #include "Employee.h"

    Employee::Employee()
        : salary(0)
    {}


    Employee::Employee(string name, string password, double salary)
        :Person(name, password), salary(0)
    {
        if (Validation::isValidSalary(salary)) {
            this->salary = salary;
        }

    }


    Employee::Employee(int id, string name, string password, double salary)
        : Person(id, name, password), salary(0)
    {
        if (Validation::isValidSalary(salary))
        {
            this->salary = salary;
        }
    }


    void Employee::setSalary(double salary)
    {
        if (Validation::isValidSalary(salary))
        {
            this->salary = salary;
        }
    }


    double Employee::getSalary()
    {
        return salary;
    }


    void Employee::addClient(Client& client)
    {

        Client::allClients.push_back(client); // note
    }


    Client* Employee::searchClient(int id)
    {

        for (Client::itClient = Client::allClients.begin(); Client::itClient != Client::allClients.end(); Client::itClient++)
        {

            if (id == Client::itClient->getID())
            {

                return &(*Client::itClient);
            }
        }

        return nullptr;
    }


    void Employee::listClient()
    {

        for (Client::itClient = Client::allClients.begin(); Client::itClient != Client::allClients.end(); Client::itClient++)
        {

            Client::itClient->displayInfo();
        }
    }


    void Employee::editClient(int id, string name, string password, double balance)
    {

        Client* client = searchClient(id);

        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);
    }


    void Employee::displayInfo() 
    {
        cout << "\n|=============== Inforamtion Employee ===============|\n\n";
        cout << "ID" << setw(9) << ":" << id << endl;
        cout << "Name" << setw(7) << ":" << name << endl;
        cout << "Password" << setw(3) << ":" << password << endl;
        cout << "Salary" << setw(5) << ":" << salary << endl;
        cout << "\n--------------------------------------------------------\n";
    }

    vector<Employee> Employee::allEmployees;
    vector<Employee>::iterator Employee::itEmployee;
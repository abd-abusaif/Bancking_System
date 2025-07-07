#pragma once
#include "Employee.h"
#include "Client.h"
#include "FileManager.h"
#include "FillData.h"
class EmployeeManager{
private:
	static void printEmployeeMenu() {
		cout << "(1)View my information" << endl;
		cout << "(2)Add a new client" << endl;
		cout << "(3)Search for a client" << endl;
		cout << "(4)Edit client information" << endl;
		cout << "(5)View all clients" << endl;
		cout << "(6)Update password" << endl;
 		cout << "(7)logout" << endl;
	}

	static void newClient(Employee* employee)
	{
		system("cls");
		cout << "------------------New Client------------------\n";
		string name, password;
		double balance;

		name = FillData::enterName();
		password = FillData::enterPassword();
		balance = FillData::enterBalance();
		int id = FilesHelper::getLast(CLIENT_LAST_ID ) + 1;

		system("cls");
		Client client(id,name, password, balance);
		employee->addClient(client);
	}

	static void listAllClients(Employee* employee) {
		employee->listClient();
	}

	static void searchForClient(Employee* employee) {

		cout << "Enter id client: ";
		int id;
		cin >> id;
		

		if (employee->searchClient(id) == nullptr)
		{
			cout << "Client not Found.\n";
			return;
		}

		employee->searchClient(id)->displayInfo();
	}

	static void editClientInfo(Employee* employee) {

		string name, password;
		double balance;
		int id;

		system("cls");
		cout << "Enter id : ";
		cin >> id;
		cout << endl;

		system("cls");
		name = FillData::enterName();

		system("cls");
		password = FillData::enterPassword();

		system("cls");
		balance = FillData::enterBalance();


		employee->editClient(id, name, password, balance);
	}

	 static void updatePassword(Person* person)
	 {
		string password = FillData::enterPassword();
		person->setPassword(password);
	 }

	 static void continueProgram(Employee* employee)
	 {
		 system("pause");
		 system("cls");
		 employeeOptions(employee);
	 }

public:
	static Employee* login(int id, string password) {
		for (Employee::itEmployee = Employee::allEmployees.begin(); Employee::itEmployee != Employee::allEmployees.end(); Employee::itEmployee++)
		{
			if (id == Employee::itEmployee->getID() && password == Employee::itEmployee->getPassword())
			{
				return &(*Employee::itEmployee);
			}
		}

		return nullptr;
	}

	static bool employeeOptions(Employee* employee)
	{

		system("cls");
		printEmployeeMenu();
		short choice;
		cout << "Choose the option you want: ";
		cin >> choice;

		FileManager manager;
		system("cls");

		switch (choice)
		{
		case 1:
			employee->displayInfo(); 
			break;

		case 2:
			newClient(employee);
			manager.updateClient();
			break;

		case 3:
			searchForClient(employee);
			break;

		case 4:
			editClientInfo(employee);
			manager.updateClient();
			break;

		case 5:
			listAllClients(employee);
			break;

		case 6:
			updatePassword(employee); 
			manager.updateEmployee(); 
			break;

		case 7: 
			return false;
		
		default:
			cout << " The choice you chose wrong, choose from 1 to 7" << endl;
			return true;
		}

		cout << endl;
		continueProgram(employee);
		
	}

};


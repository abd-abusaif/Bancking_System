#pragma once
#include "Admin.h"
#include "FillData.h"
#include "FileManager.h"
#include "EmployeeManager.h"
class AdminManager {
private:

	static void printAdminMenu() {
		cout << "(1)View my information" << endl;
		cout << "(2)Add a new employee" << endl;
		cout << "(3)Search for a employee" << endl;
		cout << "(4)Edit employee information" << endl;
		cout << "(5)View all employees" << endl;
		cout << "(6)Add a new client" << endl;
		cout << "(7)Search for a client" << endl;
		cout << "(8)Edit client information" << endl;
		cout << "(9)View all clients" << endl;
		cout << "(10)Update password" << endl;
		cout << "(11)logout" << endl;
	}


	static void newEmployee(Admin* admin)
	{
		system("cls");
		string name = FillData::enterName();
		system("cls");
		string password = FillData::enterPassword();
		system("cls");
		double balance = FillData::enterBalance();

		Employee employee(name, password, balance);
		admin->addEmployee(employee);
	}

	static void searchForEmployee(Admin* admin)
	{
		system("cls");
		cout << "Enter id: ";
		int id;
		cin >> id;

		admin->searchEmployee(id)->displayInfo();
	}

	static void editEmployee(Admin* admin)
	{
		string name, password;
		double salary;
		int id;
		cout << "Enter id : ";
		cin >> id;
		system("cls");
		name = FillData::enterName();

		system("cls");
		password = FillData::enterPassword();

		system("cls");
		salary = FillData::enterSalary();

		admin->editEmployee(id, name, password, salary);
	}

	static void  listAllEmployees(Admin* admin) {

		system("cls");
		admin->listEmployee();
	}

	
	static void newClient(Admin* admin) {
		string name, password;
		double balance;

		system("cls");
		name = FillData::enterName();

		system("cls");
		password = FillData::enterPassword();

		system("cls");
		balance = FillData::enterBalance();

		Client client(name, password, balance);

		admin->addClient(client);
	}

	static void searchForClient(Admin* admin)
	{
		system("cls");

		int id;
		std::cout << "Enter ID: ";
		cin >> id;

		if (admin->searchClient(id) == nullptr)
		{
			cout << "Client not found.\n";
			return;
		}

		admin->searchClient(id)->displayInfo();
	}

	static void editClient(Admin* admin)
	{
		string name, password;
		double balance;
		int id;
		std::cout << "Enter ID : ";
		std::cin >> id;
		name = FillData::enterName();
		password = FillData::enterPassword();
		balance = FillData::enterBalance();

		admin->editClient(id, name, password, balance);
	}

	static void updatePassword(Admin* admin)
	{
		string password = FillData::enterPassword();
		admin->setPassword(password);
	}

	static void continueProgram(Admin* admin)
	{
		system("pause");
		system("cls");

		adminOptions(admin);
	}

public:
	static Admin* login(int id, string password) {
		for (Admin::itAdmin = Admin::allAdmins.begin(); Admin::itAdmin != Admin::allAdmins.end(); Admin::itAdmin++)
		{
			if (id == Admin::itAdmin->getID() && password == Admin::itAdmin->getPassword())
			{
				return &(*Admin::itAdmin);
			}
		}

		return nullptr;
	}
	static bool adminOptions(Admin* admin)
	{
		system("cls");
		printAdminMenu();

		short choice;
		cout << "Choose the option you want: ";
		cin >> choice;

		system("cls");

		FileManager manager;
		switch (choice)
		{
		case 1: admin->displayInfo(); break;
		case 2: newEmployee(admin); manager.updateEmployee(); break;
		case 3: searchForEmployee(admin); break;
		case 4: editEmployee(admin); manager.updateEmployee(); break;
		case 5: listAllEmployees(admin); break;
		case 6: newClient(admin); manager.updateClient(); break;
		case 7: searchForClient(admin); break;
		case 8: editClient(admin); manager.updateClient(); break;
		case 9: admin->listClient(); break;
		case 10: updatePassword(admin); manager.updateAdmin();  break;
		case 11: return false;
		default:
			cout << " The choice you chose wrong, choose from 1 to 11" << endl;

		}

		cout << endl;
		continueProgram(admin);
		return true;
		/*adminOptions(admin);*/
	}
};


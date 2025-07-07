#include "Screens.h"

void Screens::loginOptions() {

	cout << "Please select your account type to log in :" << endl;
	cout << "(1) Employee" << endl;
	cout << "(2) Client" << endl;
	cout << "(3) Admin" << endl;
	cout << "(4)logout" << endl << endl;
}


int Screens::loginAs()
{
	short choice;
	cout << "Choose the option you want: ";
	cin >> choice;

	return choice;
}

void Screens::invalid(int c)
{
	system("cls");

	cout << "The ID or password is incorrect\n";
	int id;
	string password;

	cout << "\nEnter ID: ";
	cin >> id;

	cout << "Enter password: ";
	cin >> password;

	if (c == 1)
	{
		while (EmployeeManager::login(id, password) == nullptr)
		{
			system("cls");
			cout << "The ID or password is incorrect\n";
			cout << "\nEnter ID: ";
			cin >> id;

			cout << "Enter password: ";
			cin >> password;
		}

		while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)) != false);
		logout();
	}
	else if (c == 2)
	{
		while (ClientManager::login(id, password) == nullptr)
		{
			system("cls");
			cout << "The ID or password is incorrect\n";
			cout << "\nEnter ID: ";
			cin >> id;

			cout << "Enter password: ";
			cin >> password;
		}

		while (ClientManager::clientOptions(ClientManager::login(id, password)) != false);
		logout();
	}
	else if (c == 3)
	{

		while (AdminManager::login(id, password) == nullptr)
		{
			system("cls");
			cout << "The ID or password is incorrect\n";
			cout << "\nEnter ID: ";
			cin >> id;

			cout << "Enter password: ";
			cin >> password;
		}

		while (AdminManager::adminOptions(AdminManager::login(id, password)) != false);
		logout();
	}

}

void Screens::logout() {
	loginOptions();
	loginScreen(loginAs());
}


void Screens::loginScreen(int c) {

	system("cls");
	int id;
	string password;

	switch (c)
	{
	case 1:
		cout << "Enter ID: ";
		cin >> id;

		cout << "Enter password: ";
		cin >> password;

		if (EmployeeManager::login(id, password) != nullptr) {
			while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)) != false);
			logout();
		}
		else
		{
			invalid(c);
		}
		break;

	case 2:
		cout << "Enter ID: ";
		cin >> id;

		cout << "Enter password: ";
		cin >> password;

		if (ClientManager::login(id, password) != nullptr) {
			while (ClientManager::clientOptions(ClientManager::login(id, password)) != false);
			logout();
		}
		else
		{
			invalid(c);
		}
		break;

	case 3:
		cout << "Enter ID: ";
		cin >> id;

		cout << "Enter password: ";
		cin >> password;

		if (AdminManager::login(id, password) != nullptr)
		{
			while (AdminManager::adminOptions(AdminManager::login(id, password)) != false);
			logout();
		}
		else
		{
			invalid(c);
		}
		break;
	}
}


void Screens::runApp() {

	FileManager manager;
	manager.getAllData();
	loginOptions();
	loginScreen(loginAs());
}

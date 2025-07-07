#pragma once
#include "FilesHelper.h"
#include "DataSourceInterface.h"

class FileManager : public DataSourceInterface
{
public:
	void addClient(Client& client)
	{

		FilesHelper::saveClient(client);
	}

	void addEmployee(Employee& employee)
	{

		FilesHelper::saveEmployee(EMPLOYEE_FILE, EMPLOYEE_LAST_ID, employee);
	}

	void addAdmin(Admin& admin)
	{

		FilesHelper::saveEmployee(ADMIN_FILE, ADMIN_LAST_ID, admin);
	}

	void getAllClients()
	{

		FilesHelper::getClients();
	}

	void getAllEmployees()
	{

		FilesHelper::getEmployees();
	}

	void getAllAdmins()
	{

		FilesHelper::getAdmins();
	}

	void getAllData() {

		getAllAdmins();
		getAllClients();
		getAllEmployees();
	}
	void removeAllClients()
	{

		FilesHelper::clearFile(CLIENT_FILE, CLIENT_LAST_ID);
	}

	void removeAllEmployees()
	{

		FilesHelper::clearFile(EMPLOYEE_FILE, EMPLOYEE_LAST_ID);
	}

	void removeAllAdmins()
	{

		FilesHelper::clearFile(ADMIN_FILE, ADMIN_LAST_ID);
	}

	void updateClient() {

		removeAllClients();

		for (Client::itClient = Client::allClients.begin(); Client::itClient != Client::allClients.end(); Client::itClient++) {
			addClient(*Client::itClient);
		}
	}

	void updateEmployee() {
		removeAllEmployees();

		for (Employee::itEmployee = Employee::allEmployees.begin(); Employee::itEmployee != Employee::allEmployees.end(); ++Employee::itEmployee)
		{
			addEmployee(*Employee::itEmployee);
		}
	}

	void updateAdmin()
	{
		removeAllAdmins();

		for (Admin::itAdmin = Admin::allAdmins.begin(); Admin::itAdmin != Admin::allAdmins.end(); ++Admin::itAdmin)
		{
			addAdmin(*Admin::itAdmin);
		}
	}
};

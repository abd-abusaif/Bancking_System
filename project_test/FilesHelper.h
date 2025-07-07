#pragma once
#include <fstream>
#include "DataFiles.h"
#include "Parser.h"

class FilesHelper
{
public:
	static void savelast(string fileName, int id)
	{

		ofstream fileOut(fileName, ios::out);

		if (!fileOut)
		{
			cout << "Erroe: Unable to open file " << fileName << "." << endl;
			return;
		}

		fileOut << id;

		fileOut.close();
	}

	static int getLast(string fileName)
	{

		ifstream fileIn(fileName, ios::in);

		if (!fileIn)
		{
			cout << "Erroe: Unable to open file " << fileName << "." << endl;
			return 1;
		}

		string id;
		fileIn >> id;

		fileIn.close();
		return stoi(id);
	}


	static void saveClient(Client c)
	{
		c.setID(getLast(CLIENT_LAST_ID) + 1);
		ofstream clientOut(CLIENT_FILE, ios::app);

		if (!clientOut)
		{
			cout << "Erroe: Unable to open file " << CLIENT_FILE << "." << endl;
			return;
		}

		clientOut << c.getID() << "-"
				  << c.getName() << "-"
				  << c.getPassword() << "-"
				  << c.getBalance() << endl;

		clientOut.close();

		savelast(CLIENT_LAST_ID, c.getID());
	}

	static void saveEmployee(string nameFile, string lastFile, Employee emp)
	{

		ofstream fileOut(nameFile, ios::app);
		if (!fileOut)
		{
			cout << "Erroe: Unable to open file " << nameFile << "." << endl;
			return;
		}

		emp.setID(getLast(lastFile) + 1);

		fileOut << emp.getID() << "-"
				<< emp.getName() << "-"
				<< emp.getPassword() << "-"
				<< emp.getSalary() << endl;

		fileOut.close();

		savelast(lastFile, emp.getID());
	}

	static void getClients()
	{

		ifstream clientIn(CLIENT_FILE, ios::in);

		if (!clientIn)
		{
			cout << "Erroe: Unable to open file " << CLIENT_FILE << "." << endl;
			return;
		}

		string line;
		while (getline(clientIn, line) && !clientIn.eof())
		{

			Client::allClients.push_back(Parser::parserToClient(line));
		}

		clientIn.close();
	}

	static void getEmployees()
	{

		ifstream employeeIn(EMPLOYEE_FILE, ios::in);

		if (!employeeIn)
		{
			cout << "Erroe: Unable to open file " << EMPLOYEE_FILE << "." << endl;
			return;
		}

		string line;

		while (getline(employeeIn, line))
		{
			Employee::allEmployees.push_back(Parser::parserToEmployee(line));
		}

		employeeIn.close();
	}

	static void getAdmins()
	{

		ifstream adminIn(ADMIN_FILE, ios::in);

		if (!adminIn)
		{
			cout << "Erroe: Unable to open file " << ADMIN_FILE << "." << endl;
			return;
		}

		string line;

		while (getline(adminIn, line))
		{
			Admin::allAdmins.push_back(Parser::parserToAdmin(line));
		}

		adminIn.close();
	}

	static void clearFile(string fileName, string lastIdFile)
	{

		ofstream clearFile(fileName, ios::out | ios::trunc);

		if (!clearFile)
		{
			cout << "Erroe: Unable to open file " << fileName << "." << endl;
			return;
		}

		clearFile.close();

		clearFile.open(lastIdFile, ios::out | ios::trunc);

		if (!clearFile)
		{
			cout << "Erroe: Unable to open file " << lastIdFile << "." << endl;
			return;
		}

		clearFile << 0;
		clearFile.close();

	}
};

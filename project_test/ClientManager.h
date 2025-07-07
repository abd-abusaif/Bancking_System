#pragma once
#include "Client.h"
#include "FillData.h"
#include "FileManager.h"
#include <stdlib.h>
class ClientManager
{
private: 
	static Client& searchClient(int id)	{


		for (Client::itClient = Client::allClients.begin(); Client::itClient != Client::allClients.end(); Client::itClient++)
		{

			if (id == Client::itClient->getID())
			{
				
				return *Client::itClient;
			}
		}
	}

	static void printClientMenu() {
		cout << "--------------------------------Menu----------------------------------" << endl;
		cout << "(1)View my information." << endl;
		cout << "(2)Deposit an amount" << endl;
		cout << "(3)Withdraw an amount" << endl;
		cout << "(4)Check the balance" << endl;
		cout << "(5)Transferring money to another account" << endl;
		cout << "(6)Update passworrd" << endl;
		cout << "(7)logout" << endl;
	}

	static void updatePassword(Person* person) {

		string password = FillData::enterPassword();
		person->setPassword(password);
	}

	static void continueProgram(Client* client)
	{
		system("pause");
		system("cls");
		clientOptions(client);
	}
public:

	static Client* login(int id, string password) {

		for (Client::itClient = Client::allClients.begin(); Client::itClient != Client::allClients.end(); Client::itClient++)
		{

			if (id == Client::itClient->getID() && password == Client::itClient->getPassword())
			{

				return &(*Client::itClient);
			}
		}

		return nullptr;
	}

	static bool clientOptions(Client* client)
	{
		system("cls");
		printClientMenu();

		short choice;
		cout << "Choose the option you want: " ;
		cin >> choice;

		double amount;
		FileManager manager;
		system("cls");
		switch (choice)
		{
		case 1:

			client->displayInfo();
			break;

		case 2:

			cout << "Enter the amount you want to deposit : ";
			cin >> amount;

			client->deposit(amount);
			manager.updateClient();

			break;

		case 3:
			cout << "Enter the amount you want to withdraw : ";
			cin >> amount;

			client->withdraw(amount);
			manager.updateClient();
			break;

		case 4:

			client->checkBalance();
			break;

		case 5:
			cout << "Enter the amount you want to transfer: ";
			cin >> amount;

			int numberAccount;
			cout << "Enter the account number you want to transfer to: ";
			cin >> numberAccount;

			client->transferTo(amount, searchClient(numberAccount));
			manager.updateClient();
			break;

		case 6:

			client->setPassword(FillData::enterPassword());
			manager.updateClient();
			break;

		case 7:
			return false;

		default:
			cout << " The choice you chose wrong, choose from 1 to 7" << endl;
			return true;
		}
		cout << endl;
		continueProgram(client);
	}
	
};


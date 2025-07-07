#pragma once
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "ClientManager.h"

class Screens
{
private:

	static void loginOptions() ;

	static int loginAs();

	static void invalid(int c);

	static void logout();

	static  void loginScreen(int c) ;

public:
	static void runApp();

};


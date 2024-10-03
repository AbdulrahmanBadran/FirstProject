#pragma once

#include <iostream>

#include "clsBamkUser.h"
#include "clsHeaderScreen.h"

using namespace std;

class clsAddNewUserScreen : protected clsHeaderScreen {

private:
	
	static void _printUserCard(clsBankUser user) {
		cout << "             user card               \n";
		cout << "------------------------------------------------------------\n";
		cout << "first name            :" << user.getFirstName() << endl;
		cout << "last name             :" << user.getLastName() << endl;
		cout << "full name             :" << user.fullName() << endl;
		cout << "email                 :" << user.getEmail() << endl;
		cout << "phone                 :" << user.getPhone() << endl;
		cout << "user Name             : " << user.getUserName() << endl;
		cout << "password              : " << user.getPassword() << endl;
		cout << "permissions           :" << to_string(user.getPermission()) << endl;
		cout << "------------------------------------------------------------\n";

	}

public:

	static void addNewUser()
	{
		clsHeaderScreen::printHeaderScreen("Add New User Screen");

		clsBankUser user = clsBankUser::addNewUser();
		
		
		_printUserCard(user);
	}



};

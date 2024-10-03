#pragma once

#include <iostream>

#include "clsHeaderScreen.h"
#include "clsBamkUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsHeaderScreen {

private:

	static void _printUserCard(clsBankUser user) {
		cout << "             user card               \n";
		cout << "-------------------------------\n";
		cout << "first name            :" << user.getFirstName() << endl;
		cout << "last name             :" << user.getLastName() << endl;
		cout << "full name             :" << user.fullName() << endl;
		cout << "email                 :" << user.getEmail() << endl;
		cout << "phone                 :" << user.getPhone() << endl;
		cout << "user Name             : " << user.getUserName() << endl;
		cout << "password              : " << user.getPassword() << endl;
		cout << "permissions           :" << to_string(user.getPermission()) << endl;
		cout << "-------------------------------\n";

	}

public:

	static void findUserScreen()
	{

		clsHeaderScreen::printHeaderScreen("Find Useer Screen");

		string userName;

		userName = clsInputValidate::readString("enter an user name to find:");

		while (!clsBankUser::isUserExist(userName)) {

			userName = clsInputValidate::readString("this user name is not exist,please enter a valid one:");
		}

		

		clsBankUser user = user.find(userName);
		
		if (user.isEmpty())
		{	
			cout << "\n\nuser not found.\n\n";
		}
		else
		{
			cout << "\n\nuser found.\n\n";
		}
		_printUserCard(user);



	}


	


};
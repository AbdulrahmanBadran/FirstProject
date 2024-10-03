#pragma once

#include <iostream>

#include "clsBamkUser.h"
#include "clsHeaderScreen.h"

using namespace std;

class clsDeleteUserScren :protected clsHeaderScreen{

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

	static void delteUserScreen() 
	{
		



		clsHeaderScreen::printHeaderScreen("Delete User Screen");

		string userName;

		userName = clsInputValidate::readString("enter an user name to delete:");

		while (!clsBankUser::isUserExist(userName)) {

			userName = clsInputValidate::readString("this user name is not exist,please enter a valid one:");
		}

		clsBankUser user = user.find(userName);

		_printUserCard(user);

		
		char insurance;
		insurance =clsInputValidate::readChar("\nare you sure you want to delete this user (y/n):");

		if (insurance == 'y' || insurance == 'Y') {

			user.Delete();
			cout << endl << endl;

			cout << "user deleted succefully";

			cout << endl << endl;
			_printUserCard(user);
		}
		else
		{
			cout << "user has not deleted";
		}
		

	}




};

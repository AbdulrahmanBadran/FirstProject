#pragma once

#include <iostream>

#include "clsBamkUser.h"
#include "clsHeaderScreen.h"

using namespace std;


class clsUpdateUserScreen : protected clsHeaderScreen{

private:

	static int _readPermission()
	{
		return clsBankUser::readPermission();
	}

	static clsBankUser _readUser(clsBankUser& user) {

		string str;

		cout << "enter your first name:";

		cin >> str;

		user.setFirstName(str);

		cout << "enter your last name:";

		cin >> str;

		user.setLastName(str);

		cout << "enter your email:";

		cin >> str;

		user.setEmail(str);


		cout << "enter your phone:";

		cin >> str;

		user.setPhone(str);

		cout << "enter your password:";

		cin >> str;

		user.setPassword(str);

		user.setPermission(_readPermission());

		return user;

	}

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

	static void UpdateUserScreen()
	{

		clsHeaderScreen::printHeaderScreen("Update User Screen");

		string userName;

		userName = clsInputValidate::readString("enter an user name to update:");

		while (!clsBankUser::isUserExist(userName)) {

			userName = clsInputValidate::readString("this user name is not exist,please enter a valid one:");
		}

		clsBankUser user = user.find(userName);

		_printUserCard(user);

		char insurance;
		insurance = clsInputValidate::readChar("\nare you sure you want to Update this user (y/n):");

		if (insurance == 'y' || insurance == 'Y') {

			_readUser(user);
			user.save();
			cout << endl << endl;

			cout << "user updated succefully";

			cout << endl << endl;
			_printUserCard(user);
		}

		else
		{
			cout << "user has not updated";
		}



	}



};
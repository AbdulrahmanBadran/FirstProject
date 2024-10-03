#pragma once

#include <iostream>
#include <vector>
#include "clsBamkUser.h"
#include "clsHeaderScreen.h"


using namespace std;

class clsUsersList : protected clsHeaderScreen {

private:

	static void _printUsersList(clsBankUser User)
	{
		cout << "| " << setw(15) << left << User.getUserName();
		cout << "| " << setw(20) << left << User.fullName();
		cout << "| " << setw(12) << left << User.getPhone();
		cout << "| " << setw(20) << left << User.getEmail();
		cout << "| " << setw(10) << left << User.getPassword();
		cout << "| " << setw(12) << left << User.getPermission();
		cout << endl;


	}




public:

	static void showUsersList()
	{
		vector<clsBankUser> vUsers = clsBankUser::getUserList();

		clsHeaderScreen::printHeaderScreen("Users List Screen","( "+to_string( vUsers.size())+" ) Users");


		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		for (clsBankUser user : vUsers)
		{
			_printUsersList(user);
		}



	}






};

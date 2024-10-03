#pragma once

#include<iostream>
#include "clsHeaderScreen.h"
#include "clsBankClient.h"
#include "clsBamkUser.h"


using namespace std;

class clsFindClientScreen :protected clsHeaderScreen {

private:

	static void _printClientCard(clsBankClient client) {
		cout << "             client card               \n";
		cout << "------------------------------------------------------------\n";
		cout << "first name            :" << client.getFirstName() << endl;
		cout << "last name             :" << client.getLastName() << endl;
		cout << "full name             :" << client.fullName() << endl;
		cout << "email                 :" << client.getEmail() << endl;
		cout << "phone                 :" << client.getPhone() << endl;
		cout << "account number        : " << client.getAccountNumber() << endl;
		cout << "pin code              : " << client.getPinCode() << endl;
		cout << "account balance       :" << to_string(client.getAccountBalance()) << endl;
		cout << "------------------------------------------------------------\n";

	}



public:

	static void findClientScreen()
	{

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enFindClient))
		{
			return;

		}

		clsHeaderScreen::printHeaderScreen("Update Client Screen");

		string accountNumber = clsInputValidate::readString("enter an account number to find:");

		while (!clsBankClient::isClientExist(accountNumber))
		{
			accountNumber = clsInputValidate::readString("client does not exist,please enter a valid client account number:");

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		if (client.isClientExist()) {

			cout << "\nclient found.\n";

		}
		else
		{
			cout << "\n didn't find the client.\n";


		}


		_printClientCard(client);

	}




};

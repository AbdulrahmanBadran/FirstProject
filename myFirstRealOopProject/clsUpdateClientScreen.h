#pragma once

#include <iostream>
#include "clsHeaderScreen.h"
#include "clsBankClient.h"
#include "clsBamkUser.h"
#include "clsInputValidate.h"

using namespace std;


class clsUpdateClientScreen : protected clsHeaderScreen  {

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


	static void updateClient()
	{

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enUpdateClient))
		{
			return;

		}

		clsHeaderScreen::printHeaderScreen("Update Client Screen");

		string accountNumber = clsInputValidate::readString("enter an account number to update:");

		while (!clsBankClient::isClientExist(accountNumber))
		{
			accountNumber = clsInputValidate::readString("client does not exist,please enter a valid client account number:");

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClientCard(client);


		cout << "\nare you sure you want to update this client (y/n):";
		char insurance;
		cin >> insurance;

		if (insurance == 'y' || insurance == 'Y') {

			system("cls");

			client.update();

			_printClientCard(client);

			cout << "\nclient updated successfully -)\n";
		}
		else
			cout << "client was not updated.\n";

	}

	



};

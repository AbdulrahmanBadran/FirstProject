#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsBamkUser.h"
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"

using namespace std;


class clsDeleteClientScreen:protected clsHeaderScreen , protected clsBankClient{

private:
	
	static void _printClientCard(clsBankClient client) {
		cout << "\n             client card               \n";
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
	
	static void deleteClientScreen()
	{

	
		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enDeleteClient)) {

			return;

		}


		clsHeaderScreen::printHeaderScreen("Delete Client Screen");

		string accountNumber = clsInputValidate::readString("enter an account number to delete:");

		while (!isClientExist(accountNumber))
		{
			accountNumber = clsInputValidate::readString("there is np account with this number,please enter a valid one");

		}

		clsBankClient client = find(accountNumber);

		_printClientCard(client);


		cout << "\nare you sure you want to delete this client (y/n):";
		char insurance;
		cin >> insurance;

		if (insurance == 'y' || insurance == 'Y') {

			client.Delete();

			cout << "client deleted successfully.\n";

			_printClientCard(client);
		}
		else
			cout << "client was not deleted.\n";


	}

	

};

#pragma once

#include <iostream>
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsScreens.h"
#include "clsBankClient.h"


using namespace std;


class clsWithdrawScreen : protected clsHeaderScreen {

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

	static void _withdrawOperation(clsBankClient& client)
	{
		double amount;

		amount = clsInputValidate::readDoubleNumber("please enter withdraw amount:");


		cout << "\nare you sure you want to perform this transaction (y/n):";
		char insurance;
		cin >> insurance;

		if (insurance == 'y' || insurance == 'Y')
        	if(client.Withdraw(amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nnew balance is " << client.getAccountBalance() << endl;
			}

		else
			cout << "\nthe transaction failed.\n";
	}


public:

	static void withdrawScreen() {

		clsHeaderScreen::printHeaderScreen("Withdraw Screen");

		string accountNumber;

		accountNumber = clsInputValidate::readString("please enter account number:");

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "Client with [" << accountNumber << "] does not exist.\n";

			accountNumber = clsInputValidate::readString("please enter account number:");

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClientCard(client);

		_withdrawOperation(client);


		

	}



};

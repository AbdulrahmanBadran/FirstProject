#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsBamkUser.h"
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"



using namespace std;


class clsAddNewClientScreen : protected clsHeaderScreen {

private:

	static clsBankClient _readClient(clsBankClient& client) {

		string str;

		cout << "enter your first name:";

		cin >> str;

		client.setFirstName(str);

		cout << "enter your last name:";

		cin >> str;

		client.setLastName(str);

		cout << "enter your email:";

		cin >> str;

		client.setEmail(str);


		cout << "enter your phone:";

		cin >> str;

		client.setPhone(str);

		cout << "enter your pin code:";

		cin >> str;

		client.setPinCode(str);

		cout << "enter your balance:";

		cin >> str;

		client.setAccountBalance(stof(str));

		return client;

	}

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

	

	static void addNewClientScreen(){

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enAddNewClient))
		{
			return;

		}

		clsHeaderScreen::printHeaderScreen("Add New Client Screen");

		string accountNumber;

		accountNumber = clsInputValidate::readString("enter new account number to add:");


		while (clsBankClient::isClientExist(accountNumber)) {

			accountNumber = clsInputValidate::readString("this account number is already exist,please enter another account number:");
		}

		clsBankClient newClient = clsBankClient::getNewClient(accountNumber);

		_readClient(newClient);

		newClient.save();
	
		_printClientCard(newClient);
	
	
	}





};
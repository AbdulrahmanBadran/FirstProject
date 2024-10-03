#pragma once

#include<iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsHeaderScreen.h"


using namespace std;

class clsShowClientListScreen : protected clsHeaderScreen  {

	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(20) << left << Client.fullName();
		cout << "| " << setw(12) << left << Client.getPhone();
		cout << "| " << setw(20) << left << Client.getEmail();
		cout << "| " << setw(10) << left << Client.getPinCode();
		cout << "| " << setw(12) << left << Client.getAccountBalance();

	}

public:

	static void ShowClientsList()
	{
		
		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enShowClientList))
		{
			return;

		}

		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		clsHeaderScreen::printHeaderScreen("Clients List Screen","  (" + to_string(vClients.size()) + ") clients");

	
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}




};

#pragma once
#include <iostream>
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsScreens.h"
#include "clsBankClient.h"

using namespace std;

class clsTotalBalancesScreen:protected clsHeaderScreen {

private:

	static void _printClientBalance(clsBankClient Client) {

		cout << "| " << setw(30) << left << Client.getAccountNumber();
		cout << "| " << setw(40) << left << Client.fullName();
		cout << "| " << setw(20) << left << Client.getAccountBalance();
	}

    static void _showClientsBalances() {
	
		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(20) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_printClientBalance(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		double totalBalances = clsBankClient::getTotalClientsBalances();
		clsUtil::tab(9);
		cout <<left << totalBalances << endl;
		clsUtil::tab(5);

		cout << "( " << clsUtil::NumberToText(totalBalances) << ")" << endl;

	}


public:

	static void TotalBalancesScreen() {

		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		clsHeaderScreen::printHeaderScreen("Total Balances Screen", "\n\t\t\t\t\tClient Balances List (" + to_string(vClients.size()) + ") Client(s).");


		_showClientsBalances();

	}

	



};

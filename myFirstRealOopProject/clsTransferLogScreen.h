#pragma once

#include <iostream>
#include <fstream>

#include "clsBamkUser.h"
#include "clsBankClient.h"
#include "clsHeaderScreen.h"
#include "myStringLib.h"

using namespace std;

class clsTransferLogScreen : protected clsHeaderScreen {

private:

	static void _PrintTransferLogScreen()
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		_getTheTransferInfo();

		cout << "________________________________________________________________________________________________________\n\n";



	}

	static void _printTheTransferInfo(vector<string> VtransferLog)
	{
	

		cout << setw(8) << left << "" << "| " << setw(23) << left << VtransferLog[0];
		cout << "| " << setw(8) << left << VtransferLog[1];
		cout << "| " << setw(8) << left << VtransferLog[2];
		cout << "| " << setw(8) << left << stof(VtransferLog[3]);
		cout << "| " << setw(10) << left << stof(VtransferLog[4]);
		cout << "| " << setw(10) << left << stof(VtransferLog[5]);
		cout << "| " << setw(8) << left << VtransferLog[6]<<endl;

	}

	static void _getTheTransferInfo()
	{

		vector<string> VtransferLog;

		fstream myFile;

		myFile.open("transferLog.txt", ios::in);

		if (myFile.is_open()) {

			string line;

			while (getline(myFile, line)) {

				VtransferLog = myStringLib::splitString(line);

				_printTheTransferInfo(VtransferLog);

			}

			myFile.close();
		}






	}


public:

	static void TransferLogScreen()
	{
		clsHeaderScreen::printHeaderScreen("Transfer Log Screen");

		_PrintTransferLogScreen();

	}




};

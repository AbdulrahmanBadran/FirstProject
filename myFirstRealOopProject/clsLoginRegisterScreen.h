#pragma once

#include <iostream>

#include "clsHeaderScreen.h"


using namespace std;

class clsLoginRegisterScreen : protected clsHeaderScreen {

private:

	static void printLoginRegisterRecordsHeader()
	{
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Date And Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(12) << "password";
		cout << "| " << left << setw(20) << "permissions";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}

	static void printLoginRegisterRecords(vector <string> VloginRegisterList)
	{

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enShowLoginRegisterScreen)) {

			return;

		}


		printLoginRegisterRecordsHeader();

		vector <string>line;

		if (VloginRegisterList.size() == 0) {

			cout << "\t\t\t\tNo Registers In the System Yet!";

		}

		for(string& record : VloginRegisterList)
		{
			line = myStringLib::splitString(record);

			cout << "| " << left << setw(30) << line[0];
			cout << "| " << left << setw(20) << line[1];
			cout << "| " << left << setw(12) << line[2];
			cout << "| " << left << setw(20) << line[3]<<endl;


		}

		cout << "_________________________________________";
		cout << "_______________________________________________________\n";
	}


public:

	static void loginRegisterScreen()
	{

		vector<string>VloginRegisterList =currentUser.getLogInRegisterList();


		clsHeaderScreen::printHeaderScreen("Login Register Screen","()"+to_string(VloginRegisterList.size())+") records");

		
		printLoginRegisterRecords(VloginRegisterList);


	}





};
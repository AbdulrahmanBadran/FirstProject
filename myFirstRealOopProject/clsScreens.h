#pragma once

#include <iostream>
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsShowClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsMainTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsBamkUser.h"
#include "clsLoginRegisterScreen.h"
#include "clsMainCurrencyExchangeScreen.h"


using namespace std;


class clsScreens:protected clsHeaderScreen {

	enum enScreens{enShowAllClientScreen=1,enAddNewClientScreen =2,
		           enDeleteClientScreen =3,enUpdateClientScreen =4,
	               enFindClientScreen=5,enTransactionsScreen=6,
	                 enManageUsersScreen=7,enLogInRegisterScreen=8,enCurrencyExchangeScreen=9,enLogoutScreen=10};


	static void printMainScreen()
	{

		clsHeaderScreen::printHeaderScreen("Main Screen");

		clsUtil::tab(4);
		cout << "=============================================\n";
		clsUtil::tab(6);
		cout << "  Main Menu\n";
		clsUtil::tab(4);
		cout << "=============================================\n";
		clsUtil::tab(4);
		cout << "[1] Show Client List\n";
		clsUtil::tab(4);
		cout << "[2] Add New Client\n";
		clsUtil::tab(4);
		cout << "[3] Delete Client\n";
		clsUtil::tab(4);
		cout << "[4] Update Client Info\n";
		clsUtil::tab(4);
		cout << "[5] Find Client\n";
		clsUtil::tab(4);
		cout << "[6] Transactions\n";
		clsUtil::tab(4);
		cout << "[7] Manage Users\n";
		clsUtil::tab(4);
		cout << "[8] Login Register\n";
		clsUtil::tab(4);
		cout << "[9] Currency Exchange\n";
		clsUtil::tab(4);
		cout << "[10] Logout\n";
		clsUtil::tab(4);
		cout << "=============================================\n";
		clsUtil::tab(4);
		cout << "choose what do you want to do? [1-10]:";
	}

	static void ShowAllClientScreen() {
		system("cls");

		clsShowClientListScreen::ShowClientsList();

		cout << "      enter any key to exit...";
		system("pause>0");
	}

	static void AddNewClientScreen() {
		system("cls");

		clsAddNewClientScreen::addNewClientScreen();

		cout << "      enter any key to exit...";
		system("pause>0");
	}

	static void DeleteClientScreen()
	{
		system("cls");

		clsDeleteClientScreen::deleteClientScreen();

		cout << "      enter any key to exit...";
		system("pause>0");
    }

	static void UpdateClientScreen()
	{

		system("cls");

		clsUpdateClientScreen::updateClient();

		cout << "      enter any key to exit...";
		system("pause>0");
	}

	static void FindClientScreen()
	{

		system("cls");

		clsFindClientScreen::findClientScreen();

		cout << "      enter any key to exit...";
		system("pause>0");
	}

	static void TransactionsScreen()
	{
		clsMainTransactionsScreen::MainTransactionsScreen();
		system("cls");
		cout << "      enter any key to exit...";
		system("pause>0");
	
	}

	static void ManageUsersScreen()
	{
		system("cls");
		clsManageUsersScreen::ManageUsersScreen();

		cout << "      enter any key to exit...";
		system("pause>0");

	}

	static void ShowLoginRegisterScreen() {
		system("cls");

		clsLoginRegisterScreen::loginRegisterScreen();


		cout << "      enter any key to exit...";
		system("pause>0");
	}

	static void showcurrencyExchangeScreen()
	{
		
		clsMainCurrencyExchangeMenu::MainCurrencyExchangeMenu();

	}

	static void LogoutScreen()
	{

		currentUser = clsBankUser::find("", "");


	}





public:

	static void MainMenu() {
		system("cls");
		printMainScreen();

		enScreens choice;

		choice=(enScreens) clsInputValidate::readIntNumberBetween(1, 10,"", "valid choice, please enter a valid one : ");

		switch (choice)
		{
		case clsScreens::enShowAllClientScreen:
				ShowAllClientScreen();
			MainMenu();
			break;
		case clsScreens::enAddNewClientScreen:
			AddNewClientScreen();
			MainMenu();
			break;
		case clsScreens::enDeleteClientScreen:
			DeleteClientScreen();
			MainMenu();
			break;
		case clsScreens::enUpdateClientScreen:
			UpdateClientScreen();
			MainMenu();
			break;
		case clsScreens::enFindClientScreen:
			FindClientScreen();
			MainMenu();
			break;
		case clsScreens::enTransactionsScreen:
			TransactionsScreen();
			MainMenu();
			break;
		case clsScreens::enLogInRegisterScreen:
			ShowLoginRegisterScreen();
			MainMenu();
			break;
		case clsScreens::enManageUsersScreen:
			ManageUsersScreen();
			MainMenu();
			break;
		case clsScreens::enCurrencyExchangeScreen:
			showcurrencyExchangeScreen();
			MainMenu();
			break;
		case clsScreens::enLogoutScreen:
			LogoutScreen();
			return;
		}


	}







};

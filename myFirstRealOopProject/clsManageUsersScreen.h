#pragma once

#include <iostream>
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsScreens.h"
#include "clsBamkUser.h"
#include "clsShowUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;


class clsManageUsersScreen :protected clsHeaderScreen {

private:

	enum enTransactionsOption { enListUsers = 1, enAddNewUser = 2,
		               enDeleteUser = 3  ,enUpdateUser=4   ,enFindUser=5};




	static void _printManageUsersScreen()
	{
		system("cls");

		clsHeaderScreen::printHeaderScreen("Manage Users Menu");

		cout << endl;
		clsUtil::tab(4);
		cout << "===============================================\n";
		clsUtil::tab(4);
		cout << "press [1] List Users\n";
		clsUtil::tab(4);
		cout << "press [2] Add New User\n";
		clsUtil::tab(4);
		cout << "press [3] Delete User\n";
		clsUtil::tab(4);
		cout << "press [4] Update User\n";
		clsUtil::tab(4);
		cout << "press [5] Find User\n";
		clsUtil::tab(4);
		cout << "press [6] Main Menu\n";
		clsUtil::tab(4);
		cout << "===============================================\n";
		clsUtil::tab(4);

	}

	static void ListUsersScreen()
	{
		clsUsersList::showUsersList();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void AddNewUserScreen()
	{
		clsAddNewUserScreen::addNewUser();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void DeleteUserScreen()
	{
		clsDeleteUserScren::delteUserScreen();
		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void  UpdateUserScreen()
	{

		clsUpdateUserScreen::UpdateUserScreen();


		cout << "      enter any key to exit...\n";
		system("pause>0");

	}

	static void  FindUserScreen()
	{

		clsFindUserScreen::findUserScreen();


		cout << "      enter any key to exit...\n";
		system("pause>0");

	}

	static void  MainMenuScreen()
	{

		cout << "Main Menu Screen is not here yet...\n";


		cout << "      enter any key to exit...\n";
		system("pause>0");

	}


public:

	static void ManageUsersScreen() {

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enManageUsers))
		{
			return;

		}


		_printManageUsersScreen();

		enTransactionsOption option;

		option = (enTransactionsOption)clsInputValidate::readIntNumberBetween(1, 6, "enter what do you want to do [1 to 6]:");


		switch (option)
		{
		case enTransactionsOption::enListUsers:
			system("cls");
			ListUsersScreen();
			ManageUsersScreen();
			break;
		case enTransactionsOption::enAddNewUser:
			system("cls");
			AddNewUserScreen();
			ManageUsersScreen();
			break;
		case enTransactionsOption::enDeleteUser:
			system("cls");
			DeleteUserScreen();
			ManageUsersScreen();
			break;

		case enTransactionsOption::enUpdateUser:
			system("cls");
			UpdateUserScreen();
			ManageUsersScreen();
			break;

		case enTransactionsOption::enFindUser:
			system("cls");
			FindUserScreen();
			ManageUsersScreen();
			break;

		default:
			//clsScreens::MainMenu();
			system("cls");
			return;
		}



	}






};





#pragma once

#include <iostream>
#include "clsHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsScreens.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsBamkUser.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;


class clsMainTransactionsScreen :protected clsHeaderScreen {

private:

	enum enTransactionsOption { enDeposit=1,enWithdraw=2,enTotalBalances=3,enTransferScreen=4,enTransferLogScreen=5};

	
	static void _printMainTransactionsScreen()
	{
		system("cls");

		clsHeaderScreen::printHeaderScreen("Transactions Screen");

		cout << endl;
		clsUtil::tab(4);
		cout << "===============================================\n";
		clsUtil::tab(4);
		cout << "press [1] Deposit\n";
		clsUtil::tab(4);
		cout << "press [2] Withdraw\n";
		clsUtil::tab(4);
		cout << "press [3] Total Balances\n";
		clsUtil::tab(4);
		cout << "press [4] Transfer \n";
		clsUtil::tab(4);
		cout << "press [5] Transfer Log \n";
		clsUtil::tab(4);
		cout << "press [6] Main Menu\n";
		clsUtil::tab(4);
		cout << "===============================================\n";
		clsUtil::tab(4);

	}

	static void DepositScreen()
	{
		clsDepositScreen::depositScreen();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void WithdrawScreen()
	{
		clsWithdrawScreen::withdrawScreen();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void TotalBalancesScreen()
	{
		clsTotalBalancesScreen::TotalBalancesScreen();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void TransferOperationScreen()
	{

		clsTransferScreen::transferScreen();

		cout << "      enter any key to exit...\n";
		system("pause>0");

	}

	static void TransferLogScreen()
	{

		clsTransferLogScreen::TransferLogScreen();

		cout << "      enter any key to exit...\n";
		system("pause>0");


	}

	static void MainMenu()
	{

		cout << "there is nothing here yet.\n";

		cout << "      enter any key to exit...\n";
		system("pause>0");

	}



public:

	static void MainTransactionsScreen() {

		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enTransactions))
		{
			return;

		}


		_printMainTransactionsScreen();

		enTransactionsOption option;

		option = (enTransactionsOption)clsInputValidate::readIntNumberBetween(1, 6, "enter what do you want to do [1 to 6]:");
		

		switch (option)
		{
		case clsMainTransactionsScreen::enDeposit:
			system("cls");
			DepositScreen();
			MainTransactionsScreen();
			break;
		case clsMainTransactionsScreen::enWithdraw:
			system("cls");
			WithdrawScreen();
			MainTransactionsScreen();
			break;
		case clsMainTransactionsScreen::enTotalBalances:
			system("cls");
			TotalBalancesScreen();
			MainTransactionsScreen();
			break;
		case clsMainTransactionsScreen::enTransferScreen:
			system("cls");
			TransferOperationScreen();
			MainTransactionsScreen();
			break;
		case clsMainTransactionsScreen::enTransferLogScreen:
			system("cls");
			TransferLogScreen();
			MainTransactionsScreen();
			break;
		default:
			system("cls");
			return;
		}



	}

	




};





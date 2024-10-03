#pragma once

#include <iostream>


#include "clsHeaderScreen.h"
#include "clsBankCurrency.h"
#include "clsScreens.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"


using namespace std;


class clsMainCurrencyExchangeMenu:protected clsHeaderScreen {

private:

	enum enCurrencyMenu{enListCurrencies=1,enFindCurrency=2,enUpdateRate=3,
		enCurrencyCalculator=4,enMainMenu=5
	};

	static void _printMainCurrencyExchangeMenu()
	{
		system("cls");

		clsHeaderScreen::printHeaderScreen("Currency Exchange Main Screen");

		clsUtil::tab(4);
		cout << "=============================================\n";
		clsUtil::tab(6);
		cout << "  Currency Exchange Menu\n";
		clsUtil::tab(4);
		cout << "=============================================\n";
		clsUtil::tab(4);
		cout << "[1] List Currencies\n";
		clsUtil::tab(4);
		cout << "[2] Find Currency\n";
		clsUtil::tab(4);
		cout << "[3] Update Rate\n";
		clsUtil::tab(4);
		cout << "[4] Currency Calculator\n";
		clsUtil::tab(4);
		cout << "[5] Main Menu\n";
		clsUtil::tab(4);
		cout << "=============================================\n";



	}

	static void _ListCurrency()
	{

		clsCurrenciesListScreen::currenciesListScreen();


		cout << "      enter any key to exit...";
		system("pause>0");

	}

	static void _FindCurrency()
	{

		clsFindCurrencyScreen::findCurrencyScreen();


		cout << "      enter any key to exit...";
		system("pause>0");


	}

	static void _UpdateRate()
	{

		clsUpdateRateScreen::UpdateRate();


		cout << "      enter any key to exit...";
		system("pause>0");


	}

	static void _CurrencyCalculator()
	{

		clsCurrencyCalculator::currencyCalculator();


		cout << "      enter any key to exit...";
		system("pause>0");


	}


public:


	static void MainCurrencyExchangeMenu()
	{
		if (!clsHeaderScreen::CheckAccessPermission(clsBankUser::enPermissions::enCurrencyExchangeScreen))
		{
			return;

		}

		_printMainCurrencyExchangeMenu();

		enCurrencyMenu choice;

		choice=(enCurrencyMenu)clsInputValidate::readIntNumberBetween(1, 5, "enetr what you want to do [1-5]");

		switch (choice)
		{
		case clsMainCurrencyExchangeMenu::enListCurrencies:
			system("cls");
			_ListCurrency();
			MainCurrencyExchangeMenu();
			break;
		case clsMainCurrencyExchangeMenu::enFindCurrency:
			system("cls");
			_FindCurrency();
			MainCurrencyExchangeMenu();
			break;
		case clsMainCurrencyExchangeMenu::enUpdateRate:
			system("cls");
			_UpdateRate();
			MainCurrencyExchangeMenu();
			break;
		case clsMainCurrencyExchangeMenu::enCurrencyCalculator:
			system("cls");
			_CurrencyCalculator();
			MainCurrencyExchangeMenu();
			break;
		default:
			return;
			break;
		}




	}



};


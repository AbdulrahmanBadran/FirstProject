#pragma once

#include <iostream>

#include "clsBankCurrency.h"
#include "clsHeaderScreen.h"


using namespace std;


class clsFindCurrencyScreen:protected clsHeaderScreen {

private:
	enum enChoice{enCode=1,enCountry=2};

	static void _printCurrencyInfo(clsCurrencies currency)
	{
		cout << "__________________________\n\n";
		cout << "Countrty   :" << currency.getCountry()<<endl;
		cout << "Code       :" << currency.getCurrencyCode() << endl;
		cout << "Name       :" << currency.getCurrencyName() << endl;
		cout << "Rate(1$)   :" << currency.getCurrencyRate() << endl;
		cout << "__________________________\n\n";



	}

	static void _showResult(clsCurrencies currency)
	{

		if (!currency.isEmpty())
		{

			cout << "Currency Found :-)\n";

			_printCurrencyInfo(currency);
		}
		else
			cout << "Currency Not Found\n";

	}

public:

	static void findCurrencyScreen()
	{

		clsHeaderScreen::printHeaderScreen("Find Currency Screen");


		short choice;

		choice = clsInputValidate::readIntNumberBetween(1, 2, "\nFind by: [1] Code or [2] Country ?");

		clsCurrencies currency = currency.findByCode("");

		if (choice == (enChoice)enChoice::enCode)
		{
			string currencyCode;

			currencyCode = myStringLib::to_upper(clsInputValidate::readString("\n Please Enter Currency Code :"));

			 currency = clsCurrencies::findByCode(currencyCode);

			
		}
		else
		{

			string countryName;

			countryName = myStringLib::to_upper(clsInputValidate::readString("\n Please Enter Country Name :"));

			currency = clsCurrencies::findByCountry(countryName);

			

		}

		_showResult(currency);


	}





};







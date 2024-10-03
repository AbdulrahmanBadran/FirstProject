#pragma once

#include <iostream>

#include "clsBankCurrency.h"
#include "clsHeaderScreen.h"


using namespace std;

class clsUpdateRateScreen : protected clsHeaderScreen{

private:

	static void _printCurrencyInfo(clsCurrencies currency)
	{
		cout << "__________________________\n\n";
		cout << "Countrty   :" << currency.getCountry() << endl;
		cout << "Code       :" << currency.getCurrencyCode() << endl;
		cout << "Name       :" << currency.getCurrencyName() << endl;
		cout << "Rate(1$)   :" << currency.getCurrencyRate() << endl;
		cout << "__________________________\n\n";



	}

	static void _showResult(clsCurrencies currency)
	{

		if (!currency.isEmpty())
		{

			

			_printCurrencyInfo(currency);
			

		}
		else
		{
			cout << "Currency Not Found\n";

			
		}




	}

	static void _updateRate(clsCurrencies currency)
	{
		float newRate;

		cout << "\n\nUpdate Currency Rate:\n";
		cout << "_______________________________\n\n";
     
		newRate = clsInputValidate::readFloatNumber("Enter New Rate:");

		currency.setCurrencyRate(newRate);

		cout << "currency Rate Updated Successfully\n";

		_printCurrencyInfo(currency);

	}


public:


	static void UpdateRate()
	{

		clsHeaderScreen::printHeaderScreen("Update Rate Screen");

		string currencyCode;

		currencyCode = clsInputValidate::readString("please enter Currency Code:");

		clsCurrencies currency = currency.findByCode(currencyCode);

		while (!clsCurrencies::isCurrencyExist(currencyCode))
		{
			currencyCode = clsInputValidate::readString("\nCurrency is not found, choose another one: ");

		}

		_showResult(currency);
		
			char insurrance;

			insurrance = clsInputValidate::readChar("are you sure you want to update this currency (y/n)?");

			if (insurrance == 'y' || insurrance == 'Y')
			{

				_updateRate(currency);

				cout << endl;

				
			}



		




	}




};


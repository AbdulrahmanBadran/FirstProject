#pragma once

#include <iostream>

#include "clsBankCurrency.h"
#include "clsHeaderScreen.h"


using namespace std;


class clsCurrenciesListScreen:protected clsHeaderScreen {

private:

	static void _printCurrencyDataLine(clsCurrencies currency)
	{

		cout << setw(8) << left << "" << "| " << left << setw(30) << currency.getCountry();
		cout << "| " << left << setw(8) << currency.getCurrencyCode();
		cout << "| " << left << setw(45) << currency.getCurrencyName();
		cout << "| " << left << setw(10) << currency.getCurrencyRate();



	}

	static void _printCurrenciesListScreen()
	{

		vector<clsCurrencies>vCurrencies = clsCurrencies::GetAllUSDRates();

		clsHeaderScreen::printHeaderScreen("Currencies List Screen", "(" + to_string(vCurrencies.size()) + ") currency.");



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

		if(vCurrencies.size()==0)
		cout << "\t\t\t\tNo Currencies Available In the System!";

		else
		{

			for (clsCurrencies currency : vCurrencies)
			{

				_printCurrencyDataLine(currency);
				cout << endl;

			}



		}

	}

public:

	static void currenciesListScreen()
	{

		_printCurrenciesListScreen();




    }






};




#pragma once

#include <iostream>

#include "clsHeaderScreen.h"
#include "clsBankCurrency.h"

using namespace std;

class clsCurrencyCalculator : protected clsHeaderScreen {

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

	static float _calculateToUsd(clsCurrencies currency,float amount)
	{

		return (amount / currency.getCurrencyRate());

	}

	static float _claculateToOtherCurrencies(clsCurrencies currency, float amount)
	{

		return (amount * currency.getCurrencyRate());


	}

	static clsCurrencies _readCurrency(string messege)
	{

		string currencyCode;

		currencyCode = clsInputValidate::readString(messege);

		while (!clsCurrencies::isCurrencyExist(currencyCode))
		{
			currencyCode = clsInputValidate::readString("\nCurrency is not found, choose another one: ");

		}

		clsCurrencies currency = currency.findByCode(currencyCode);


		return currency;

	}

	static void _currencyCalculator()
	{


		clsCurrencies currency1 = _readCurrency("\nplease enter the currency you want to convert from:\n");


		clsCurrencies currency2 = _readCurrency("\nplease enter the currency you want to convert to:\n");

		float amount;
		amount=clsInputValidate::readFloatNumber("\nEnter Amount To Exchange:\n");

		float toUsd = currency1.calculateToUsd(amount);

		if (currency1.getCurrencyCode() != "USD") {

			cout << "\nConvert  From:\n\n";

			_printCurrencyInfo(currency1);
		
			cout << amount << " " << currency1.getCurrencyCode() << " = " << toUsd <<" USD" << endl;


		}

		if (currency2.getCurrencyCode() != "USD") {

			cout << "\nConverting  From Usd To\n\n";

			_printCurrencyInfo(currency2);

			float fromUsd = currency1.claculateToOtherCurrencies( toUsd, currency2);

			cout << amount << " " << currency1.getCurrencyCode() << " = " << fromUsd << " " << currency2.getCurrencyCode() << endl;


		}



	}



public:

	static void currencyCalculator()
	{

		

		char choice = 'n';

		do {

			system("cls");

			clsHeaderScreen::printHeaderScreen("Currency Calculator");

			_currencyCalculator();
			
			choice = clsInputValidate::readChar(" do you want to perform another calculation? (y/n):");

		} while (choice == 'y' || choice == 'Y');
		


		



	}



};


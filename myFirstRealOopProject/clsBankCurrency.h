#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "myStringLib.h"

using namespace std;


class clsCurrencies {

private:

	enum enMode{enEmptyMode=0,enUpdateMode=1}; 

	enMode _mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrencies _getEmptyObject()
	{

		return clsCurrencies(enMode::enEmptyMode, "", "", "", 0);

	}

	static clsCurrencies _convertLineToCurrencyObject(string line,string delim="#//#")
	{

		vector<string>VCurrency;

		VCurrency = myStringLib::splitString(line, delim);



		return clsCurrencies(enMode::enUpdateMode, VCurrency[0], VCurrency[1], VCurrency[2], stof(VCurrency[3]));


	}

	static string _ConverCurrencyObjectToLine(clsCurrencies Currency, string delim = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.getCountry() + delim;
		stCurrencyRecord += Currency.getCurrencyCode() + delim;
		stCurrencyRecord += Currency.getCurrencyName() + delim;
		stCurrencyRecord += to_string(Currency.getCurrencyRate());

		return stCurrencyRecord;

	}

	static vector<clsCurrencies> _LoadCurrencysDataFromFile()
	{
	
		fstream myFile;
		myFile.open("currencies.txt", ios::in);

		vector <clsCurrencies>vCurrencies;

		if (myFile.is_open()) {

			string line;

			while (getline(myFile, line)) {

				vCurrencies.push_back(_convertLineToCurrencyObject(line));


			}

			myFile.close();
		}

		 
		return vCurrencies;


	
	}

	static void _savecurrenciesDataInFile(vector<clsCurrencies>Vcurrencies)
	{
     
		fstream myFile;

		myFile.open("currencies.txt", ios::out);

		if (myFile.is_open())
		{
			string line;

			for (clsCurrencies currency : Vcurrencies)
			{

				myFile << _ConverCurrencyObjectToLine(currency)<<endl;

			}
			myFile.close();

		}




	}

	 void _update()
	{

		vector<clsCurrencies>Vcurrencies;

		Vcurrencies = _LoadCurrencysDataFromFile();

		for (clsCurrencies& currency : Vcurrencies)
		{

			if (currency._CurrencyCode == getCurrencyCode())
			{
				currency = *this;
				break;

			}


		}

		_savecurrenciesDataInFile(Vcurrencies);

	}




public:

	clsCurrencies(enMode mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{


		_mode = mode;
		_Country=Country;
	    _CurrencyCode= CurrencyCode;
		_CurrencyName= CurrencyName;
		 _Rate= Rate;

	}

	static vector <clsCurrencies> GetAllUSDRates()
	{

		return _LoadCurrencysDataFromFile();

	}

	string getCountry()
	{

		return _Country;

	}

    string getCurrencyCode()
	{

		return _CurrencyCode;

	}

	string getCurrencyName()
	{

		return _CurrencyName;
	}

	float getCurrencyRate()
	{

		return _Rate;

	}
	void setCurrencyRate(float newRate)
	{
		_Rate = newRate;

		_update();

	}

	bool isEmpty()
	{

		return (_mode==enMode::enEmptyMode);

	}


	static clsCurrencies findByCode(string currencyCode)
	{

		fstream myFile;

		myFile.open("currencies.txt", ios::in);

		string line;

		currencyCode=myStringLib::to_upper(currencyCode);


		if (myFile.is_open()) {



			while (getline(myFile,line)) {

				clsCurrencies currency=_convertLineToCurrencyObject(line);

				if (currency.getCurrencyCode() == currencyCode)
				{
					myFile.close();
					return currency;
				}

				
			}
			myFile.close();
			return _getEmptyObject();

		}



	}

	static clsCurrencies findByCountry(string country)
	{

		fstream myFile;

		myFile.open("currencies.txt", ios::in);

		string line;

		country=myStringLib::to_upper(country);


		if (myFile.is_open()) {

			while (getline(myFile, line)) {

				clsCurrencies currency = _convertLineToCurrencyObject(line);

				if (myStringLib::to_upper(currency.getCountry()) == country)
				{
					myFile.close();
					return currency;
				}

			
			}
			myFile.close();
			return _getEmptyObject();

		}



	}

	static bool isCurrencyExist(string currencyCode)
	{
	
		
		clsCurrencies currency=findByCode(currencyCode);

		return !currency.isEmpty();
			

	}

	static vector <clsCurrencies> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

    float calculateToUsd( float amount)
	{

		return (amount / getCurrencyRate());

	}
   
    float claculateToOtherCurrencies(float amount, clsCurrencies currency2)
	{

		float currencyInUsd = calculateToUsd(amount);


		if (currency2.getCurrencyCode() == "USD")
			return currencyInUsd;

		return (amount * currency2.getCurrencyRate());


	}


};


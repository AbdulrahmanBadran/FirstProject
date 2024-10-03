#pragma once

#include <iostream>

#include "clsBankClient.h"
#include "clsHeaderScreen.h"

using namespace std;

class clsTransferScreen :protected clsHeaderScreen {

private:

	static void _printClientCard(clsBankClient client)
	{
		cout << "             client card               \n";
		cout << "------------------------------------------------------------\n";
		cout << "full name             :" << client.fullName() << endl;
		cout << "password              : " << client.getAccountNumber() << endl;
		cout << "permissions           :" << to_string(client.getAccountBalance()) << endl;
		cout << "------------------------------------------------------------\n";


	}

	static clsBankClient _getTheClient(string messege) {


		string accountNumber;

		accountNumber = clsInputValidate::readString(messege);

		while (!clsBankClient::isClientExist(accountNumber))
		{
			accountNumber = clsInputValidate::readString("Wrong number,please enter a valid one:");

		}

		clsBankClient client = client.find(accountNumber);

		return client;
	
	}

	static void _readTheTransferStructure(clsBankClient::stTransferLogInfo &log,double amount,clsBankClient clientFrom,clsBankClient clientTo)
	{
		log.amount = amount;
		log.clientFrom = clientFrom.getAccountNumber();
		log.clientTo = clientTo.getAccountNumber();
		log.clientFromAmount = clientFrom.getAccountBalance();
		log.clientToAmount = clientTo.getAccountBalance();
		log.dateAndTime = clsDate::dateToString(clsDate::getSystemDate())+ "-" +clsDate::getTime();
		log.username = currentUser.getUserName();

		
	}

	static void _transferOperation(clsBankClient& clientFrom, clsBankClient& clientTo,clsBankClient::stTransferLogInfo &log)
	{
		double amount;

		amount = clsInputValidate::readDoubleNumber("please enter Transfer amount:");


		

		while (!clientFrom.Withdraw(amount))
		{
			amount = clsInputValidate::readDoubleNumber("amount Exceeds the available balance,please enter another amount:");

		}

		char insurance;

		cout << "\nare you sure you want to perform this transaction (y/n):";

		cin >> insurance;

		if (insurance == 'y' || insurance == 'Y')
		{
			

			clientTo.Deposit(amount);

			_readTheTransferStructure(log, amount, clientFrom, clientTo);

			cout << "\nAmount Transfered Successfully.\n";

		}

			else
		{

			clientFrom.Deposit(amount);
			cout << "\nthe transaction failed.\n";

		}

	}

	static string _prepareTheTransferLog(clsBankClient::stTransferLogInfo log,string delim="#//#")
	{

		
		return log.dateAndTime + delim + log.clientFrom + delim + log.clientTo + delim + to_string(log.amount) + delim
			+ to_string(log.clientFromAmount) + delim + to_string(log.clientToAmount) 
			+ delim + log.username;



	}

	static void _AddToTransferLog(clsBankClient::stTransferLogInfo log)
	{

		fstream transferLog;

		transferLog.open("transferLog.txt", ios::app | ios::out);

		if (transferLog.is_open())
		{
			transferLog << _prepareTheTransferLog(log)<<endl;

			transferLog.close();
		}



	}


public:

	static void transferScreen()
	{
		clsBankClient::stTransferLogInfo log;

		clsHeaderScreen::printHeaderScreen("Transfer Screen");

		clsBankClient clientFrom = _getTheClient("\n\nplease enter the account number that you want to transfer from:");

		_printClientCard(clientFrom);

		clsBankClient clientTo = _getTheClient("please enter the account number that you want to transfer to:");

		cout << endl << endl;
		_printClientCard(clientTo);

		_transferOperation(clientFrom, clientTo,log);
		_AddToTransferLog(log);


		cout << endl << endl;
		_printClientCard(clientFrom);
		cout << endl << endl;

		_printClientCard(clientTo);
		cout << endl << endl;

	}




};
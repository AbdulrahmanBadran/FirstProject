#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "myStringLib.h"
#include "clsInputValidate.h"

using namespace std;

class clsBankClient : public clsPerson {

private:

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool  _MarkToDelete = false;

	enum enMode{emptyMode=0,updateMode=1,addNewMode=2};

	 enMode _mode;

	 static clsBankClient _convertLineToClientObject(string line, string delim = "#//#") {

		

		vector<string> vRecord;

		vRecord = myStringLib::splitString(line,"#//#");

		return clsBankClient(enMode::updateMode, vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4], clsUtil::_decryptText(vRecord[5]), stof(vRecord[6]));

}
	
	 static clsBankClient _getEmptyObject() {

		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);

	}
	 static clsBankClient _getNewClient() {

		 return clsBankClient(enMode::addNewMode, "", "", "", "", "", "", 0);

	 }

	 static clsBankClient _readClient(clsBankClient & client) {

		 string str;

		 cout << "enter your first name:";
		 
		 cin >> str;

		 client.setFirstName(str);

		 cout<< "enter your last name:";

		 cin >> str;

		 client.setLastName(str);

		 cout << "enter your email:";

		 cin >> str;

		 client.setEmail(str);


		 cout << "enter your phone:";

		 cin >> str;

		 client.setPhone(str);

		 cout << "enter your pin code:";

		 cin >> str;

		 client._PinCode=str;

		 cout << "enter your balance:";

		 cin >> str;

		 client._AccountBalance = stof(str);

		 return client;

	 }

	 static vector<clsBankClient> _saveClientsFileInVector() {

		 fstream clientFile;

		 vector<clsBankClient> vClients;

		 clientFile.open("clientFile.txt", ios::in);

		 if (clientFile.is_open()) {
			 string line;
			 while (getline(clientFile, line)) {


				 vClients.push_back(_convertLineToClientObject(line));


			 }

			 clientFile.close();
		 }

		 return vClients;
	 }

	  static vector<clsBankClient> _refreshTheVector(clsBankClient client,vector<clsBankClient> vClients) {

		

		 for (clsBankClient & clientInVector : vClients) {

			 if (clientInVector._AccountNumber == client._AccountNumber) {

				 clientInVector = client;

			 }


		 }

		 return vClients;
	 }

	  static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	  {

		  string stClientRecord = "";
		  stClientRecord += Client.getFirstName() + Separator;
		  stClientRecord += Client.getLastName() + Separator;
		  stClientRecord += Client.getEmail() + Separator;
		  stClientRecord += Client.getPhone() + Separator;
		  stClientRecord += Client._AccountNumber + Separator;
		  stClientRecord += clsUtil::_EncryptText(Client._PinCode) + Separator;
		  stClientRecord += to_string(Client._AccountBalance);

		  return stClientRecord;

	  }

	  void _addDataLineToFile(string line) {

		  fstream clientFile;



		  clientFile.open("clientFile.txt", ios::out | ios::app);

		  if (clientFile.is_open()) {

			  clientFile << line<<endl;

		  }

		  clientFile.close();



	  }

	  void _update(clsBankClient client) {

		 fstream clientFile;

		 vector<clsBankClient> vClients= _saveClientsFileInVector();

		 vClients = _refreshTheVector(*this, vClients);

		 _refreshClientsDataFile(vClients);


	 }

	  void _addNewClient(clsBankClient client)
	  {

		  _addDataLineToFile(_ConvertClientObjectToLine(client));

	  }

	  void _markForDeletion(string accountNumber, vector<clsBankClient>& vClients) {

		  for (clsBankClient& client : vClients) {
			  if (client.getAccountNumber() == accountNumber)
			  {
				  client.setMarkForDelete(true);
				  return;
			  }


		  }

	  }

	  static void _deleteThisFile() {


		  fstream clientFile;



		  clientFile.open("clientFile.txt", ios::out);

		  if (clientFile.is_open()) {

			  clientFile << "";

		  }

		  clientFile.close();

	  }

	  static void _refreshClientsDataFile(vector<clsBankClient> vClients) {

		  fstream clientFile;

		  _deleteThisFile();

		  clientFile.open("clientFile.txt", ios::out | ios::app);

		  if (clientFile.is_open()) {
			  string line;

			  for (clsBankClient client : vClients)
			  {

				  if (client.getMarkForDelete() == false)
				  {
					  clientFile << _ConvertClientObjectToLine(client) << endl;
				  }


			  }

			  clientFile.close();
		  }



	  }

	  void _delete(string accountNumber)
	  {
		  vector<clsBankClient>vClients = _saveClientsFileInVector();

		  _markForDeletion(accountNumber, vClients);

		  _refreshClientsDataFile(vClients);



	  }
	 
	




public:

	static struct stTransferLogInfo {

		string dateAndTime;
		string clientFrom;
		string clientTo;
		double amount;
		double clientFromAmount;
		double clientToAmount;
		string username;

	};


	string getAccountNumber() 
	{

		return _AccountNumber;

	}

	void setPinCode(string pinCode)
	{
		this->_PinCode = pinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}
	
	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;


	}
	float getAccountBalance()
	{
		return _AccountBalance;
	}

	void setMarkForDelete(bool MarkToDelete) {

		_MarkToDelete = MarkToDelete;
	}
	bool getMarkForDelete() {

		return _MarkToDelete;
	}

	


	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone,string accountNumber, string pinCode, float accountBalance)
		:clsPerson(firstName, lastName, email, phone)
	{

		_mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = accountBalance;


	}

	static clsBankClient find(string accountNumber) {

		fstream clientFile;

		

		clientFile.open("clientFile.txt", ios::in);

		if (clientFile.is_open()) {

			string line;


			while (getline(clientFile, line))
			{

			clsBankClient client=_convertLineToClientObject(line);
			
			if (client._AccountNumber == accountNumber)
				return client;
		}

			clientFile.close();

		}

		return _getEmptyObject();


	}

	static bool isClientExist(string accountNumber) {

		clsBankClient client = find(accountNumber);
		
		return client._mode;

	}

	bool isClientExist() {

		return isClientExist(this->_AccountNumber);

	}

	static bool isEmpty(clsBankClient client) {

		return !(client.isClientExist());

	}

    void update() {

		cout << "update the data:\n";
		cout << "------------------------------------------------------------\n";

		_readClient(*this);
		
		
		cout << "------------------------------------------------------------\n";

		save();

		//client.print();

		

	}

	static void addNewClient() {

		string accountNumber;
		
		accountNumber=clsInputValidate::readString("enter new account number to add:");


		while (isClientExist(accountNumber)) {

			accountNumber = clsInputValidate::readString("this account number is already exist,please enter another account number:");
		}

		clsBankClient newClient = newClient._getNewClient();

		_readClient(newClient);

		newClient.save();

	}

	static clsBankClient getNewClient(string accountNumber)
	{

		return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);


	}

	enum enSvFileResult{svSucceeded=0,svFaildEmptyObject=1, svFaildAccountNumberExists = 2};

	enSvFileResult save() {

		switch (_mode) {

		{
		case enMode::emptyMode:

		   return enSvFileResult::svFaildEmptyObject;

		}

			{case enMode::updateMode:

			     _update(*this);

                     return enSvFileResult::svSucceeded;
			}
		case enMode::addNewMode:

			_addNewClient(*this);

			this->_mode = enMode::updateMode;
			return enSvFileResult::svSucceeded;
		}




	}

	 void Delete() {


			_delete(this->_AccountNumber);

			*this = _getEmptyObject();

		
	}

	static vector<clsBankClient> getClientsList() {

		return _saveClientsFileInVector();


	}

	static double getTotalClientsBalances() {

		vector<clsBankClient> vClients = getClientsList();

		double ClientsBalances = 0;

		for (clsBankClient client : vClients) {

			ClientsBalances += client._AccountBalance;


		}

		return ClientsBalances;

	}

	 void Deposit(double amount)
	{
		_AccountBalance += amount;
		save();

	}

	 bool Withdraw(double amount)
	 {
		 if (amount > _AccountBalance || amount<0) {

			 return false;
		 }
		 else
		 {
			 _AccountBalance -= amount;
			 save();
			 return true;
		 }

	 }

	
	

};
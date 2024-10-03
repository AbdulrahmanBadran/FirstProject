#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "clsPerson.h"
#include "myStringLib.h"
#include "clsInputValidate.h"




using namespace std;


class clsBankUser : public clsPerson
{

private:

	enum enMode{enEmptyMode = 0,enUpdateMode = 1,enAddNewMode = 2,enDeleteMode=3};

	enMode _mode;
	string _userName;
	string _password;
	int _permission;

	bool _markForDeleted = false; 

	static clsBankUser _getEmptyObject() {

		return clsBankUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);

	}

	static clsBankUser _readUser(clsBankUser& user) {

		string str;

		cout << "enter your first name:";

		cin >> str;

		user.setFirstName(str);

		cout << "enter your last name:";

		cin >> str;

		user.setLastName(str);

		cout << "enter your email:";

		cin >> str;

		user.setEmail(str);


		cout << "enter your phone:";

		cin >> str;

		user.setPhone(str);

		cout << "enter your password:";

		cin >> str;

		user._password=str;

		user._permission=readPermission();

		return user;

	}

	static clsBankUser _convertLineToUserObject(string line, string delim = "#//#")
	{

		vector<string> vRecord;

		vRecord = myStringLib::splitString(line, "#//#");
		
	

		return clsBankUser(enMode::enUpdateMode, vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4],clsUtil::_decryptText(vRecord[5]), stof(vRecord[6]));

	}
	 
	static string _ConvertUserObjectToLine(clsBankUser User, string Separator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += User.getFirstName() + Separator;
		stClientRecord += User.getLastName() + Separator;
		stClientRecord += User.getEmail() + Separator;
		stClientRecord += User.getPhone() + Separator;
		stClientRecord += User._userName + Separator;
		stClientRecord += clsUtil::_EncryptText((User._password)) + Separator;
		stClientRecord += to_string(User._permission);

		return stClientRecord;

	}

	static vector<clsBankUser> _refreshTheVector(clsBankUser user, vector<clsBankUser> vUsers) {



		for (clsBankUser& userInVector : vUsers) {

			if (userInVector._userName == user._userName) {

				userInVector = user;

			}


		}

		return vUsers;
	}

	void _deleteThisFile() {


		fstream userFile;



		userFile.open("userFile.txt", ios::out);

		if (userFile.is_open()) {

			userFile << "";

		}

		userFile.close();

	}

	 void _refreshClientsDataFile(vector<clsBankUser> vUsers) {

		fstream userFile;

		_deleteThisFile();

		userFile.open("userFile.txt", ios::out | ios::app);

		if (userFile.is_open()) {
			string line;

			for (clsBankUser user : vUsers)
			{

				if (user.getMarkForDeleted() == false)
				{
					userFile << _ConvertUserObjectToLine(user) << endl;
				}


			}

			userFile.close();
		}



	}

	static vector<clsBankUser> _saveUsersFileInVector() {

		fstream userFile;

		vector<clsBankUser> vUsers;

		userFile.open("userFile.txt", ios::in);

		if (userFile.is_open()) {
			string line;
			while (getline(userFile, line)) {


				vUsers.push_back(_convertLineToUserObject(line));


			}

			userFile.close();
		}

		return vUsers;
	}

	void _update() {

		fstream userFile;

		vector<clsBankUser> vUsers = _saveUsersFileInVector();

		vUsers = _refreshTheVector(*this, vUsers);

		_refreshClientsDataFile(vUsers);


	}

	void _addDataLineToFile(string line) {

		fstream userFile;



		userFile.open("userFile.txt", ios::out | ios::app);

		if (userFile.is_open()) {

			userFile << endl << line << endl;

		}

		userFile.close();



	}

	void _addNewUser()
	{

		_addDataLineToFile(_ConvertUserObjectToLine(*this));

	}

	static vector<string> _getLoginRegisterLines()
	{
		fstream loginRegisterHistory;

		loginRegisterHistory.open("loginRegisterHistory.txt", ios::in);

		vector<string>Vusers;

		if (loginRegisterHistory.is_open()) {
			string line;

			while (getline(loginRegisterHistory, line)) {


				Vusers.push_back(line);

			}
			loginRegisterHistory.close();
		}

		
		return Vusers;

		


	}

	 string _prepareTheRegisterToAdd()
	{

		string _date = clsDate::dateToString(clsDate());
		string _time = clsDate::getTime();


		vector<string>data(4);
		
		string dateAndTime = _date + '-' +(_time);

		data[0] = dateAndTime;
		data[1] = _userName;
		data[2] = _password;
		data[3] = to_string(_permission);

		return myStringLib::JoinString(data, "#//#");


	}

public:

	enum enPermissions { enAll = -1, enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 4, enUpdateClient = 8, enFindClient = 16, enTransactions = 32, enManageUsers = 64,enShowLoginRegisterScreen=128,enCurrencyExchangeScreen=256 };

	clsBankUser(enMode mode, string firstName, string lastName, string email, string phone,
		string userName, string password, int permission)
		: clsPerson(firstName, lastName, email, phone) 
	{
		_userName = userName;

		_password = password;

		_permission = permission;

		_mode = mode;

	}

	bool isEmpty()
	{
		return (_mode == enMode::enEmptyMode);
	}

	static bool isUserExist(string userName)
	{
		clsBankUser user = find(userName);

		return user._mode;
	}

	static int readPermission()
	{
		int permissions = 0;
		char choice = 'n';



		choice = clsInputValidate::readChar(" do you want this user to have all the permissions? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions = -1;
			return permissions;

		}



		choice = clsInputValidate::readChar(" do you want this user to show all client list? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enShowClientList;

		}



		choice = clsInputValidate::readChar(" do you want this user to add new client ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enAddNewClient;

		}



		choice = clsInputValidate::readChar(" do you want this user to delete client ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enDeleteClient;

		}



		choice = clsInputValidate::readChar(" do you want this user to update client ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enUpdateClient;

		}



		choice = clsInputValidate::readChar(" do you want this user to find client ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enFindClient;

		}



		choice = clsInputValidate::readChar(" do you want this user to do transactions ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enTransactions;

		}



		choice = clsInputValidate::readChar(" do you want this user to manage users ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enManageUsers;
		}

		choice = clsInputValidate::readChar(" do you want this user to show login Register List ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enShowLoginRegisterScreen;
		}

		choice = clsInputValidate::readChar(" do you want this user to use Currency Exchange ? (y/n)");

		if (choice == 'y' || choice == 'Y')
		{
			permissions |= enPermissions::enCurrencyExchangeScreen;
		}



		return permissions;
	}

	bool getMarkForDeleted()
	{
		return _markForDeleted;
	}
	void setMarkForDeleted(bool markForDeleted)
	{
		_markForDeleted = markForDeleted;
	}

	string getUserName()
	{
		return _userName;
	}
	void setUserName(string userName)
	{
		_userName = userName;
	}

	string getPassword()
	{
		return _password;
	}
	void setPassword(string password)
	{

		_password = password;

	}

	int getPermission()
	{
		return _permission;
	}
	void setPermission(int permission)
	{
		_permission = permission;
	}

	 bool checkAccessPermissions(enPermissions permissions)
	{

		 if ((this->getPermission() & permissions) == permissions)
			 return true;

		 return false;

	}

	static clsBankUser find(string userName) {

		fstream userFile;



		userFile.open("userFile.txt", ios::in);

		if (userFile.is_open()) {

			string line;


			while (getline(userFile, line))
			{

				clsBankUser user = _convertLineToUserObject(line);

				if (user._userName == userName)
					return user;
			}

			userFile.close();

		}

		return _getEmptyObject();


	}

	static clsBankUser find(string userName,string password) {

		fstream userFile;

		userFile.open("userFile.txt", ios::in);

		if (userFile.is_open()) {

			string line;


			while (getline(userFile, line))
			{

				clsBankUser user = _convertLineToUserObject(line);

				if (user._userName == userName && user._password==password)
					return user;
			}

			userFile.close();

		}

		return _getEmptyObject();


	}


	static clsBankUser addNewUser() {

		string userName;

		userName = clsInputValidate::readString("enter an user name to add:");

		while (clsBankUser::isUserExist(userName)) {

			userName = clsInputValidate::readString("this user name is already exist,please enter a new one:");
		}

		clsBankUser newUser = newUser.getNewUser(userName);

		_readUser(newUser);

		newUser.save();

		return newUser;
	}

	enum enSaveResult{ svFaildEmptyObject  = 0, svSucceeded = 1, svFaildAccountNumberExists };

	enSaveResult save() 
	{

		switch (_mode)
		{
		case enMode::enEmptyMode:
			if(isEmpty())
			{
				return enSaveResult::svFaildEmptyObject;
			}


			break;
		case enMode::enUpdateMode:
		{
			_update();
			return enSaveResult::svSucceeded;


		}


			break;
		case enMode::enAddNewMode:
			if (isUserExist(_userName))
			{
				return enSaveResult::svFaildAccountNumberExists;

			}
			else
			{
				_addNewUser();
				_mode = enMode::enUpdateMode;
				return enSaveResult::svSucceeded;
			}


			break;
		default:
			break;
		}


	}

	 void Delete(string userName)
	{

		vector<clsBankUser>vUsers = _saveUsersFileInVector();

		for (clsBankUser& user : vUsers) {
			if (user.getUserName() == userName)
			{
				user.setMarkForDeleted(true);
				break;
			}


		}

		_refreshClientsDataFile(vUsers);

		*this = _getEmptyObject();
	}

	 void Delete()
	 {
		 Delete(this->_userName);

	 }

	static vector <clsBankUser> getUserList()
	{
		return _saveUsersFileInVector();
	}

	static clsBankUser getNewUser(string userName)
	{

		return clsBankUser(enMode::enAddNewMode, "", "", "", "", userName, "", 0);


	}

    void addToLogInHistory()
	{
		fstream loginRegisterHistory;

		loginRegisterHistory.open("loginRegisterHistory.txt", ios::app | ios::out);


		if (loginRegisterHistory.is_open())
		{

			loginRegisterHistory << _prepareTheRegisterToAdd() << endl;


		}
		loginRegisterHistory.close();






	}

	 static vector<string> getLogInRegisterList()
	{
		vector<clsBankUser>Vusers;

		vector<string>lines = _getLoginRegisterLines();

		return lines;
	}

};


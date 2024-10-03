#pragma once

#include <iostream>
#include "clsUtil.h"
#include "myDateLib.h"
using namespace std;




class clsInputValidate {

public:


	 template <typename T>static T isNumberBetween(T number, T from, T to)
	{

		if (to < from)
			clsUtil::swap(from, to);

		return (number >= from && number <= to);


	}


	/*static bool isNumberBetween(int number, int from, int to)
	{
		if (to < from)
			clsUtil::swap(from, to);

		return (number >= from && number <= to);
	}

	static bool isNumberBetween(float number, float from, float to)
	{
		if (to < from)
			clsUtil::swap(from, to);

		return (number >= from && number <= to);
	}

	static bool isNumberBetween(double number, double from, double to)
	{
		if (to < from)
			clsUtil::swap(from, to);

		return (number >= from && number <= to);
	}*/

	

	static bool isDateBetween(clsDate date, clsDate dateFrom, clsDate dateTo)
	{
		if (dateTo.isBeforeDate(dateFrom))
			clsUtil::swap(dateFrom, dateTo);

		return (date.isAfterDate(dateFrom) && date.isBeforeDate(dateTo));


	}


	
	static int readIntNumber(string messege = "please enter an int value:", string messege2 = "invalid value, please enter a valid one.\n")
	{

		int num;
		cout << messege;
		cin >> num;
		while (!cin>>num) {
			cout << messege2;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> num;
		}

		return num;

	}

	static float readFloatNumber(string messege = "please enter a float value:", string messege2 = "invalid value, please enter a valid one.\n")
	{

		float num;
		cout << messege;
		cin >> num;
		while (cin.fail()) {
			cout << messege2;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> num;
		}

		return num;

	}

	static double readDoubleNumber(string messege = "please enter a double value:", string messege2 = "invalid value, please enter a valid one.\n")
	{

		double num;
		cout << messege;
		cin >> num;
		while (cin.fail()) {
			cout << messege2;				cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> num;
		}

		return num;

	}

	static string readString(string messege = "please enter a string value:", string messege2 = "invalid value, please enter a valid one.\n")
	{

		string var;
		cout << messege;
		cin >> var;
		while (cin.fail()) {
			cout << messege2;				
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> var;
		}

		return var;

	}

	static char readChar(string messege = "please enter a char value:", string messege2 = "invalid value, please enter a valid one.\n")
	{
		char var;
		cout << messege;
		cin >> var;

		while (!cin >> var) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "please enter a valid choice:";
			cin >> var;
		}

		return var;

	}



	static int readIntNumberBetween(int from, int to,string messege1, string messege = "number is not within the range,please enter an in range number")
	{
		int number = 0;

		do {
			number = readIntNumber(messege1, messege);
		} while (!isNumberBetween(number, from, to));

		return number;

	}

	static int readDoubleNumberBetween(double from, double to, string messege = "number is not within the range,please enter an in range number")
	{
		double number = 0;

		do {
			number = readDoubleNumber("please enter an int value:", messege);
		} while (!isNumberBetween(number, from, to));

		return number;


	}

	

	static bool isValidDate(clsDate date) {

		return clsDate::isValidDate(date);

	}




};




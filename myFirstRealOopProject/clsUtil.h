#pragma once

#include <iostream>
#include "myDateLib.h"
using namespace std;



class clsUtil {

public:
	static enum enrandomize { smallLetters = 1, capitalLetters = 2, specialChar = 3, numberDigit = 4, mixChar = 5, mix = 6 };

	static string textAfterEncreption(string word, int key) {
		for (int i = 0; i < word.size(); i++)
		{
			word[i] += key;
		}

		return word;
	}

	static string textAfterDecreption(string word, int key) {

		for (int i = 0; i < word.size(); i++)
		{
			word[i] -= key;
		}

		return word;


	}

	static void Srand() {


		srand((unsigned)time(NULL));
	}

	static int randomNum(int from, int to) {

		int randomNum = rand() % (to - from + 1) + from;
		return randomNum;
	}

	static void tab(int times)
	{
		for (int i = 0; i < times; i++)
		{
			cout << "\t";
		}


	}

	static char RandomSth(enrandomize sth) {
		int random;

		if (sth == enrandomize::mix)
		{

			sth = (enrandomize)randomNum(1, 6);


		}


		if (sth == enrandomize::mixChar)
		{

			sth = (enrandomize)randomNum(1, 2);


		}

		if (sth == enrandomize::smallLetters)
		{
			random = rand() % (122 - 97 + 1) + 97;

			return (char)random;
		}

		if (sth == enrandomize::capitalLetters)
		{
			random = rand() % (90 - 65 + 1) + 65;

			return (char)random;
		}


		if (sth == enrandomize::specialChar)
		{
			random = rand() % (47 - 33 + 1) + 33;

			return (char)random;
		}

		if (sth == enrandomize::numberDigit)

		{
			random = rand() % (57 - 48 + 1) + 48;

			return (char)random;
		}


	}

	static string genarateWord(enrandomize sth, int numberOfChar)
	{
		string word = "";

		for (int i = 0; i < numberOfChar; i++)
		{

			word += RandomSth(sth);


		}

		return word;

	}

	static string genarateKey(enrandomize sth = enrandomize::mix) {

		string key = "";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				key += RandomSth(sth);

			}
			if (i == 3)
				break;
			key += '-';
		}

		return key;
	}

	static void genarateKeys(int keysAmount, enrandomize sth = enrandomize::mix)
	{

		for (int i = 0; i < keysAmount; i++)
		{
			cout << genarateKey(sth) << endl;

		}


	}

	static void readRandomArray(int arr[], int n) {


		for (int i = 0; i < n; i++)
		{
			arr[i] = randomNum(1, 100);
		}

	}

	static void readArray(int arr[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++)
		{
			cin >> arr[i];
		}

	}

	static void readStringArray(string arr[], int arrayLength) {

		for (int i = 0; i < arrayLength; i++)
		{
			arr[i] = genarateKey();
		}


	}

	static void readRandomString(string& word, int wordLength) {

		word += RandomSth(enrandomize::capitalLetters);


		for (int i = 1; i < wordLength; i++)
		{
			if (i == 21)
				word += RandomSth(enrandomize::capitalLetters);
			if (i % 2 != 0)
				word += RandomSth(enrandomize::numberDigit);
			else
				word += RandomSth(enrandomize::smallLetters);

		}

	}

	static void arrayShuffling(int arr[], int arr2[], int arrayLength) {
		int temp;
		int index;

		for (int i = 0; i < arrayLength; i++)
		{

			index = randomNum(0, arrayLength - 1);
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;

		}
		cout << endl;
	}


	template <typename T> static void swap(T& num1, T& num2)
	{

		T temp = num1;
		num1 = num2;
		num2 = temp;

	}

	/*static void swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void swap(float& num1, float& num2)
	{
		float temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void swap(double& num1, double& num2)
	{
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void swap(string& str1, string& str2)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
*/
	static void swap(clsDate& date1, clsDate& date2)
	{

		clsDate tempDate = date1;

		date1 = date2;
		date2 = tempDate;
	}

	static string NumberToText(long long num) {

		string arr1[] = { "zero","one","two","three","four","five","six","seven" ,"eight","nine","ten",
			"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen" };

		string arr2[] = { " ","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty" };

		string arr3[] = { "billion","million","thousand","hundred" };
		if (num == 0)
			return "";

		if (num >= 1 && num <= 19)
			return arr1[num] + " ";

		if (num >= 20 && num <= 99)
			return arr2[num / 10] + " " + NumberToText(num % 10);

		if (num >= 100 && num <= 999)
			return NumberToText(num / 100) + arr3[3] + " " + NumberToText(num % 100);

		if (num >= 1000 && num <= 999999)
			return NumberToText(num / 1000) + arr3[2] + " " + NumberToText(num % 1000);

		if (num >= 1000000 && num <= 999999999)
			return NumberToText(num / 1000000) + " " + arr3[1] + " " + NumberToText(num % 1000000);

		if (num >= 1000000000 && num <= 999999999999)
			return NumberToText(num / 1000000000) + " " + arr3[0] + " " + NumberToText(num % 1000000000);

	}

	static string _EncryptText(string text, int EncryptionKey=2) {

		string EncryptionValue=text;

		for (int i = 0; i < text.length(); i++)
		{

			EncryptionValue[i] = char(int(text[i])) + EncryptionKey;


		}

		return EncryptionValue;

	}

	static string _decryptText(string text, int DecryptionKey=2) {

		string DecryptionValue=text;

		for (int i = 0; i < text.length(); i++)
		{

			DecryptionValue[i] = char(int(text[i])) - DecryptionKey;


		}

		return DecryptionValue;

	}

};

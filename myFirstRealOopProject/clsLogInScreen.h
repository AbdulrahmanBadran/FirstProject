#pragma once

#include <iostream>

#include "clsBamkUser.h"
#include "clsScreens.h"
#include "clsHeaderScreen.h"
#include "clsBankClient.h"



using namespace std;

class clsLogInscreen :protected clsHeaderScreen {
private:
	

public:

	static bool LogInScreen()
	{
		



		system("cls");
		 string username, password;

		clsHeaderScreen::printHeaderScreen("LogIn Screen ");

		bool logIn = true;

		short failesLogInCounter = 0;

		do {
			if (failesLogInCounter == 3) {

				cout << "you are locked after 3 failed trials.";

				system("color 4f");
				system("pause>0");

				return false;

			}

			cout << "enter your username:";

			cin >> username;

			cout << "enter your password:";

			cin >> password;

			currentUser = clsBankUser::find(username,password);

			logIn = currentUser.isEmpty();
			
				if (logIn) {
					failesLogInCounter++;
					cout << "\nInavalid password/username!\n";
					cout << "you have " << 3- failesLogInCounter << " trials to logIn\n\n";
					
				}


		} while (logIn);

		
		currentUser.addToLogInHistory();

		clsScreens::MainMenu();

	}



};
#pragma once

#include <iostream>
#include "clsUtil.h"
#include "myDateLib.h"
#include "clsBamkUser.h"
#include "globalVar.h"



using namespace std;


class clsHeaderScreen {
	public:

	static void printHeaderScreen(string screenName,string secondText=" ") {

		clsUtil::tab(4);
		cout << "---------------------------------------------\n";
		clsUtil::tab(6);
		cout << screenName<<"\n";
		
		

		if (secondText != " ") {
			cout << endl;
			clsUtil::tab(6);
			cout << secondText << "\n";
		}
		clsUtil::tab(4);
		cout << "---------------------------------------------\n\n";

		clsUtil::tab(4);

		cout << "user:" << currentUser.getUserName() <<endl;

		clsUtil::tab(4);

		cout<<"date:"<<clsDate::dateToString(clsDate());
		cout << endl;


	}


	static bool CheckAccessPermission(clsBankUser::enPermissions permission)
	{

		if (!currentUser.checkAccessPermissions(permission))
		{
			clsUtil::tab(4);
			cout << "______________________________________________\n\n";
			clsUtil::tab(5);
			cout << "Access Dinaiable,contact your Admin." << "\n";

			clsUtil::tab(4);
			cout << "______________________________________________\n";
			return  false;
		}
		return true;

	}



};


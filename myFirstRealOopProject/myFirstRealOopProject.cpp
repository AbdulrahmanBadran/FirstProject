#include <iostream>
#include "clsBankClient.h"
#include "clsHeaderScreen.h"
#include "clsScreens.h"
#include "clsPerson.h"
#include <vector>
#include "clsMainTransactionsScreen.h"
#include "clsBamkUser.h"
#include "clsShowUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsLogInScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsTransferScreen.h"


using namespace std;






int main()
{

	while (true)
	{
		if (!clsLogInscreen::LogInScreen())
		{
			break;

		}	

	
	}
	
	//clsTransferScreen::transferScreen();

	

	

	system("pause>0");
}


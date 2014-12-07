#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

void MainMenu();
int main()
{

	bool adminStatus = false;
	Accounts test;
	int selection;

	while (selection != 0 && selection != 2)
	{
		cout << "\nPlease make a selection:\n"
		"1--Sign Up\n"
		"2--Log in\n"
		"0--Exit\n\n"
		"Selection: ";
		selection = GetValidInt(2,0);
		switch(selection)
		{
			case 1: test.SignUp();
			break;
			case 2: cout << endl;
			test.LogIn(adminStatus);

			system("CLS");
			if (adminStatus == true)
			{
				test.AdminSelection();
			}
			else
			{
				MainMenu();
			}
		}
		test.CloseAccounts();



	}

	return 0;
}


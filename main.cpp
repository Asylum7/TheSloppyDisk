#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"
#include "Prospects.h"

void MainMenu();
int main()
{
	ResizeWindow();
	bool adminStatus = false;
	Accounts test;
	int selection;

	MenuHeader();
	cout << "\nPlease make a selection:\n"
	"1--Sign Up\n"
	"2--Log in\n"
	"3--Help\n"
	"0--Exit\n\n"
	"Selection: ";
	selection = GetValidInt(3,0);

	while (selection != 0)
	{
		switch(selection)
		{
		case 1: test.SignUp();
				break;
		case 2: cout << endl;
				test.LogIn(adminStatus);

				if (adminStatus == true)
				{
					AdminMenuHeader();
					test.AdminSelection();
				}
				else
				{
					MainMenu();
				}
				break;
		case 3: Help();
				break;
		default: cout << "***INVALID***\n\n";
				break;
		}
		test.CloseAccounts();

		MenuHeader();
		cout << "\nPlease make a selection:\n"
		"1--Sign Up\n"
		"2--Log in\n"
		"3--Help\n"
		"0--Exit\n\n"
		"Selection: ";
		selection = GetValidInt(3,0);
	}


	return 0;
}


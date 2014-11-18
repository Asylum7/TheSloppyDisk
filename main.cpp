#include"header.h"

int main()
{
	bool adminStatus = false;
	Accounts test;
	int selection;

	while (selection != 0 && selection != 2)
	{
		cout <<	  "\nPlease make a selection:\n"
				  "1--Sign Up\n"
				  "2--Log in\n"
				  "0--Exit\n\n"
				  "Selection: ";

		cin  >> selection;
		cin.ignore();

		switch(selection)
		{
		case 1: test.SignUp();
				break;
		case 2: cout << endl;
				test.LogIn(adminStatus);

				if (adminStatus == true)
				{
					test.AdminSelection();
				}
				else
				{
					//Joshs code can go here
					cout << "Josh Code";
				}
		}
		test.CloseAccounts();
	}

	return 0;
}

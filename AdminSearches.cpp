#include "header.h"

/******************************************************************************
 * FUNCTION - SearchUserName
 * ___________________________________________________________________________
 * Allows admin to search for a username..nothing else
 ******************************************************************************/
void Accounts::SearchUserName()
{
	AdminMenuHeader();
	bool sameUserName = false;
	string searchItem;

	//INPUT--From admin, the username they wanna search for
	cout << "Enter the user name you would like to search for: ";
	getline(cin, searchItem);

	//Calls checkusername function to search for username
	sameUserName = CheckUsername(searchItem);

	if (sameUserName == true)
	{
		cout << "Found user: " << searchItem;
		cout << "\nTo edit user..go to account "
				"options in main admin menu\n\n";
	}
	else
	{
		cout << "Did not find user: " << searchItem;
	}
	cout << endl << endl;
	system("pause");
}
/******************************************************************************
 * FUNCTION - Search company name
 * ___________________________________________________________________________
 * Allows admin to search for a company name
 ******************************************************************************/
void Accounts::SearchCompanyName()
{
	AdminMenuHeader();
	string searchItem;
	bool companyName = false;
	unsigned int i = 0;

	//INPUT--From admin, the company name they would like to search for
	cout << "Enter the name of the company you would like to search for: ";
	getline(cin, searchItem);

	StringToupper(searchItem);

	//OUTPUTS--All companies found and that are not admins.
	while (i < accounts.size() && !companyName)
	{
		if(accounts[i].name == searchItem && accounts[i].adminStatus != 1)
		{
			companyName = true;
		}
		else
		{
			i++;
		}
	}

	if (companyName == true)
	{
		cout << "\nFound company name: " << searchItem << endl;
		cout << "Company Address   : " << accounts[i].address << " "
									   << accounts[i].city << ", "
									   << accounts[i].state << " "
									   << accounts[i].zip << endl;
		cout << "Their Interest    : " << accounts[i].theirInterest << endl;
		cout << "Our Interest      : " << accounts[i].ourInterest << endl;
	}
	else
	{
		cout << "Company name: " << searchItem << " was NOT found";
	}
	cout << endl << endl;;
	system("pause");
}
/******************************************************************************
 * FUNCTION - SearchCity
 * ___________________________________________________________________________
 * Allows admin to search for users in a specific city
 ******************************************************************************/
void Accounts::SearchCity()
{
	AdminMenuHeader();
	string searchItem;
	bool found = false;
	unsigned int i = 0;

	//Admin enters in the city they would like to search for
	cout << "Enter the city of the company you would like to search for: ";
	getline(cin, searchItem);

	StringToupper(searchItem);

	//OUTPUTS--All companies found in this city.
	cout << "Companies located in the city " << searchItem << ":\n";
	while (i < accounts.size())
	{
		if(accounts[i].city == searchItem && accounts[i].adminStatus != 1)
		{
			cout << endl << "Company Name      : "<< accounts[i].name
					<< endl;
			cout << "Company Address   : " << accounts[i].address << " "
										   << accounts[i].city << ", "
										   << accounts[i].state << " "
										   << accounts[i].zip << endl;
			cout << "Their Interest    : " << accounts[i].theirInterest << endl;
			cout << "Our Interest      : " << accounts[i].ourInterest << endl;
			found = true;
			i++;
		}
		else
		{
			i++;
		}
	}
	if (!found)
	{
		cout << " None";
	}
	cout << endl << endl;
	system("pause");
}

/******************************************************************************
 * FUNCTION - SearchState
 * ___________________________________________________________________________
 * Allows admin to search for users in a specific state
 ******************************************************************************/
void Accounts::SearchState()
{
	AdminMenuHeader();
	string searchItem;
	bool found = false;
	unsigned int i = 0;

	//Allows admin to search by state
	cout << "Enter the state of the company you would like to search for: ";
	getline(cin, searchItem);

	StringToupper(searchItem);

	//OUTPUTS--All companes found in a specific state that are NOT admins
	cout << "Companies located in the state " << searchItem << ":\n";
	while (i < accounts.size())
	{
		if(accounts[i].state == searchItem && accounts[i].adminStatus != 1)
		{
			cout << endl << "Company Name      : "<< accounts[i].name
					<< endl;
			cout << "Company Address   : " << accounts[i].address << " "
										   << accounts[i].city << ", "
										   << accounts[i].state << " "
										   << accounts[i].zip << endl;
			cout << "Their Interest    : " << accounts[i].theirInterest << endl;
			cout << "Our Interest      : " << accounts[i].ourInterest << endl;
			found = true;
			i++;
		}
		else
		{
			i++;
		}
	}
	if (!found)
	{
		cout << " None";
	}
	cout << endl << endl;
	system("pause");
}

/******************************************************************************
 * FUNCTION - SearchZip
 * ___________________________________________________________________________
 * Allows admin to search for users in a specific zip code area
 ******************************************************************************/
void Accounts::SearchZip()
{
	AdminMenuHeader();
	int searchItem;
	bool found = false;
	unsigned int i = 0;

	//Allows admin to search for a specific zip
	cout << "Enter the zip of the company you would like to search for: ";
	searchItem = GetValidInt(99999, 00000);

	//OUTPUTS--All companies located in the specific zip code, that are not
	// admins
	cout << "Companies located in the zip code " << searchItem << ":\n";
	while (i < accounts.size())
	{
		if(accounts[i].zip == searchItem && accounts[i].adminStatus != 1)
		{
			cout << endl << "Company Name      : " << accounts[i].name
					<< endl;
			cout << "Company Address   : " << accounts[i].address << " "
										   << accounts[i].city << ", "
										   << accounts[i].state << " "
										   << accounts[i].zip << endl;
			cout << "Their Interest    : " << accounts[i].theirInterest << endl;
			cout << "Our Interest      : " << accounts[i].ourInterest << endl;
			found = true;
			i++;
		}
		else
		{
			i++;
		}
	}
	if (!found)
	{
		cout << " None";
	}
	cout << endl << endl;
	system("pause");
}

/******************************************************************************
 * FUNCTION - SearchTheirInterest
 * ___________________________________________________________________________
 * Allows admin to search for users by user interest
 ******************************************************************************/
void Accounts::SearchTheirInterest()
{
	string searchItem;
	int response;
	int count = 0;
	AdminMenuHeader();
	cout << "Search for users with interest:\n"
			"1--Very Interested\n"
			"2--Somewhat Interested\n"
			"3--Not Interested\n"
			"4--Never Call Again\n"
			"0--Return to Previous Menu\n\n"
			"Selection: ";

	response = GetValidInt(4, 0);

	while (response != 0)
	{
		switch (response)
		{
			case 1: searchItem = "very interested";
				break;
			case 2: searchItem = "somewhat interested";
				break;
			case 3: searchItem = "not interested";
				break;
			case 4: searchItem = "never call again";
				break;
			case 0:
				break;
			default: cout << "\nINVALID INPUT\n";
		}

		cout << endl;
		if(response == 1)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].theirInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}
		else if (response == 2)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].theirInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}
		else if (response == 3)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].theirInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}
		else if (response == 4)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].theirInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}

		count = 0;
		AdminMenuHeader();
		cout << "Search for users with interest:\n"
				"1--Very Interested\n"
				"2--Somewhat Interested\n"
				"3--Not Interested\n"
				"0--Return to Previous Menu\n\n"
				"Selection: ";

		response = GetValidInt(3, 0);
	}
}

/******************************************************************************
 * FUNCTION - SearchOurInterest
 * ___________________________________________________________________________
 * Allows admin to search for users by our interest
 ******************************************************************************/
void Accounts::SearchOurInterest()
{
	string searchItem;
	int response = 1;
	int count = 0;
	AdminMenuHeader();
	cout << "Search for users with interest level:\n"
			"1--Key\n"
			"2--Nice to Have\n"
			"0--Return to Previous Menu\n\n"
			"Selection: ";

	response = GetValidInt(2, 0);

	cout << endl;
	while (response != 0)
	{

		switch (response)//changes what the searchItem is.
		{
			case 1: searchItem = "key";
				break;
			case 2: searchItem = "nice to have";
				break;
			case 0:
				break;
			default: cout << "\nINVALID INPUT\n";
		}

		if(response == 1)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].ourInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}
		else if (response == 2)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].ourInterest == searchItem && accounts[index].adminStatus != 1)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
					count++;
				}
			}
			cout << "\nNumber of users with interest '" << searchItem << "'= "
					<< count << endl << endl;
			system("pause");
		}

		count = 0;
		AdminMenuHeader();
		cout << "Search for users with interest level:\n"
				"1--Key\n"
				"2--Nice to Have\n"
				"0--Return to Previous Menu\n\n"
				"Selection: ";

		response = GetValidInt(2, 0);
	}
		cout << endl;
}

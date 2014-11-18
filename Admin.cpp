#include "header.h"

void Accounts::AdminPrint()
{
	cout <<  "1--Search by Name\n"
			 "2--Search by Company Name\n"
			 "3--Search by City\n"
			 "4--Search by State\n"
			 "5--Search by Zip\n"
			 "0--Exit\n\n"
			 "Selection: ";
}

void Accounts::AdminSelection()
{
	int selection;

	while (selection != 0)
	{
		cout << endl << endl;
		//Prints the menu for the admin
		AdminPrint();


		cin  >> selection;
		cin.ignore();

		switch(selection)
		{
		case 0:
			break;
		case 1: SearchUserName();
			break;
		case 2: SearchCompanyName();
			break;
		case 3: SearchCity();
			break;
		case 4: SearchState();
			break;
		case 5: SearchZip();
			break;
		default: cout << "***INVALID INPUT****";
		}
	}
}

//Allows admin to Search for a user name
void Accounts::SearchUserName()
{
	bool sameUserName = false;
	string searchItem;

	cout << "Enter the user name you would like to search for: ";
	getline(cin, searchItem);

	sameUserName = CheckUsername(searchItem);

	if (sameUserName == true)
	{
		cout << "Found user: " << searchItem;
	}
	else
	{
		cout << "Did not find user: " << searchItem;
	}

}

//Allows admin to Search for a company name
void Accounts::SearchCompanyName()
{
	string searchItem;
	bool companyName = false;
	unsigned int i = 0;

	cout << "Enter the name of the company you would like to search for: ";
	getline(cin, searchItem);

	while (i < accounts.size() && !companyName)
	{
		if(accounts[i].name == searchItem)
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
		cout << "Found company name: " << searchItem;
	}
	else
	{
		cout << "Company name: " << searchItem << " was NOT found";
	}
}

//Allows admins to search by city
void Accounts::SearchCity()
{
	string searchItem;
	unsigned int i = 0;

	cout << "Enter the city of the company you would like to search for: ";
	getline(cin, searchItem);

	cout << "Companies located in the city " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].city == searchItem)
		{
			cout << endl << accounts[i].name << endl;
			i++;
		}
		else
		{
			i++;
		}
	}
}

//Allows admints to search by state
void Accounts::SearchState()
{
	string searchItem;
	unsigned int i = 0;

	cout << "Enter the state of the company you would like to search for: ";
	getline(cin, searchItem);

	cout << "Companies located in the state " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].state == searchItem)
		{
			cout << endl << accounts[i].name << endl;
			i++;
		}
		else
		{
			i++;
		}
	}
}

//Allows admints to search by zip
void Accounts::SearchZip()
{
	int searchItem;
	unsigned int i = 0;

	cout << "Enter the zip of the company you would like to search for: ";
	cin  >> searchItem;

	cout << "Companies located in the zip code " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].zip == searchItem)
		{
			cout << endl << accounts[i].name << endl;
			i++;
		}
		else
		{
			i++;
		}
	}
}

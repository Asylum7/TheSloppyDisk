#include "header.h"

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
	bool found = false;
	unsigned int i = 0;

	cout << "Enter the city of the company you would like to search for: ";
	getline(cin, searchItem);

	cout << "Companies located in the city " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].city == searchItem)
		{
			cout << endl << accounts[i].name << endl;
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
}

//Allows admints to search by state
void Accounts::SearchState()
{
	string searchItem;
	bool found = false;
	unsigned int i = 0;

	cout << "Enter the state of the company you would like to search for: ";
	getline(cin, searchItem);

	cout << "Companies located in the state " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].state == searchItem)
		{
			cout << endl << accounts[i].name << endl;
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
}

//Allows admints to search by zip
void Accounts::SearchZip()
{
	int searchItem;
	bool found = false;
	unsigned int i = 0;

	cout << "Enter the zip of the company you would like to search for: ";
	cin  >> searchItem;

	cout << "Companies located in the zip code " << searchItem << ":";
	while (i < accounts.size())
	{
		if(accounts[i].zip == searchItem)
		{
			cout << endl << accounts[i].name << endl;
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
}

void Accounts::SearchTheirInterest()
{
	string searchItem;
	int response = 1;
	while (response != 0)
	{
	cout << "Search for users with interest:\n"
			"1--Very Interested\n"
			"2--Somewhat Interested\n"
			"3--Not Interested\n"
			"0--Return to Previous Menu\n\n"
			"Selection: ";

	cin  >> response;
	cin.ignore(1000, '\n');

	switch (response)
	{
		case 1: searchItem = "very interested";
			break;
		case 2: searchItem = "somewhat interested";
			break;
		case 3: searchItem = "not interested";
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
			if (accounts[index].theirInterest == searchItem)
			{
				cout << "Username: " << accounts[index].username << endl;
				cout << "Company Name: " << accounts[index].name << endl << endl;
			}
		}
	}
	else if (response == 2)
	{
		for (unsigned int index = 0; index < accounts.size(); index++)
		{
			if (accounts[index].theirInterest == searchItem)
			{
				cout << "Username: " << accounts[index].username << endl;
				cout << "Company Name: " << accounts[index].name << endl << endl;
			}
		}
	}
	else if (response == 3)
	{
		for (unsigned int index = 0; index < accounts.size(); index++)
		{
			if (accounts[index].theirInterest == searchItem)
			{
				cout << "Username: " << accounts[index].username << endl;
				cout << "Company Name: " << accounts[index].name << endl << endl;
			}
		}
	}
	}
}

void Accounts::SearchOurInterest()
{
	string searchItem;
	int response = 1;
	while (response != 0)
	{
		cout << "Search for users with interest level:\n"
				"1--Key\n"
				"2--Nice to Have\n"
				"0--Return to Previous Menu\n\n"
				"Selection: ";

		cin  >> response;
		cin.ignore(1000, '\n');

		cout << endl;
		switch (response)
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
				if (accounts[index].ourInterest == searchItem)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
				}
			}
		}
		else if (response == 2)
		{
			for (unsigned int index = 0; index < accounts.size(); index++)
			{
				if (accounts[index].ourInterest == searchItem)
				{
					cout << "Username: " << accounts[index].username << endl;
					cout << "Company Name: " << accounts[index].name << endl << endl;
				}
			}
		}
	}
}

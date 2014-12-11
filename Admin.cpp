#include "header.h"

/******************************************************************************
 * FUNCTION - AdminPrint
 * ___________________________________________________________________________
 * Prints main menu for admin
 ******************************************************************************/
void Accounts::AdminPrint()
{
	AdminMenuHeader();
	cout <<  "1--Search by Name\n"
			 "2--Search by Company Name\n"
			 "3--Search by City\n"
			 "4--Search by State\n"
			 "5--Search by Zip\n"
			 "6--Search by Their Interest\n"
			 "7--Search by Our Interest\n"
			 "8--Account Options\n"
			 "0--Sign Off\n\n"
			 "Selection: ";
}

/******************************************************************************
 * FUNCTION - AdminSelection
 * ___________________________________________________________________________
 * Takes in the admin selection for the main menu
 ******************************************************************************/
void Accounts::AdminSelection()
{
	int selection;

	//Prints the menu for the admin
	AdminPrint();

	selection = GetValidInt(9, 0);

	while (selection != 0)
	{
		cout << endl << endl;

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
		case 6: SearchTheirInterest();
			break;
		case 7: SearchOurInterest();
			break;
		case 8: AccountOptionsSelection();
			break;
		default: cout << "***INVALID INPUT****";
		}

		//Prints the menu for the admin
		AdminPrint();

		selection = GetValidInt(9, 0);
	}
}
/******************************************************************************
 * FUNCTION - AccountOptionsMenu
 * ___________________________________________________________________________
 * Prints account options main menu for admin
 ******************************************************************************/
void Accounts::AccountOptionsMenu()
{
	AdminMenuHeader();
	cout << "1--Create a User\n"
			"2--Edit a User\n"
			"3--Delete a User\n"
			"4--Print Customer List\n"
			"0--Back to Previous Menu\n\n"
			"Selection: ";
}
/******************************************************************************
 * FUNCTION - AccountOptionsSelection
 * ___________________________________________________________________________
 * Takes in the selection from the admin for the menu
 ******************************************************************************/
void Accounts::AccountOptionsSelection()
{
	int accountSelection;

	cout << endl << endl;
	//Prints the menu for the admin
	AccountOptionsMenu();

	accountSelection = GetValidInt(4, 0);
	while (accountSelection != 0)
	{
		switch(accountSelection)
		{
		case 0:
			break;
		case 1: CreateUser();
			break;
		case 2: EditUser();
			break;
		case 3: DeleteUser();
			break;
		case 4: Print();
			break;
		default: cout << "***INVALID INPUT****";
		}

		cout << endl << endl;
		//Prints the menu for the admin
		AccountOptionsMenu();

		accountSelection = GetValidInt(4, 0);
	}


}

/******************************************************************************
 * FUNCTION - CreateUser
 * ___________________________________________________________________________
 * Allows admin to create a user
 ******************************************************************************/
void Accounts::CreateUser()
{
	string username;
	string password;
	string companyName;
	string address;
	string city;
	string state;
	string ourInterest;
	int zip;
	int admin;
	string passwordConfirm;
	bool   validUsername = false;
	int selection;

	//catch classes
	class invalidPasswordLength{};
	class invalidUsernameLength{};
	class passwordConfermationFail{};
	class usernameAlreadyTaken{};
	class invalidGeneralLength{};
	class invalidStateLength{};

	do
		{
			try
			{
				cout << "Please enter a username: ";
				getline(cin, username);

				//error checking for if the username is already taken
				if(CheckUsername(username))throw usernameAlreadyTaken();

				//error checking for minimum length for username
				if(username.length() < 5 || username.length() > 25)throw invalidUsernameLength();
				else
				{
					validUsername = true;
				}
			}

			catch(usernameAlreadyTaken)
			{
				cout << "::ATTENTION:: Username already taken, "
						 "please try again\n";
			}

			catch(invalidUsernameLength)
			{
				cout << "::ATTENTION:: Invalid username, must be between "
						"5 and 25 characters, "
						 "please try again\n\n";
			}


		}while(!validUsername);

		do
		{
			try
			{
				cout << "Please enter a password: ";
				getline(cin, password);

				//error checking for minimum password size
				if(password.length() < 5 || password.length() > 18)throw invalidPasswordLength();

				cout << "Please confirm password: ";
				getline(cin, passwordConfirm);

				//error checking for account input
				if(password != passwordConfirm)throw passwordConfermationFail();

			}
			catch(passwordConfermationFail)
			{
				cout << "::ATTENTION:: Passwords do not match, "
						 "please try again\n";
			}


			catch(invalidPasswordLength)
			{
				cout << "::ATTENTION:: Invalid password, must be between "
						"5 and 18 characters, "
						 "please try again\n\n";
			}
		}while(password.length() < 5 || password.length() > 18 || password != passwordConfirm);


		do
		{
			try
			{
				//input company name from user
				cout << "Please enter in user company name: ";
				getline(cin, companyName);

				//error checking account from user
				if(companyName.length() > 30 || (companyName.length() == 0))throw invalidGeneralLength();
			}
			catch(invalidGeneralLength)
			{
				cout << "::ATTENTION:: Invalid input, must be greater than"
						" 0 characters, and less "
						"than 30 characters, please try again\n\n";
			}
		}while(companyName.length() > 30 || companyName.length() == 0);

		do
		{
			try
			{
				//input address from user
				cout << "Please enter in user address (street address): ";
				getline(cin, address);

				//error checking account from user
				if(address.length() > 30 || address.length() == 0)throw invalidGeneralLength();
			}
			catch(invalidGeneralLength)
			{
				cout << "::ATTENTION:: Invalid input, must be greater than"
								" 0 characters, and less "
								"than 30 characters, please try again\n\n";
			}
		}while(address.length() > 30 || address.length() == 0);

		do
		{
			try
			{
				//input city from user
				cout << "Please enter in user city: ";
				getline(cin, city);

				//error checking account from user
				if(city.length() > 30 || city.length() == 0)throw invalidGeneralLength();
			}
			catch(invalidGeneralLength)
			{
				cout << "::ATTENTION:: Invalid input, must be greater than"
							" 0 characters, and less "
							"than 30 characters, please try again\n\n";
			}
		}while(city.length() > 30 || city.length() == 0);

		do
		{
			try
			{
				//input state from user
				cout << "Please enter in user state: ";
				getline(cin, state);

				//error checking account from user
				if (state.length() != 2)throw invalidStateLength();
			}
			catch(invalidStateLength)
			{
				cout << "::ATTENTION:: Invalid state input, must be 2"
						" characters\n\n";
			}
		}while (state.length() != 2);

		do
		{
			//input zip from user
			cout << "Please enter in user zip code: ";
			zip = GetValidInt(99999, 0);

		}while(zip > 99999 || zip < 0);

		do
		{
			//input admin abilities from the user
			cout << "Enter 0 for Regular user, Enter 1 for Admin: ";
			admin = GetValidInt(1, 0);
		}while(admin > 1 || admin < 0);

			//Allows admin to enter in interest level for the user
			if (admin != 1)
			{
				cout << "Our interest level: \n";
				cout << "1--Key\n"
					"2--Nice To Have\n\n"
					"Selection: ";

				selection = GetValidInt(2, 1);

				//Switch statement for the interest level entered
				switch (selection)
				{
					case 1: ourInterest = "key";
						break;
					case 2: ourInterest = "nice to have";
						break;
					default: cout << "***INVALID INPUT***";
				}

			}
			else if (admin == 1)
			{
				ourInterest = "key";
			}


			cout << "Account created! User may now log in\n";

			//creating new instance of accInfo struct to fill with data
			accInfo nextAccount;

			//assigning the users new log in information
			nextAccount.username = username;
			nextAccount.password = password;

			//Sets the class information from the inputs from the user
			nextAccount.name          = companyName;
			nextAccount.address       = address;
			nextAccount.city          = city;
			nextAccount.state         = state;
			nextAccount.zip			  = zip;
			nextAccount.adminStatus   = admin;
			nextAccount.ourInterest   = ourInterest;

			//setting defaults for all the rest of the information
			nextAccount.theirInterest = "somewhat interested";

			accounts.push_back(nextAccount);

			totalAccounts++;
			validUsername = true;

			system("pause");
		}//END

/******************************************************************************
 * FUNCTION - EditUserMenu
 * ___________________________________________________________________________
 * Prints EditUserMenu for the admin
 ******************************************************************************/
void Accounts::EditUserMenu()
{
	AdminMenuHeader();
	//OUTPUT--Menu
	cout << "\n1--Edit Our Interest\n"
			"2--Edit Admin Status\n"
			"0--Return to Previous Menu\n\n"
			"Selection: ";

}
/******************************************************************************
 * FUNCTION - EditUser
 * ___________________________________________________________________________
 * Prints account options main menu for admin and takes in the
 * selection from the edit user
 ******************************************************************************/
void Accounts::EditUser()
{
	AdminMenuHeader();
	int selection;

	//Calls menu functions
	EditUserMenu();

	//Calls get Valid Int Function
	selection = GetValidInt(2, 0);

	while (selection != 0)
	{
		switch(selection)
		{
			case 0:
				break;
			case 1: EditInterest();
				break;
			case 2: EditAdminStatus();
				break;
			default: cout << "***INVALID INPUT****";
		}

		//Calls menu functions
		EditUserMenu();

		//Calls get Valid Int Function
		selection = GetValidInt(2, 0);
	}
}
/******************************************************************************
 * FUNCTION - Edit Interest
 * ___________________________________________________________________________
 * Allows admin to edit the interest of the user
 ******************************************************************************/
void Accounts::EditInterest()
{
	AdminMenuHeader();
	int selection;
	string userName;
	unsigned int i = 0;
	bool sameUserName = false;

	for (unsigned int index = 0; index < accounts.size(); index++)
	{
		if (accounts[index].adminStatus != 1)
		{
			cout << accounts[index].username << endl;
			cout << accounts[index].ourInterest << endl << endl;
		}
	}

	//Takes in name from user to search
	cout << "Enter the user name you would like to edit (Press X to exit): ";
	getline(cin, userName);

	if (userName != "X" && userName != "x")
	{
		while(i < accounts.size() && !sameUserName)
		{
			if(accounts[i].username == userName && (accounts[i].adminStatus =! 1))
			{
				sameUserName = true;
				break;
			}
			else if (sameUserName != true)
			{
				i++;
			}
		}

		//If found
		if (sameUserName)
		{
			cout << "Found user " << userName << endl;

			cout << "\nWhat would you like to change our interest to?\n";

			//Outputs menu to admin on which selection they would like to
			//make
			cout << "1--Key\n"
					"2--Nice To Have\n"
					"0--Return to Previous Screen\n\n"
					"Selection: ";

			//Get valid input function called
			selection = GetValidInt(2, 0);

			switch (selection)
			{
				case 0:
					break;
				case 1: accounts[i].ourInterest = "key";
				cout << "\nStatus Changed to: " << accounts[i].ourInterest
						<< endl;
					break;
				case 2: accounts[i].ourInterest = "nice to have";
				cout << "\nStatus Changed to: " << accounts[i].ourInterest
						<< endl;
					break;
				default: cout << "***INVALID INPUT***";
			}

		}
		else
		{
			cout << "\nUser not in DataBase!\n";
		}
	}
	cout << endl << endl;
	system("pause");
}
/******************************************************************************
 * FUNCTION - EditAdminStatus
 * ___________________________________________________________________________
 * Allows user to edit Admin status of a user/admin
 ******************************************************************************/
void Accounts::EditAdminStatus()
{
	AdminMenuHeader();
	char response;
	string userName;
	unsigned int i = 0;
	bool sameUserName = false;
	bool adminStatus = false;

	//OUTPUTS--All users and their admin status
	for (unsigned int index = 0; index < accounts.size(); index++)
	{
		cout << accounts[index].username << endl;
		if(accounts[index].adminStatus== 1)
		{
			cout << "ADMIN\n\n";
		}
		else
		{
			cout << "NOT ADMIN\n\n";
		}
	}

	//Takes in the name the admin would like to edit
	cout << "Enter the user name you would like to edit, press X to cancel: ";
	getline(cin, userName);

	if (userName != "X" && userName != "x")
	{
		while(i < accounts.size() && !sameUserName)
		{
			if(accounts[i].username == userName)
			{
				sameUserName = true;
				break;
			}
			else if (sameUserName != true)
			{
				i++;
			}
		}

		if (sameUserName == true)
		{
			if(accounts[i].adminStatus == 1)
			{
				adminStatus = true;
			}
			else
			{
				adminStatus = false;
			}

		if (adminStatus)
		{
			cout << "Would you like to demote this admin to a user? (Y or N)\n";
			cout << "Response: ";
			cin.get(response);
			cin.ignore(1000, '\n');

			response = toupper(response);

			switch (response)
			{
			case 'Y': accounts[i].adminStatus = 0;
					  cout << "\nDEMOTED\n";
					  break;
			case 'N': cout << "\nNO CHANGE!\n" ;
					  break;
			default: cout << "\nINVALID INPUT, ENTER Y or N\n";
			}
		}
		else
		{
			cout << "Would you like to promote this user to a admin? (Y or N)\n";
			cout << "Response: ";
			cin.get(response);
			cin.ignore(1000, '\n');

			response = toupper(response);

			switch (response)
			{
			case 'Y': accounts[i].adminStatus = 1;
					  cout << "\nPROMOTED\n";
					  break;
			case 'N': cout << "\nNO CHANGE!\n" ;
					  break;
			default: cout << "\nINVALID INPUT, ENTER Y or N\n";
			}
		}
		}
		else
		{
			cout << "\nUser not in DataBase!\n";
		}

	}
	cout << endl << endl;
	system("pause");
}
/******************************************************************************
 * FUNCTION - DeleteUser
 * ___________________________________________________________________________
 * Allows the admin to delete a user
 ******************************************************************************/
void Accounts::DeleteUser()
{
	AdminMenuHeader();
	int selection = 0;
	cout << endl;

	//Outputs all the users and their index
	for (unsigned int index = 1; index < accounts.size(); index++)
	{
		cout << index << ": Username: " << accounts[index].username << endl;
		cout << "Company Name: " << accounts[index].name << endl << endl;
	}

	//Admin will type in the index they would like to delete
	cout << "Which user would you like to delete? Type 0 to exit: ";
	selection = GetValidInt(accounts.size() - 1, 0);

	if(selection != 0)
	{
		cout << "ERASED: " << accounts[selection].username;
		accounts.erase(accounts.begin() + selection);
	}
}

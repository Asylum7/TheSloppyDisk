#include "Accounts.h"

//creating an account will generate a queue of account names and passwords
Accounts::Accounts()
{
	string name;
	string address;
	string city;
	string state;
	int    zip = 0;
	int    theirInterest = 0;
	int    ourInterest = 0;
	bool   adminStatus;
	string username;
	string password;
	totalAccounts = 0;

	ifstream inFile;
	inFile.open("accountInformation.txt");

	//has created a queue of account names and passwords
	while(inFile)
	{
		//incrementing the total number of accounts
		totalAccounts++;

		//taking in user address information
		getline(inFile, name);
		getline(inFile, address);
		getline(inFile, city);
		getline(inFile, state);
		inFile >> zip;
		inFile.ignore(10000, '\n');

		//taking in the users interest level
		inFile >> theirInterest;
		inFile.ignore(10000, '\n');

		//taking in our interest level, it's been assigned yet
		inFile >> ourInterest;
		inFile.ignore(10000, '\n');

		//Assigning admin status
		inFile >> adminStatus;
		inFile.ignore(10000, '\n');


		//taking in the username and and password from the input file
		getline(inFile, username);
		getline(inFile, password);

		//creating new instance of accInfo struct to fill with data
		accInfo nextAccount;
		nextAccount.name          = name;
		nextAccount.address       = address;
		nextAccount.city          = city;
		nextAccount.state         = state;
		nextAccount.zip			  = zip;
		nextAccount.theirInterest = theirInterest;
		nextAccount.ourInterest   = ourInterest;
		nextAccount.adminStatus   = adminStatus;
		nextAccount.username      = username;
		nextAccount.password      = password;

		accounts.push_back(nextAccount);
		inFile.ignore(10000, '\n');
	}//END - while(inFile)
	//closing the input file
	inFile.close();
}//END - Default Constructor

//default destructor
Accounts::~Accounts(){}

//MUTATORS/////////////////////////////////////////////////////////////////////

//Sign In method will prompt the user for a username and password, the sign
//in method will then check the validity of the username against the usernames
//already created as well as for being a valid username of over a set length
void Accounts::SignUp()
{
	string username;
	string password;
	string companyName;
	string address;
	string city;
	string state;
	int zip;
	string passwordConfirm;
	bool   validUsername = false;

	//catch classes
	class invalidPasswordLength{};
	class invalidUsernameLength{};
	class passwordConfermationFail{};
	class usernameAlreadyTaken{};

	do
	{
		try
		{
			cout << "Please enter a username: ";
			getline(cin, username);

			//error checking for if the username is already taken
			if(CheckUsername(username))throw usernameAlreadyTaken();

			//error checking for minimum length for username
			if(username.length() < 5)throw invalidUsernameLength();

			cout << "Please enter a password: ";
			getline(cin, password);

			//error checking for minimum password size
			if(password.length() < 5)throw invalidPasswordLength();

			cout << "Please confirm password: ";
			getline(cin, passwordConfirm);

			//error checking for account input
			if(password != passwordConfirm)throw passwordConfermationFail();

			//input company name from user
			cout << "Please enter in your company name: ";
			getline(cin, companyName);

			//input address from user
			cout << "Please enter in your address (street address): ";
			getline(cin, address);

			//input city from user
			cout << "Please enter in your city: ";
			getline(cin, city);

			//input state from user
			cout << "Please enter in your state: ";
			getline(cin, state);

			//input zip from user
			cout << "Please enter in your zip code: ";
			cin  >> zip;
			cin.ignore(1000, '\n');


			cout << "Account created! You may now log in\n";

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

			//setting defaults for all the rest of the information
			nextAccount.theirInterest = 0;
			nextAccount.ourInterest   = 0;
			nextAccount.adminStatus   = 0;

			accounts.push_back(nextAccount);

			totalAccounts++;
			validUsername = true;

		}//END - try
		catch(passwordConfermationFail)
		{
			cout << "::ATTENTION:: Passwords do not match, "
					 "please try again\n";
		}

		catch(usernameAlreadyTaken)
		{
			cout << "::ATTENTION:: Username already taken, "
					 "please try again\n";
		}

		catch(invalidUsernameLength)
		{
			cout << "::ATTENTION:: Invalid username, minimum of "
					 "five characters required, "
					 "please try again\n";
		}

		catch(invalidPasswordLength)
		{

			cout << "::ATTENTION:: Invalid password, minimum of "
					 "five characters required, "
					 "please try again\n";
		}
	}while(!validUsername);

}//END - SignUp


//ACCESSORS////////////////////////////////////////////////////////////////////

//The following method will allow the user to log into their account. It will
//prompt for a username and password and check them against the already-
//created queue of usernames and passwords
bool Accounts::LogIn(bool &adminStatus)
{
	bool loginOk = false;
	adminStatus = false;
	int admin = 0;
	int count = 0;
	string username;
	string password;
	int i =0;

	do
	{
		cout << "Enter username: ";
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, password);

		loginOk = CheckLogin(username, password, i, count);


		if(loginOk)
		{
			admin = accounts[count-1].adminStatus;
			adminStatus = CheckAdmin(adminStatus, admin);

			if (admin)
			{
				cout << "Login successful! Welcome back admin " << username << endl;
			}
			else
			{
				cout << "Login successful! Welcome back user " << username << endl;
			}

		}
		else
		{
			cout << "::ERROR:: Invalid username or password, "
					"please try again\n";
		}
	}while(!loginOk);

	return (loginOk);
}//END - LogIn

//Close accounts method will output to a file a current and comprehensive
//list of all the usernames and passwords currently in the program
void Accounts::CloseAccounts()
{
	ofstream outFile;

	//removing the old accountInformation file
	remove("accountInformation.txt");
	//creating new account information text of the same name as the input file
	outFile.open("accountInformation.txt");

	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		outFile << accounts[i].name 		 << endl;
		outFile << accounts[i].address 		 << endl;
		outFile << accounts[i].city 		 << endl;
		outFile << accounts[i].state		 << endl;
		outFile << accounts[i].zip 			 << endl;
		outFile << accounts[i].theirInterest << endl;
		outFile << accounts[i].ourInterest 	 << endl;
		outFile << accounts[i].adminStatus 	 << endl;
		outFile << accounts[i].username 	 << endl;
		outFile << accounts[i].password;

		if(i != accounts.size() - 1)outFile << endl << endl;
	}

	outFile.close();
}//END - CloseAccounts

//returns the total number of accounts
int Accounts::GetTotAccounts()
{
	return totalAccounts;
}//END - GetTotAccounts

//takes in a username and searches through the queue for any same usernames
bool Accounts::CheckLogin(string username, string password, unsigned int i,
		int &count)
{
	bool loginOk = false;
	i = 0;

	while(i < accounts.size() && !loginOk)
	{
		//checking against the passed in username and password
		loginOk = accounts[i].username == username &&
				  accounts[i].password == password;
		i++;
	}

	count = i;

	return loginOk;
}//END - SearchAccounts

//prints the current list of all usernames and passwords. FOR DEV MODE ONLY
void Accounts::Print()
{
	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		cout << accounts[i].name << endl;
		cout << accounts[i].address << endl;
		cout << accounts[i].city << endl;
		cout << accounts[i].state << endl;
		cout << accounts[i].zip << endl;
		cout << accounts[i].theirInterest << endl;
		cout << accounts[i].ourInterest << endl;
		cout << accounts[i].adminStatus << endl;
		cout << accounts[i].username << endl;
		cout << accounts[i].password << endl;
		if(i <= accounts.size())cout << endl;
	}
}//END - Print

//returns true if a username in the list matches the passed in username
bool Accounts::CheckUsername(string username)
{
	bool sameUsername = false;
	unsigned int i = 0;

	while(i < accounts.size() && !sameUsername)
	{
		if(accounts[i].username == username)
		{
			sameUsername = true;
		}
		else
		{
			i++;
		}
	}

	return sameUsername;
}

bool Accounts::CheckAdmin(bool adminStatus, int admin)
{

	if (admin == 1)
	{
		adminStatus = true;
	}
	else if (admin != 1)
	{
		return false;
	}

	return adminStatus;
}



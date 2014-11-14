#include "Accounts.h"

//creating an account will generate a queue of account names and passwords
Accounts::Accounts()
{
	string name;
	string address;
	string ciry;
	string state;
	int    zip;
	int    theirInterest;
	int    ourInterest;
	bool   adminStatus;
	string username;
	string password;
	totalAccounts = 0;

	ifstream inFile;
	inFile.open("accountInformation.txt");

	//has created a queue of account names and passwords
	while(!inFile.eof())
	{
		//incrementing the total number of accounts
		totalAccounts++;

		//taking in user address


		//taking in the username and and password from the input file
		getline(inFile, username);
		getline(inFile, password);

		//creating new instance of accInfo struct to fill with data
		accInfo nextAccount;
		nextAccount.username = fileUsername;
		nextAccount.password = filePassword;

		accounts.push_back(nextAccount);
	}//END - while(inFile)
	//closing the input file
	inFile.close();
}//END - Default Constructor


Accounts::Accounts(int i)
{

	cout << "Hello";

	string fileUsername;
	string filePassword;
	totalAccounts = 0;

	ifstream inFile;
	inFile.open("accountInformation.txt");

	//has created a queue of account names and passwords
	while(!inFile.eof())
	{
		//incrementing the total number of accounts
		totalAccounts++;

		//taking in the username and and password from the input file
		getline(inFile, fileUsername);
		getline(inFile, filePassword);

		//creating new instance of accInfo struct to fill with data
		accInfo nextAccount;
		nextAccount.username = fileUsername;
		nextAccount.password = filePassword;

		accounts.push_back(nextAccount);

	}//END - while(inFile)

	inFile.close();





}


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
	string passwordConfirm;
	bool   validUsername = false;

	//catch classes
	class invalidPasswordLength{};
	class invalidUsernameLength{};
	class passwordConfermationFail{};
	class usernameAlreadyTaken{};

	do
	{
		//prompting for username, password, and confirm password
		cout << "Please enter a username: ";
		getline(cin, username);
		cout << "Please enter a password: ";
		getline(cin, password);
		cout << "Please confirm password: ";
		getline(cin, passwordConfirm);

		try
		{
			//error checking for account input
			if(password != passwordConfirm)throw passwordConfermationFail();
			//error checking for if username is already taken
			if(CheckLogin(username, password))throw usernameAlreadyTaken();
			//error checking for minimum length size
			if(username.length() < 5)throw invalidUsernameLength();
			//error checking for minimum password size
			if(password.length() < 5)throw invalidPasswordLength();

			cout << "Account created! You may now log in\n";

			//creating new instance of accInfo struct to fill with data
			accInfo nextAccount;
			nextAccount.username = username;
			nextAccount.password = password;

			accounts.push_back(nextAccount);

			totalAccounts++;
			validUsername = true;

		}//END - try
		catch(int passwordConfermationFail())
		{
			cout << "::ATTENTION:: Passwords do not match, "
					 "please try again\n";
		}

		catch(int usernameAlreadyTaken())
		{
			cout << "::ATTENTION:: Username already taken, "
					 "please try again\n";
		}

		catch(int invalidUsernameLength())
		{
			cout << "::ATTENTION:: Invalid username, minimum of "
					 "five characters required, "
					 "please try again\n";
		}

		catch(int invalidPasswordLength())
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
bool Accounts::LogIn()
{
	bool passwordOK = false;
	bool usernameOK = false;
	string username;
	string password;

	do
	{
		cout << "Enter username: ";
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, password);

		usernameOK = CheckLogin(username, password);

		if(passwordOK && usernameOK)
		{
			cout << "Login successful! Welcome back " << username << endl;
		}
		else
		{
			cout << "::ERROR:: Invalid username or password, "
					"please try again\n";
		}
	}while(!(passwordOK && usernameOK));

	return (passwordOK && usernameOK);
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
		outFile << accounts[i].username << endl;
		outFile << accounts[i].password;
		if(i != accounts.size() - 1)outFile << endl;
	}

	outFile.close();
}//END - CloseAccounts

//returns the total number of accounts
int Accounts::GetTotAccounts()
{
	return totalAccounts;
}//END - GetTotAccounts

//takes in a username and searches through the queue for any same usernames
bool Accounts::CheckLogin(string username, string password)
{
	bool sameUsername = false;
	bool samePassword = false;
	unsigned int i = 0;

	while(i < accounts.size() && !sameUsername)
	{
		if(accounts[i].username == username)
		{
			sameUsername = true;
			if(accounts[i].password == password)
			{
				samePassword = true;
			}
		}
		else
		{
			i++;
		}
	}

	return sameUsername && samePassword;
}//END - SearchAccounts

//prints the current list of all usernames and passwords. FOR DEV MODE ONLY
void Accounts::Print()
{
	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		cout << accounts[i].username << endl;
		cout << accounts[i].password << endl;
	}
}//END - Print

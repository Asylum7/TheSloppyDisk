#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_

#include<queue>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//struct to hold all the users account information.
struct accInfo
{
	string name;
	string address;
	string city;
	string state;
	int    zip;
	string theirInterest;
	string ourInterest;
	bool   adminStatus;
	string username;
	string password;
};

class Accounts {
public:
	//default constructor not used, it will not allow the program to be function
	Accounts();
	//overloaded constructor
	Accounts(int i);
	virtual ~Accounts();

//MUTATORS/////////////////////////////////////////////////////////////////////
	//upon successful login,
	//a new username and password will be added to the queue
	void SignUp();

//ACCESSORS////////////////////////////////////////////////////////////////////
	//returns true if login was successful
	bool LogIn(bool &adminStatus);
	//updates the current account text file
	void CloseAccounts();
	//returns the current total number of accounts
	int  GetTotAccounts();
	//returns true if passed in string matches username AND password in list
	bool CheckLogin(string username, string password, unsigned int i,
			int &count);
	//displays the current contents of the queue
	void Print();
	//returns true if the passed in string matches username in list
	bool CheckUsername(string username);
	//returns true if the username is an admin
	bool CheckAdmin(bool adminStatus, int admin);

	//ADMIN FUNCTIONS
	//Prints the main page and menu for an admin user.
	void AdminPrint();
	//Takes in admin choice for menu and does the operation.
	void AdminSelection();
	//Searches for a username.
	void SearchUserName();
	//Searches for a company name.
	void SearchCompanyName();
	//Searches for a city.
	void SearchCity();
	//Searches for a state.
	void SearchState();
	//Searches for a Zip code.
	void SearchZip();
	//Searches for users based on their interest.
	void SearchTheirInterest();
	//Searches for users based on our interest in their business.
	void SearchOurInterest();
	//Prints a page and menu for modifying the list of accounts.
	void AccountOptionsMenu();
	//Takes in admin choice and initiates the desired operation.
	void AccountOptionsSelection();
	//Allows the admin to create a new user.
	void CreateUser();
	//Menu to change existing users.
	void EditUserMenu();
	//Takes in admin choice for editting a user and initiates the operation.
	void EditUser();
	//Allows admin to change ourInterest for a desired user.
	void EditInterest();
	//Allows the admin to change a regular user into an another admin.
	void EditAdminStatus();
	//Allows admin to delete a user.
	void DeleteUser();


private:
	vector<accInfo> accounts;
	vector<accInfo>::iterator it;
	int totalAccounts;
};

#endif /* ACCOUNTS_H_ */

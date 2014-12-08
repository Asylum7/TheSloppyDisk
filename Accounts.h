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
	//returns type if the username is an admin
	bool CheckAdmin(bool adminStatus, int admin);

	//ADMIN FUNCTIONS
	void AdminPrint();
	void AdminSelection();
	void SearchUserName();
	void SearchCompanyName();
	void SearchCity();
	void SearchState();
	void SearchZip();
	void SearchTheirInterest();
	void SearchOurInterest();
	void AccountOptionsMenu();
	void AccountOptionsSelection();
	void CreateUser();
	void EditUserMenu();
	void EditUser();
	void EditInterest();
	void EditAdminStatus();
	void DeleteUser();


private:
	vector<accInfo> accounts;
	vector<accInfo>::iterator it;
	int totalAccounts;
};

#endif /* ACCOUNTS_H_ */

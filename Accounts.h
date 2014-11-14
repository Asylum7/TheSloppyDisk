#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_

#include<queue>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//struct to hold all the users account information
struct accInfo
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
	bool LogIn();
	//updates the current account text file
	void CloseAccounts();
	//returns the current total number of accounts
	int  GetTotAccounts();
	//returns true if passed in string matched username or password in queue
	bool CheckLogin(string username, string password);
	//displays the current contents of the queue
	void Print();

private:
	vector<accInfo> accounts;
	int totalAccounts;
};

#endif /* ACCOUNTS_H_ */

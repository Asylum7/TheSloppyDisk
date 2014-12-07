#include "header.h"
#include "Accounts.h"
void Accounts::AdminPrint()
{
cout << "1--Search by Name\n"
"2--Search by Company Name\n"
"3--Search by City\n"
"4--Search by State\n"
"5--Search by Zip\n"
"6--Search by Their Interest\n"
"7--Search by Our Interest\n"
"8--Account Options\n"
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
cin >> selection;
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
case 6: SearchTheirInterest();
break;
case 7: SearchOurInterest();
break;
case 8: AccountOptionsSelection();
break;
default: cout << "***INVALID INPUT****";
}
}
}
void Accounts::AccountOptionsMenu()
{
cout << "1--Create a User\n"
"2--Edit a User\n"
"0--Back to Previous Menu\n\n"
"Selection: ";
}
void Accounts::AccountOptionsSelection()
{
int accountSelection;
while (accountSelection != 0)
{
cout << endl << endl;
//Prints the menu for the admin
AccountOptionsMenu();
cin >> accountSelection;
cin.ignore();
switch(accountSelection)
{
case 0:
break;
case 1: CreateUser();
break;
case 2: EditUser();
break;
default: cout << "***INVALID INPUT****";
}
}
}
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
bool validUsername = false;
int selection;
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
cout << "Please enter in the company name: ";
getline(cin, companyName);
//input address from user
cout << "Please enter in the address (street address): ";
getline(cin, address);
//input city from user
cout << "Please enter in the city: ";
getline(cin, city);
//input state from user
cout << "Please enter in the state: ";
getline(cin, state);
//input zip from user
cout << "Please enter in the zip code: ";
cin >> zip;
cin.ignore(1000, '\n');
cout << "Enter 0 for Regular user, Enter 1 for Admin: ";
cin >> admin;
cin.ignore(1000, '\n');
if (admin != 1)
{
cout << "Our interest level: \n";
cout << "1--Key\n"
"2--Nice To Have\n\n"
"Selection: ";
cin >> selection;
cin.ignore(1000, '\n');
switch (selection)
{
case 1: ourInterest = "Key";
break;
case 2: ourInterest = "Nice to Have";
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
nextAccount.name = companyName;
nextAccount.address = address;
nextAccount.city = city;
nextAccount.state = state;
nextAccount.zip	= zip;
nextAccount.adminStatus = admin;
nextAccount.ourInterest = ourInterest;
//setting defaults for all the rest of the information
nextAccount.theirInterest = "somewhat interested";
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
}
void Accounts::EditUserMenu()
{
cout << "\n1--Edit Our Interest\n"
"2--Edit Admin Status\n"
"0--Return to Previous Menu\n\n"
"Selection: ";
}
void Accounts::EditUser()
{
int selection;
while (selection != 0)
{
EditUserMenu();
cin >> selection;
cin.ignore(1000, '\n');
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
}
}
void Accounts::EditInterest()
{
int selection;
string userName;
unsigned int i = 0;
bool sameUserName = false;
for (unsigned int index = 0; index < accounts.size(); index++)
{
cout << accounts[index].username << endl;
cout << accounts[index].ourInterest << endl << endl;
}
cout << "Enter the user name you would like to edit (Press X to exit): ";
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
if (sameUserName)
{
cout << "Found user " << userName << endl;
cout << "\nWhat would you like to change our interest to?\n";
cout << "1--Key\n"
"2--Nice To Have\n"
"0--Return to Previous Screen\n\n"
"Selection: ";
cin >> selection;
cin.ignore(1000, '\n');
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
}
void Accounts::EditAdminStatus()
{
char response;
string userName;
unsigned int i = 0;
bool sameUserName = false;
bool adminStatus = false;
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
}

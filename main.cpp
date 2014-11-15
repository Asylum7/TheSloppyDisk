#include"header.h"

int main()
{

	Accounts test;

	cout << "TESTING:\n\n";

	test.Print();

	cout << endl << endl;

	test.SignUp();

	cout << endl << endl;
	test.Print();
	cout << endl << endl;

	test.LogIn();

	cout << endl << endl;


	cout << endl << endl;
	test.Print();

	test.CloseAccounts();

	return 0;
}

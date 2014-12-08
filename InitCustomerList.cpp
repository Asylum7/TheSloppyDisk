#include "header.h"
void InitCustomerList()
{
	Person *personPtr;
	Person *head;
	Person *tail;
	int count;
	count = 1;

	//Declares file stream variables
	ofstream oFile;

	fstream inFile ("inFile.txt", ios::out|ios::in);

	cout << "CUSTOMERS:\n\n";
	head = NULL;
	tail = NULL;
	//Takes in data from a file

	personPtr = NULL;
	while(inFile)
	{
		personPtr = new Person;
		cout << "\nTaking in customer #" << count;
		cout << endl;

		getline(inFile, personPtr->name);
		cout << personPtr->name << endl;

		getline(inFile, personPtr->address);
		cout << personPtr->address << endl;

		getline(inFile, personPtr->address2);
		cout << personPtr-> address2;

		getline(inFile, personPtr->zip);
		cout << personPtr->zip << endl;

		getline(inFile, personPtr->interest);
		cout << personPtr->interest << endl;

		getline(inFile, personPtr->rating);
		cout << personPtr->rating << endl;

		inFile.ignore();
		personPtr->next = NULL;

		if(count == 1)
		{
			head = personPtr;
			tail = personPtr;
		}
		else
		{
			tail = personPtr;
			tail = tail->next;
		}

		count++;
	}
	inFile.close();

	Print(head, inFile);
}

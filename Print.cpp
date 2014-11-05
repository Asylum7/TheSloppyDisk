#include "header.h"
void Print (Person *personPtr, fstream &oFile)
{
	Person *head;

	head = personPtr;
	oFile.open("inFile.txt");

	while (head!= NULL)
	{
		oFile << head->name << endl;
		oFile << head->address << endl;
		oFile << head->address2 << endl;
		oFile << head->zip << endl;
		oFile << head->interest << endl;
		oFile << head->rating;

		if(head->next != NULL)
		{
			oFile << endl << endl;
		}

		head = head->next;
	}

	oFile.close();
}

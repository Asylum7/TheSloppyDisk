#include "header.h"
#include <stdio.h>
#include <stdlib.h>
bool CheckDigit(string inString);
int GetValidInt(int upper, int lower)
{
	string response;
	int intResponse;
	bool invalid;
	do
	{
		getline(cin, response);
		invalid = false;
		if(!CheckDigit(response))
		{
			cout << "\n\nERROR!\n\nPlease enter a number: ";
			invalid = true;
		}
		else if(atoi(response.c_str()) < lower || atoi(response.c_str()) > upper)
		{
			cout << "\n\nERROR!\n\nPlease enter a number between " << lower << " and "
				 << upper << ": ";
			invalid = true;
		}
		else if(response.length() == 0)
		{
			cout << "\n\nERROR!\n\nMust enter an input!:";
			cout << "\n\nSelection: ";
			invalid = true;
		}
	}while(invalid);

	intResponse = atoi(response.c_str());

	return intResponse;
}

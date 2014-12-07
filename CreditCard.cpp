#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

string CreditCard()
{
	bool valid = false;
	string input;
	string lastFour;
	char creditCard[19];
	do
	{
		cout <<"\nPlease input a valid credit card number (xxxx-xxxx-xxxx-xxxx)\n\n";
		getline(cin, input);

		for(int i = 0; i < 19; i ++)
		{
			creditCard[i] = input[i];
		}

		if((creditCard[4] == '-') && (creditCard[9] == '-' ) && (creditCard[14] == '-')
			&& input.length() <= 19)
		{
			for(int i = 0; i < 4; i ++)
			{
				if(!(isdigit(creditCard[i])))
				{
					valid = true;
				}
				else
				{
					valid = false;
				}
			}
			for(int i = 5; i < 9; i ++)
			{
				if(!(isdigit(creditCard[i])))
				{
					valid = true;
				}
				else
				{
					valid = false;
				}
			}
			for(int i = 10; i <14; i ++)
			{
				if(!(isdigit(creditCard[i])))
				{
					valid = true;
				}
				else
				{
					valid = false;
				}
			}
			for(int i = 15; i <19; i ++)
			{
				if(!(isdigit(creditCard[i])))
				{
					valid = true;
				}
				else
				{
					valid = false;
				}
			}
			valid = true;
		}
		else
		{
			cout << "\n**** Invalid Card Number ****\n"
					"Card number format should be (xxxx-xxxx-xxxx-xxxx) "
					"including\n"
					"the dashes\n";
		}
	}while(!valid);


	string a(creditCard);
	lastFour = a.substr(15,18);

	return lastFour;
}

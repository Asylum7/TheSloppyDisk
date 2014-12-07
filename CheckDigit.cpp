#include "header.h"

bool CheckDigit(string inString)
{
	bool digit = true;

	if(inString[0] == '-')
	{
		for(unsigned int i = 1; i < inString.length(); i ++)
		{
			if(!isdigit(inString[i]))
			{
				digit = false;
			}
		}
	}
	else
	{
		for(unsigned int i = 0; i < inString.length(); i ++)
		{
			if(!isdigit(inString[i]))
			{
				digit = false;
			}
		}
	}


	return digit;
}

#include "header.h"

void ModelNumberGenerator(string list[])
{
	srand( time(0) );
		string letters_numbers = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		string modelNumber = "";

		for(int a = 0; a < 100; a ++)
		{
			for (int i = 0; i < 11; i ++)
			{
				modelNumber += letters_numbers[rand() % letters_numbers.size()];
			}
			list[a] = modelNumber;
			modelNumber = "";
		}


}

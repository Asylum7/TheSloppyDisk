#include <iostream>
using namespace std;

void StringToupper(string &word1)
{
	for(unsigned int i = 0; i < word1.size(); i++)
	{
		word1[i] = toupper(word1[i]);
	}
}

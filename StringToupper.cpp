#include <iostream>
using namespace std;

//modifies the string you want to change to upper case
void StringToupper(string &word1)
{
	//looping for the length of the string changing every char toupper
	for(unsigned int i = 0; i < word1.size(); i++)
	{
		word1[i] = toupper(word1[i]);
	}
}//end - StringToupper

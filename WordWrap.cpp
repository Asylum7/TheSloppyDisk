
#include "header.h"

void WordWrap(string &text)
{
	const int BUFFER_SIZE = 80;
    for (unsigned int i = 1; i <= text.length() ; i++)
    {
        if ((i % BUFFER_SIZE) == 0)
        {
            int spaceCount = 0;

            if (text[(i-1)] != ' ')
            {
                for (int j = (i-1); j > -1 ; j--)
                {
                    if (text[j] == ' ')
                    {
                    	text.insert(j, spaceCount, ' ');
                        break;
                    }
                    else spaceCount++;
                }
            }
        }
    }
}

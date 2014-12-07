#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

void PrintReview(Reviews customerReviews[], int &count, ostream &file)
{

	file << "\nCUSTOMER REVIEWS\n"
			"******************************************************************\n";
	for(int i = 0; i < count - 1; i ++)
	{
		file << endl;
		file << customerReviews[i].date;
		file << endl;
		file << customerReviews[i].name;
		file << endl;
		file << customerReviews[i].review;
		if(i < count -2)
		{
			file << "------------------------------------------------------------------";
		}
		file << endl;
	}

	file << "******************************************************************\n";
}

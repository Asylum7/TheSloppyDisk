#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"

void DisplayCart(vector<Earth> &eBots,
				 vector<Air> &aBots,
				 vector<Sea> &sBots,
				 unsigned int &numBots)
{
	unsigned int i;
	int index = 1;
	double totalPrice = 0.0;
	cout << left;
	cout << "\nSHOPPING CART\n";
	cout << "*********************************************"<< endl;
//
//	cout << left;
//	cout << setw(15) << "BOT TYPE" << setw(15) << "MODEL NUMBER" << setw(19)
//		 <<"PRICE" << endl;
//	cout << "------------       ------------   ----------\n\n";


	for(i = 0; i < numBots; i ++)
	{
		if( i < eBots.size())
		{
			cout << "Robot #" << index << endl << endl;
			cout << left;
			//cout << setw(2) << index << ": ";
			eBots[i].DisplayToCart(cout);

			cout << "____________________________________________\n";
			totalPrice += eBots[i].getPrice();
			cout << endl << endl;
			index ++;
		}
		if( i < aBots.size())
		{
			cout << "Robot #" << index << endl << endl;
			//cout << index << ": ";
			aBots[i].DisplayToCart(cout);
			cout << "____________________________________________\n";
			totalPrice += aBots[i].getPrice();
			cout << endl << endl;
			index ++;
		}
		if( i < sBots.size())
		{
			cout << "Robot #" << index << endl << endl;
			//cout << index << ": ";
			sBots[i].DisplayToCart(cout);
			cout << "____________________________________________\n";
			totalPrice += sBots[i].getPrice();
			cout << endl << endl;
			index ++;
		}
	}
	cout << "*********************************************\n"
			" Total Price: $" << totalPrice << endl << endl;

}

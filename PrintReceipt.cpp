#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

void PrintReceipt(vector<Earth> &eBots,
		 	 	  vector<Air> &aBots,
		 	 	  vector<Sea> &sBots,
		 	 	  unsigned int &numBots,
		 	 	  double shipping,
		 	 	  string lastFour)
{
	ShoppingCartHeader();
	double totalPrice = 0;
	int totalE = 0;
	int totalA = 0;
	int totalS = 0;
	unsigned int index;
	int cc;

	cc =atoi(lastFour.c_str());

	time_t now = time(0);
	char* dt = ctime(&now);

	for(index = 0 ;index < numBots; index ++)
	{
		if( index < eBots.size())
		{
			totalPrice += eBots[index].getPrice();
			totalE ++;
		}
		if( index < aBots.size())
		{
			totalPrice += aBots[index].getPrice();
			totalA ++;
		}
		if( index < sBots.size())
		{
			totalPrice += sBots[index].getPrice();
			totalS ++;
		}
	}


		totalPrice += shipping;

		cout << "\n\niRobotsTheBomb Sales Receipt\n"
				"-------------------------------------------\n";
		cout << "Thank you for making iRobotsTheBomb.com\n"
				"your number one choice for you Robot needs!\n\n"
				"iRobotsTheBomb.com\n"
				"123 Robot Drive\n"
				"RobotVille, CA 10101\n"
				"iRobotsTheBomb.com@gmail.com\n\n"
				"Date of Purchase :\n" << dt << endl;
		cout <<	"Credit Card Charged:\n"
				"xxxx-xxxx-xxxx-";
		cout << cc << endl << endl;
		cout << "NUMBER OF EARTH BOTS : "   << totalE << endl;
		cout << "NUMBER OF AIR BOTS   : "   << totalA << endl;
		cout << "NUMBER OF SEA BOTS   : "   << totalS << endl;
		cout << "Shipping             : $"  << shipping << endl;
		cout <<"**************************\n";
		cout << "Order Total: $" << totalPrice << endl;

		cout << endl << endl;
		system("PAUSE");

}

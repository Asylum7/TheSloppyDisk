#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

void DisplayCart(vector<Earth> &eBots,
				 vector<Air> &aBots,
				 vector<Sea> &sBots,
				 unsigned int &numBots);

//prints out the receipt for the user to view total costs
void PrintReceipt(vector<Earth> &eBots,
		 	 	  vector<Air> &aBots,
		 	 	  vector<Sea> &sBots,
		 	 	  unsigned int &numBots,
		 	 	  double shipping,
		 	 	  string lastFour);

//validates credit card informaiton
string CreditCard();

//allows the user to choose their prefered method of shipping
double Shipping();

//totals the price and calculates the total cost for the user
void CheckOut(vector<Earth> &eBots,
		  	  vector<Air> &aBots,
		  	  vector<Sea> &sBots,
		  	  unsigned int &numBots)
{


		int response;
		double shippingOption;
		string lastFour;

		if(numBots <= 0)
		{
			cout << "\nCan't check out, cart is empty\n";
		}
		else
		{
			DisplayCart(eBots, aBots, sBots, numBots);
			cout << CHECK_OUT;
			cin  >> response;
			system("CLS");
			switch(response)
			{
				case 1:
				shippingOption = Shipping();
				lastFour = CreditCard();
				cout << lastFour << endl;
				PrintReceipt(eBots, aBots, sBots, numBots, shippingOption, lastFour);
				eBots.clear();
				aBots.clear();
				sBots.clear();
				numBots = 0;
				cout << "Thank you for your purchase!\n\n";
				break;

			}

			if(response == 2)
			{
				cin.ignore();
			}
		}

}

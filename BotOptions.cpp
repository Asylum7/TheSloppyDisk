#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

string input;
void PurchaseAir(int response,
				 unsigned &totalBots,
				 int &index,
				 string numberList[],
				 Air &airBot,
				 vector<Air> &vectorA)
{
		switch(response)
		{
			case 1:
			airBot.setReset(false);
			vectorA.push_back(airBot);
			cout << "\nAdded to Cart:\n";
			airBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			system("CLS");
			index ++;
			totalBots ++;
			airBot.Reset(numberList[index]);
			break;

			case 2:
			cout << CA_HEADER << A_CUST;
			response = GetValidInt(3,0);
			system("CLS");
			CustomizeAir(response, airBot);
			cout << "\nAdded to Cart:\n";
			airBot.setReset(false);
			vectorA.push_back(airBot);
			index ++;
			totalBots ++;
			airBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			airBot.Reset(numberList[index]);
			break;
		  }

}
void PurchaseEarth(int response,
				   unsigned &totalBots,
				   int &index,
				   string numberList[],
				   Earth &earthBot,
				   vector<Earth> &vectorE)
{

		switch(response)
		{
			// Base model of earth bot
			case 1:
			// Adds base model to vector
			earthBot.setReset(false);
			vectorE.push_back(earthBot);
			cout << "\nAdded to Cart:\n";
			// OUTPUT - displays bot info
			earthBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			system("CLS");
			// Incrementing index and total bots
			index ++;
			totalBots ++;
			// Resets bot back to default values, next model number from
			// the generated list is set as robot model number
			earthBot.Reset(numberList[index]);
			break;

			// Customizable Earth Bot
			case 2:
			// OUTPUT & INPUT
			cout << CE_HEADER << E_CUST;
			response = GetValidInt(3,0);
			system("CLS");
			CustomizeEarth(response, earthBot);
			cout << "\nAdded to Cart:\n";
			earthBot.setReset(false);
			vectorE.push_back(earthBot);
			index ++;
			totalBots ++;
			earthBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			earthBot.Reset(numberList[index]);
			break;
		  }

}
void PurchaseSea(int response,
				   unsigned &totalBots,
				   int &index,
				   string numberList[],
				   Sea &seaBot,
				   vector<Sea> &vectorS)
{

		switch(response)
		{
			case 1:
			seaBot.setReset(false);
			vectorS.push_back(seaBot);
			cout << "\nAdded to Cart:\n";
			seaBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			system("CLS");
			index ++;
			totalBots ++;
			seaBot.Reset(numberList[index]);
			break;

			case 2:
			cout << CS_HEADER << S_CUST;
			response = GetValidInt(3,0);
			system("CLS");
			CustomizeSea(response, seaBot);
			seaBot.setReset(false);
			cout << "\nAdded to Cart:\n";
			vectorS.push_back(seaBot);
			totalBots ++;
			seaBot.Display(cout);
			cout << endl << endl;
			system("PAUSE");
			seaBot.Reset(numberList[index]);
			break;
		  }

}
void CustomizeEarth(int response, Earth &earthBot)
{
	while(response != 0)
	{
		switch(response)
		{
		case 1:
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");

		while(response != 0)
		{
			switch(response)
			{
			case 1:
			earthBot.setiOS(true);
			break;

			case 2:
			earthBot.setAndroid(true);
			break;

			case 3:
			earthBot.setiOS(true);
			earthBot.setAndroid(true);
			break;
			}
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");
		}
		break;

		case 2:
		earthBot.setFour(true);
		break;

		case 3:
		earthBot.setSC(true);
		break;
		}
		cout << E_HEADER << E_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}

}
void CustomizeAir(int response, Air &airBot)
{
	while(response != 0)
	{
		switch(response)
		{
		case 1:
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");

		while(response != 0)
		{
			switch(response)
			{
			case 1:
			airBot.setiOS(true);
			break;

			case 2:
				airBot.setAndroid(true);
			break;

			case 3:
				airBot.setiOS(true);
			airBot.setAndroid(true);
			break;
			}
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");
		}
		break;

		case 2:
		airBot.setAlt(true);
		break;

		case 3:
		airBot.setAuto(true);
		break;
		}
		cout << A_HEADER << A_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}

}
void CustomizeSea(int response, Sea &seaBot)
{
	while(response != 0)
	{
		switch(response)
		{
		case 1:
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");

		while(response != 0)
		{
			switch(response)
			{
			case 1:
			seaBot.setiOS(true);
			break;

			case 2:
			seaBot.setAndroid(true);
			break;

			case 3:
			seaBot.setiOS(true);
			seaBot.setAndroid(true);
			break;
			}
		cout << CONT_UPGRADE;
		response = GetValidInt(3,0);
		system("CLS");
		}
		break;

		case 2:
		seaBot.setSonar(true);
		break;

		case 3:
		seaBot.setSub(true);
		break;
		}
		cout << S_HEADER << S_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}
}
void AddEarthUpgrade(vector<Earth> &eBots, unsigned int &index)
{
	int response;
	cout << E_EDIT << E_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			case 1:
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);
			system("CLS");

			while(response != 0)
			{
				switch(response)
				{
				case 1:
				eBots[index].setiOS(true);
				break;

				case 2:
				eBots[index].setAndroid(true);
				break;

				case 3:
				eBots[index].setiOS(true);
				eBots[index].setAndroid(true);
				break;
				}
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);
			system("CLS");
			}
			break;

			case 2:
			eBots[index].setFour(true);
			break;

			case 3:
			eBots[index].setSC(true);
			break;
		}
	cout << E_EDIT << E_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	}
}
void AddAirUpgrade(vector<Air> &aBots, unsigned int &index)
{
	int response;

	cout << A_EDIT << A_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			case 1:
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);

			while(response != 0)
			{
				switch(response)
				{
				case 1:
				aBots[index].setiOS(true);
				break;

				case 2:
				aBots[index].setAndroid(true);
				break;

				case 3:
				aBots[index].setiOS(true);
				aBots[index].setAndroid(true);
				break;
				}
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);
			system("CLS");
			}
			break;

			case 2:
			aBots[index].setAlt(true);
			break;

			case 3:
			aBots[index].setAuto(true);
			break;
		}
	cout << A_EDIT << A_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	}
}
void AddSeaUpgrade(vector<Sea> &sBots, unsigned int &index)
{
	int response;
	cout << S_EDIT << S_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			case 1:
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);
			system("CLS");

			while(response != 0)
			{
				switch(response)
				{
				case 1:
				sBots[index].setiOS(true);
				break;

				case 2:
				sBots[index].setAndroid(true);
				break;

				case 3:
				sBots[index].setiOS(true);
				sBots[index].setAndroid(true);
				break;
				}
			cout << CONT_UPGRADE;
			response = GetValidInt(3,0);
			system("CLS");
			}
			break;

			case 2:
			sBots[index].setSonar(true);
			break;

			case 3:
			sBots[index].setSub(true);
			break;
		}
	cout << A_EDIT << S_CUST_SP;
	response = GetValidInt(3,0);
	system("CLS");
	}
}
void RemoveAirUpgrades(vector<Air> &aBots, unsigned int &index)
{
	int response;
	cout << A_EDIT << REM_A_CUST;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			case 1:
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");

			while(response != 0)
			{
				switch(response)
				{
				case 1:
				aBots[index].setiOS(false);
				break;

				case 2:
				aBots[index].setAndroid(false);
				break;

				case 3:
				aBots[index].setiOS(false);
				aBots[index].setAndroid(false);
				break;
				}
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");
			}// END - remove controller
			break;

			case 2:
			aBots[index].setAlt(false);
			break;

			case 3:
			aBots[index].setAuto(false);
			break;
		}
		cout << E_EDIT << REM_A_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}
}
void RemoveEarthUpgrade(vector<Earth> &eBots, unsigned int &index)
{
	int response;

	cout << E_EDIT << REM_E_CUST;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			case 1:
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");

			while(response != 0)
			{
				switch(response)
				{
				case 1:
				eBots[index].setiOS(false);
				break;

				case 2:
				eBots[index].setAndroid(false);
				break;

				case 3:
				eBots[index].setiOS(false);
				eBots[index].setAndroid(false);
				break;
				}
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");
			}// END - remove controller
			break;

			case 2:
			eBots[index].setFour(false);
			break;

			case 3:
			eBots[index].setSC(false);
			break;
		}
		cout << E_EDIT << REM_E_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}// END - chose which upgrade to remove
}
void RemoveSeaUpgrade(vector<Sea> &sBots, unsigned int &index)
{
	int response;

	cout << S_EDIT << REM_S_CUST;
	response = GetValidInt(3,0);
	system("CLS");
	while(response != 0)
	{
		switch(response)
		{
			/******************************************
			 * START - Remove Contr Upgrade: Sea Bot
			 ******************************************/
			case 1:
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");

			while(response != 0)
			{
				switch(response)
				{
				// INPUT - sets iOS to false
				case 1:
				sBots[index].setiOS(false);
				break;

				// INPUT - sets android to false
				case 2:
				sBots[index].setAndroid(false);
				break;

				// INPUT - sets iOS/android to false
				case 3:
				sBots[index].setiOS(false);
				sBots[index].setAndroid(false);
				break;
				}
			// Re-initialize LCV
			cout << REMOV_CONT;
			response = GetValidInt(2,0);
			system("CLS");
			}
			break;

			// INPUT - sets sonar to false
			case 2:
			sBots[index].setSonar(false);
			break;

			// INPUT - sets submarine to false
			case 3:
			sBots[index].setSub(false);
			break;
		}
		cout << S_EDIT << REM_S_CUST;
		response = GetValidInt(3,0);
		system("CLS");
	}
}


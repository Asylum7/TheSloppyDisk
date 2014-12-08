#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"
/******************************************************************************
 * PROTOTYPES
 ******************************************************************************/
void ShoppingCart(vector<Earth> &eBots,
		          vector<Air> &aBots,
		          vector<Sea> &sBots,
		          unsigned int &numBots,
		          string numberList[],
		          int &i);
void SelectRobotType(int response,
					 int &index,
					 unsigned int &totalBots,
					 Earth &earthBot,
		             Air &airBot,
		             Sea &seaBot,
		             string numberList[],
		             vector<Earth> &vectorE,
		             vector<Air> &vectorA,
		             vector<Sea> &vectorS);


void ExternalLink(string webLink);
/******************************************************************************
 * FUNCTION - MaiMenu
 * ___________________________________________________________________________
 * This function will create objects of type Earth, Air, and Sea. It will allow
 * the user to make various purchase options to the robots, and will send them
 * to a shopping cart when the user is done
 ******************************************************************************/
void MainMenu()
{
	string numberList[100];
	ofstream oFile;
	oFile.open("modelNum.txt");
	int response;
	int index;
	unsigned int totalBots;

	// CALC - generates a list of random model numbers
	ModelNumberGenerator(numberList);
	for(int index = 0; index < 100; index ++)
	{
		oFile << numberList[index] << endl;
	}

	// CALC - instantiates three objects of type Eart, Air, and Sea.
	//      - To be used to create all robots
	Earth earthBot;
	Air   airBot;
	Sea   seaBot;

	// Creates three vectors to hold shopping cart info
	vector<Earth> vectorE;
	vector<Air>   vectorA;
	vector<Sea>   vectorS;

	// Initializing index and total bots to zero
	index = 0;
	totalBots = 0;

	// OUT & IN - Main Menu
	MenuHeader();
	cout << MAIN_MENU;
	response = GetValidInt(4,0);
	system("CLS");

	while(response != 0)
	{
		switch(response)
		{
		case 1:
		ExternalLink("https://docs.google.com/document/d/1NBhCniSvtfygnMvZYHYM_0HwyD_BE2e_uopF3m0SMRM/edit?usp=sharing");
		break;

		// INPUT & OUTPUT - User will input which type of robot to buy
		case 2:
		RobotCatalogMenu();
		cout << PURCHASE_MENU;
		response = GetValidInt(3,0);
		system("CLS");
		SelectRobotType(response,index,totalBots,earthBot,airBot,seaBot,numberList,
				         vectorE,vectorA,vectorS);
		break;
		case 3:
		if(totalBots == 0)
		{
			cout << "\nCart is empty\n";
		}
		else
		{
			ShoppingCart(vectorE, vectorA, vectorS,totalBots, numberList, index);
		}
		break;

		case 4:
		cout << "\nCustomer Reviews/Testimonials go here\n";
		break;
		}
		MenuHeader();
		cout << MAIN_MENU;
		response = GetValidInt(4,0);

		system("CLS");
	}
}

#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"
/******************************************************************************
 * PROTOTYPES
 ******************************************************************************/
void PurchaseEarth(int response,
				   unsigned int &totalBots,
				   int &index,
				   string numberList[],
				   Earth &earthBot,
				   vector<Earth> &vectorE);
void PurchaseAir(int response,
				 unsigned &totalBots,
				 int &index,
				 string numberList[],
				 Air &airBot,
				 vector<Air> &vectorA);
void PurchaseSea(int response,
				 unsigned &totalBots,
				 int &index,
				 string numberList[],
				 Sea &seaBot,
				 vector<Sea> &vectorS);
/******************************************************************************
 * FUNCTION - SelectRobotType
 * ___________________________________________________________________________
 * This function will allow the user to select which type of robot to select
 ******************************************************************************/
void SelectRobotType(int response,
					 int &index,
					 unsigned int &totalBots,
					 Earth &earthBot,
		             Air &airBot,
		             Sea &seaBot,
		             string numberList[],
		             vector<Earth> &vectorE,
		             vector<Air> &vectorA,
		             vector<Sea> &vectorS)
{
	while(response != 0)
	{
		switch(response)
		{
		// INPUT - Earth Bot
		case 1:
		// Initializes model number of first earth bot
		earthBot.setNum(numberList[index]);
		// INPUT & OUTPUT - purchase options for earth bot
		cout << E_HEADER << PURCHASE_OPTIONS;
		response = GetValidInt(2,0);
		system("CLS");
		PurchaseEarth(response,totalBots,index,numberList,earthBot,vectorE);
		system("CLS");
		break;

		case 2:
		airBot.setNum(numberList[index]);
		index ++;

		cout << A_HEADER << PURCHASE_OPTIONS;
		response = GetValidInt(2,0);
		system("CLS");
		PurchaseAir(response,totalBots,index,numberList,airBot,vectorA);
		system("CLS");
		break;

		case 3:
		seaBot.setNum(numberList[index]);
		index ++;

		cout << S_HEADER << PURCHASE_OPTIONS;
		response = GetValidInt(2,0);
		system("CLS");
		PurchaseSea(response,totalBots,index,numberList,seaBot,vectorS);
		system("CLS");

		break;
		}

	cout << PURCHASE_MENU;
	response = GetValidInt(3,0);
	system("CLS");
	}
}//end - SelectRobotType

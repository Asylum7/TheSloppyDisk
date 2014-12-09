#include "header.h"

void ContactUsHeader()
{
	//clearing the screen of any text before the main menu
	system( "cls" );

	//setting background color to light gray and text color to black
	system ("color 70");

	const string contactHeader = "\n"
			"		'##::::'##:'########:'##:::::::'########:::'##::::'##:'########:'##::: ##:'##::::'##:\n"
			"		 ##:::: ##: ##.....:: ##::::::: ##.... ##:: ###::'###: ##.....:: ###:: ##: ##:::: ##:\n"
			"		 ##:::: ##: ##::::::: ##::::::: ##:::: ##:: ####'####: ##::::::: ####: ##: ##:::: ##:\n"
			"		 #########: ######::: ##::::::: ########::: ## ### ##: ######::: ## ## ##: ##:::: ##:\n"
			"		 ##.... ##: ##...:::: ##::::::: ##.....:::: ##. #: ##: ##...:::: ##. ####: ##:::: ##:\n"
			" 		 ##:::: ##: ##::::::: ##::::::: ##::::::::: ##:.:: ##: ##::::::: ##:. ###: ##:::: ##:\n"
			" 		 ##:::: ##: ########: ########: ##::::::::: ##:::: ##: ########: ##::. ##:. #######::\n"
			"		 ..:::::..::........::........::..::::::::::..:::::..::........::..::::..:::.......:::\n";

	cout << contactHeader << endl;


}

void ContactUs()
{
	ContactUsHeader();

	cout << "iRobotsTheBomb\n"
			"431 Sulfur Street\n"
			"Lake Forest, CA. 92630\n"
			"Toll Free: 1(800)-WTF-DIAF\n"
			"iRobotsTheBomb.com@gmail.com";

	cout << "\n\nPress enter to return to the main menu...";
	system("pause");
}

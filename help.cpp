#include "header.h"

//help menu to guide the user through using the program. Internet
//connection required
void Help()
{
	//printing help header and help color
	HelpMenuHeader();

	cout << "You are being redirected to an online help tutorial!\n\n";

	//Opening external google docs link to an interactive help menu
	ExternalLink("https://docs.google.com/document/d/1YoCcngpTv694s-"
			     "Jo6ML1giQqiH-_BI9D4yEXM0nytvI/edit?usp=sharing");

	cout << "For other help options please contact us at:\n\n";
	cout << "Phone:   1-800-ROBOTCARE\n";
	cout << "Email:   iRobotsTheBomb.com@gmail.com\n";
	cout << "Fax:     1-888-ROBOTFAXS\n\n";

	//holding the program until the user presses any key
	system("pause");
}

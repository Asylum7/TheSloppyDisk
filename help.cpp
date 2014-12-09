#include "header.h"

void Help()
{
	HelpMenuHeader();
	string helpText;
	helpText = "Using the iRobotsTheBomb interactive brochure is easy! "
			"You will be guided through your purchasing process by a series of menus. "
			"Each menu will give you a series of numbered options. Once you've decided "
			"which option you would like to select, simply type the corresponding number "
			"press the enter button. When being asked for input, be sure to carefully "
			"enter the correct information in the correct format, as specified by the "
			"prompt.";
	WordWrap(helpText);
	cout << helpText;

	cout << "\n\nPress enter to return to the main menu...";
	system("pause");
}

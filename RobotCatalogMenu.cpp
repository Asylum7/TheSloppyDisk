#include <Windows.h>
#include <iostream>
using namespace std;

/*
Color Codes:
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/

void RobotCatalogMenu()
{
	//clearing the screen of any text before the main menu
	system( "cls" );

	//setting background color to red and text color to white
	system ("color 4F");

	const string robotMenu = "\n"
			" ooooooooo            oooo                  o8      ooooooo8            o8               o888\n"
			"  88    888  oooooo   888oooo     oooooo  o888oo  o888     88   oooooo o888oo  oooooo    888   oooooo    ooooooo8\n"
			"  88oooo88 888    888 888   888 888    888 888    888          'oooo888 888   'oooo888   888 888    888 888    88o\n"
			"  88  88o  888    888 888   888 888    888 888    888o     oo 888   888 888  888   888   888 888    888  888oo888o\n"
			" o88o  88o8  88oo88  o888oo88     88oo88    888o   888ooo88    88oo88 8o 888o  88oo88 8oo888o  88oo88         888\n"
			"                                                                                                         888ooo888\n";

	cout << robotMenu << endl;

}//end - RobotCatalogMenu

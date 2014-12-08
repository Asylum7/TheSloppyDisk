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

void AdminMenuHeader()
{
	//clearing the screen of any text before the main menu
	system( "cls" );

	//setting background color to red and text color to white
	system ("color FC");

	const string AdminMenu = "\n"
			"	     /.\\          ||`                                       ||                     ||                 \n"
			"	    // \\\\         ||              ''            ''          ||                     ||                 \n"
			"	   //...\\\\    .|''||  '||),,(|,   ||  `||''|,   ||  ('''' ''||''  '||''|  '''|.  ''||''  .|''|, '||''|\n"
			"	  //     \\\\   ||  ||   || || ||   ||   ||  ||   ||   `'')   ||     ||    .|''||    ||    ||  ||  ||   \n"
			"	.//       \\\\. `|..||. .||    ||. .||. .||  ||. .||. `...'   `|..' .||.   `|..||.   `|..' `|..|' .||.  \n";

	cout << AdminMenu << endl;


}

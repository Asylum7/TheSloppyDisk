#include <iostream>
#include <Windows.h>
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

void MenuHeader()
{
	//clearing the screen of any text before the main menu
	system( "cls" );

	//setting background color to gray and text color to white
	system ("color 8F");

    const string logo = "\n"
    		"  d8b 8888888b.         888             888       88888888888888             888888b.                       888      \n"
    		"  Y8P 888   Y88b        888             888           888    888             888  `88b                      888      \n"
    		"      888    888        888             888           888    888             888  .88P                      888      \n"
    		"  888 888   d88P .d88b. 88888b.  .d88b. 888888.d8888b 888    88888b.  .d88b. 8888888K.  .d88b. 88888b.d88b. 88888b.  \n"
    		"  888 8888888P` d88``88b888 `88bd88``88b888   88K     888    888 `88bd8P  Y8b888  `Y88bd88``88b888 `888 `88b888 `88b \n"
    		"  888 888 T88b  888  888888  888888  888888   `Y8888b.888    888  88888888888888    888888  888888  888  888888  888 \n"
    		"  888 888  T88b Y88..88P888 d88PY88..88PY88b.      X88888    888  888Y8b.    888   d88PY88..88P888  888  888888 d88P \n"
    		"  888 888   T88b `Y88P` 88888P`  `Y88P`  `Y888 88888P`888    888  888 `Y8888 8888888P`  `Y88P` 888  888  88888888P`  \n\n"
    		"  ================================================================================================================\n"
    		"				____         __                       ___         \n"
    		"				 /  / _ '_  / _)  _  /  _  (__/    _ (_  '_ /_/   \n"
    		"				(  /)(-//  /(_)()//)()_) ,  / ()(//  /  /(//)/    \n"
    		"                                                          _/            _/        \n"
    		"  ================================================================================================================\n";

	cout << logo << endl;

}//end - MenuHeader

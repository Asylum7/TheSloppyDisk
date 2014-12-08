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

void ShoppingCartHeader()
{
	//clearing the screen of any test before the shopping cart menu
	system( "cls" );

	//setting background color to aqua and the text color to white
	system( "color 3F" );

	const string shoppingCartLogo = "\n"
			"    _|_|_|  _|                                      _|                        _|_|_|                        _|      \n"
			"  _|        _|_|_|      _|_|    _|_|_|    _|_|_|        _|_|_|      _|_|_|  _|          _|_|_|  _|  _|_|  _|_|_|_|  \n"
			"    _|_|    _|    _|  _|    _|  _|    _|  _|    _|  _|  _|    _|  _|    _|  _|        _|    _|  _|_|        _|      \n"
			"        _|  _|    _|  _|    _|  _|    _|  _|    _|  _|  _|    _|  _|    _|  _|        _|    _|  _|          _|      \n"
			"  _|_|_|    _|    _|    _|_|    _|_|_|    _|_|_|    _|  _|    _|    _|_|_|    _|_|_|    _|_|_|  _|            _|_|  \n"
			"                                _|        _|                            _|                                          \n"
			"                                _|        _|                        _|_|                                            \n";

	cout << shoppingCartLogo << endl;


}

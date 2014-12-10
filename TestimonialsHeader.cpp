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

//outputs the shopping cart header
void TestimonialsHeader()
{
	//clearing the screen of any test before the testimonials menu
	system( "cls" );

	//setting background color to white and the text color to black
	system( "color F1" );

	const string TestimonialsLogo = "\n"
			"  ::::::::::::.,:::::: .::::::.::::::::::::::: .        :       ...   :::.    :::.:::  :::.      :::     .::::::. \n"
			"  ;;;;;;;;'''';;;;'''';;;`    `;;;;;;;;'''';;; ;;,.    ;;;   .;;;;;;;.`;;;;,  `;;;;;;  ;;`;;     ;;;    ;;;`    ` \n"
			"       [[      [[cccc '[==/[[[[,    [[     [[[ [[[[, ,[[[[, ,[[     \[[,[[[[[. '[[[[[ ,[[ '[[,   [[[    '[==/[[[[,\n"
			"       $$      $$\"\"\"\"   '''    $    $$     $$$ $$$$$$$$\"$$$ $$$,     $$$$$$ \"Y$c$$$$$c$$$cc$$$c  $$'      '''    $\n"
			"       88,     888oo,__88b    dP    88,    888 888 Y88\" 888o\"888,_ _,88P888    Y88888 888   888,o88oo,.__88b    dP\n"
			"       MMM     \"\"\"\"YUMMM\"YMmMY\"     MMM    MMM MMM  M'  \"MMM  \"YMMMMMP\" MMM     YMMMM YMM   \"\"` \"\"\"\"YUMMM \"YMmMY\" \n";
	cout << TestimonialsLogo << endl;
}//end - TestimonialsHeader

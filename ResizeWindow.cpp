#include <Windows.h>
using namespace std;

//This function will resize a console window to preset dimensions
void ResizeWindow()
{
	//Set mode to ensure window does not exceed buffer size
	system("mode 118,100");

	//New dimensions for window in 8x12 pixel chars
	SMALL_RECT WinRect = {0, 0, 118, 100};
	SMALL_RECT* WinSize = &WinRect;

	//Set new size for window
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

}//end - ResizeWindow

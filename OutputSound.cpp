#include <windows.h>
using namespace std;

//Plays sound for the user to enjoy!
void OutputSound()
{
			Beep(329,100);
			Beep(493,300);
			Beep(698,300);
			Beep(659,600);

			Beep(392,250);
			Beep(440,200);
			Beep(587,300);

			Beep(392,250);
			Beep(440,200);
			Beep(587,300);

			Beep(783,300); //G^
			Beep(698,300); //F^
			Beep(659,600); //E^

}//end - OutputSound

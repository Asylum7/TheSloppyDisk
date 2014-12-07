#include "Earth.h"

Earth::Earth()
:Robot("Earth Bot", "00000000000", 45555.99, false, false)
{
	fourXfour = false;
	superCharged = false;
}

Earth::~Earth()
{

}
void Earth::Reset(string num)
{
	setReset(true);
	setNum(num);
	setPrice(45555.99);
	resetiOS();
	resetAndroid();
	fourXfour = false;
	superCharged = false;

}
void Earth::setFour(bool setFour)
{
	if(setFour)
	{
		if(fourXfour)
		{
			cout << "\nThis Earth Bot already has a 4x4 upgrade\n";
		}
		else
		{
			fourXfour = setFour;
			setPrice(getPrice() + 500.99);
			cout << "\nPrucahsed 4x4 capability ($500.99)\n";
		}
	}
	else if(!setFour && !getReset())
	{
		if(fourXfour)
		{
			fourXfour = setFour;
			setPrice(getPrice() - 500.99);
			cout << "\nRemoved 4x4 capability (-$500.99)\n";

		}
		else
		{
			cout << "\nThis Earth Bot does not have a 4x4 upgrade\n";
		}
	}
}
void Earth::setSC(bool setSC)
{
	if(setSC)
	{
		if(superCharged)
		{
			cout << "\nThis Earth Bot already has a super charge upgrade\n";
		}
		else
		{
			superCharged = setSC;
			setPrice(getPrice() + 700.99);
			cout << "\nPurchased super-charged engine ($700.99)\n";
		}
	}
	else if(!setSC && !getReset())
	{
		if(superCharged)
		{
			superCharged = setSC;
			setPrice(getPrice() - 700.99);
			cout << "\nRemoved super charged engine (-$500.99)\n";
		}
		else
		{
			cout << "\nThis Earth Bot does not have a super charged engine\n";
		}
	}
}

bool Earth::getFour() const
{
	return fourXfour;
}
bool Earth::getSC() const
{
	return superCharged;
}
void Earth::Display(ostream &file)
{
	Robot::Display(file);
	DisplayUpgrades(file);
}
void Earth::DisplayUpgrades(ostream &file)
{
	Robot::DisplayUpgrades(file);
	if(fourXfour)
	{
		file << "4x4 drive train\n";
	}
	if(superCharged)
	{
		file << "Super Charged engine\n";
	}
	if(!getiOS() && !getAndroid() && !fourXfour && !superCharged)
	{
		file << "None\n";
	}
}


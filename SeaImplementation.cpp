#include "Sea.h"

Sea::Sea()
:Robot("Sea-Bot", "00000000000", 105555.99, false, false )
{
	sonar = false;
	subMarine = false;
}
Sea::~Sea()
{

}
void Sea::Reset(string num)
{
	setReset(true);
	setNum(num);
	setPrice(105555.99);
	resetiOS();
	resetAndroid();
	subMarine = false;
	sonar = false;
}
void Sea::setSonar(bool sonarSet)
{
	if(sonarSet)
	{
		if(sonar)
		{
			cout << "\nThis Earth Bot already has a sonar upgrade\n";
		}
		else
		{
			sonar = sonarSet;
			setPrice(getPrice() + 1200.99);
			cout << "\nPrucahsed sonar ($1200.99)\n";
		}
	}
	else if(!sonarSet && !getReset())
	{
		if(sonar)
		{
			sonar = sonarSet;
			setPrice(getPrice() - 1200.99);
			cout << "\nRemoved soanr (-$1200.99)\n";

		}
		else
		{
			cout << "\nThis Sea Bot does not have sonar\n";
		}
	}
}
void Sea::setSub(bool setSub)
{
	if(setSub)
	{
		if(subMarine)
		{
			cout << "\nThis Earth Bot already has submarine capabilities\n";
		}
		else
		{
			subMarine = setSub;
			setPrice(getPrice() + 1700.99);
			cout << "\nPurchased submarine capability ($1700.99)\n";
		}
	}
	else if(!setSub && !getReset())
	{
		if(subMarine)
		{
			subMarine = setSub;
			setPrice(getPrice() - 1700.99);
			cout << "\nRemoved submarine capabilities\n";
		}
		else
		{
			cout << "\nThis Sea Bot does not have submarine capabilities\n";
		}
	}
}
bool Sea::getSonar()
{
	return sonar;
}
bool Sea::getSub()
{
	return subMarine;
}
void Sea::Display(ostream &file)
{
	Robot::Display(file);
	DisplayUpgrades(file);
}
void Sea::DisplayUpgrades(ostream &file)
{
	Robot::DisplayUpgrades(file);
	if(sonar)
	{
		cout << right;
		file <<"Sonar\n";
	}
	if(subMarine)
	{
		file << right;
		file << "Submarine capability\n";
	}
	if(!getiOS() && !getAndroid() && !sonar && !subMarine)
	{
		file << "None\n";
	}
}

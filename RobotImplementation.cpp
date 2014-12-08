#include "Robot.h"

Robot::Robot()
{
	name = " ";
	modelNumber = " ";
	price = 0.0;
	iOS = false;
	android = false;
	reset = false;
}
Robot::Robot(string setName,
			 string setNum,
			 double setPrice,
		     bool setiOS,
			 bool setAndroid)
{
	name = setName;
	modelNumber = setNum;
	price = setPrice;
	iOS = setiOS;
	android = setAndroid;
	reset = false;
}
Robot::~Robot()
{

}
void Robot::setName(string setName)
{
	name = setName;
}
void Robot::setNum(string setNum)
{
	modelNumber = setNum;
}
void Robot::setPrice(double setPrice)
{
	price = setPrice;
}
void Robot::resetiOS()
{
	iOS = false;
}
void Robot::resetAndroid()
{
	android = false;
}
void Robot::setiOS(bool setiOS)
{
	if(setiOS)
	{
		if(iOS)
		{
			cout << "\nThis bot already has iOS compatibility\n";
		}
		else if(!iOS)
		{
			iOS = setiOS;
			price += 1999.99;
			cout << "\nPurchased iOS compatible robot controller ($1999.99)\n";

		}
	}
	else if(!setiOS && !getReset())
	{
		if(iOS)
		{
			iOS = setiOS;
			price -= 1999.99;
			cout << "\nRemoved iOS capabilities\n";
		}
		else if(!iOS && !reset)
		{
			cout << "\nThis Bot does not have iOS compatibilities\n";
		}
	}

}
void Robot::setAndroid(bool setA)
{
	if(setA)
	{
		if(android)
		{
			cout << "\nThis bot already has Android compatiblity\n";
		}
		else if(!android)
		{
			android = setA;
			price += 1999.99;
			cout << "\nPurchased Android compatible robot controller ($1999.99)\n";

		}
	}
	else if(!setA && !getReset())
	{
		if(android)
		{
			android = setA;
			price -= 1999.99;
			cout << "\nRemoved Android capabilities\n";
		}
		else if(!android && !reset)
		{
			cout << "\nThis Bot does not have Android compatibilities\n";
		}
	}
}
void Robot::setReset(bool setReset)
{
	reset = setReset;
}

string Robot::getName() const
{
	return name;
}
string Robot::getNum() const
{
	return modelNumber;
}
double Robot::getPrice() const
{
	return price;
}
bool Robot::getiOS() const
{
	return iOS;
}
bool Robot::getAndroid() const
{
	return android;
}
bool Robot::getReset() const
{
	return reset;
}
void Robot::Display(ostream &file)
{
	file << left;
	file << setw(17) << "MODEL NAME: "   << name << endl;
	file << setw(17) << "MODEL NUMBER: " << modelNumber << endl;
	file << setw(17) << "PRICE: "        << setprecision(2) << fixed << "$"
		 << price << endl;
}
void Robot::DisplayUpgrades(ostream &file)
{
	file << left;
	file << setw(17) << "\nUPGRADES\n"
						"--------\n";

	if(iOS || android)
	{
		if(iOS && android)
		{
			file << "iPad and Android compatibility\n";
		}

		else if(iOS && !android)
		{
			file << "iOS compatibility\n";
		}
		else if(!iOS && android)
		{
			file << "Android compatibility\n";
		}

	}
}
void Robot::DisplayToCart(ostream &file)
{

	file << left << setw(15) << name << setw(15) << modelNumber << "$" << setw(15)
		 <<price;
	DisplayUpgrades(file);
}

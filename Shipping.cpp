#include "header.h"

double Shipping()
{
	cin.ignore();
	double shippingOption;
	int response;
	cout << "\nSHIPPING OPTIONS\n"
			"****************************************************************\n"
			"1.    USPS First Class Mail  (3-7 days        no additional cost\n"
			"2.    UPS Ground             (2-4 days)       + $10.99\n"
			"3.    UPS Next Day Air       (1 business day) + $50.99\n\n"
			"Selection: ";
	response = GetValidInt(3,1);
	if(response == 2)
	{
		shippingOption = 10.99;
	}
	else if(response == 3)
	{
		shippingOption = 50.99;
	}
	system("CLS");
	return shippingOption;
}

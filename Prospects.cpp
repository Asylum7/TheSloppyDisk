#include "Prospects.h"

//creating an account will generate a queue of account names and passwords
Prospects::Prospects(string nName, string nCompany,
				     string nEmail, int nZip,
				     bool broRec)
: name(nName), company(nCompany), email(nEmail), zip(nZip), brochureSent(broRec)
{ }//END - Default Constructor

//default destructor
Prospects::~Prospects(){}

//MUTATORS/////////////////////////////////////////////////////////////////////
void Prospects::SendBrochure()
{	brochureSent = true;	}

//ACCESSORS////////////////////////////////////////////////////////////////////

string Prospects::GetName()
{	return name;			}

string Prospects::GetCompany()
{	return company;			}

string Prospects::GetEmail()
{	return email;			}

int    Prospects::GetZip()
{	return zip;				}

bool   Prospects::GetBrocSent()
{	return brochureSent;	}

void Prospects::Print()
{

		cout << name 	 << endl;
		cout << company  << endl;
		cout << email 	 << endl;
		cout << zip 	 << endl;
		cout << (brochureSent ? "Brochure Sent" : "Brochure Not Sent")
			 << endl;

}//END - Print

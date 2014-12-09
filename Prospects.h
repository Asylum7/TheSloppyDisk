#ifndef PROSPECTS_H_
#define PROSPECTS_H_

#include "header.h"
using namespace std;

class Prospects
{
public:
	//default constructor, overloaded to accept values(has set defaults)
	Prospects(string nName = " ", string nCompany = " ",
			  string nEmail = " ", int nZip = 12345,
			  bool broRec = false);
	virtual ~Prospects();

//MUTATORS/////////////////////////////////////////////////////////////////////
	void  SendBrochure();

//ACCESSORS////////////////////////////////////////////////////////////////////
	string GetName();
	string GetCompany();
	string GetEmail();
	int    GetZip();
	bool   GetBrocSent();

	void Print();
	string email;

private:
	string name;
	string company;

	int    zip;
	bool   brochureSent;
};

#endif /* PROSPECTS_H_ */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


struct Person
{
	string name;
	string address;
	string address2;
	string zip;
	string interest;
	string rating;
	Person* next;
};

void Print (Person *personPtr, fstream &file);



#endif /* HEADER_H_ */

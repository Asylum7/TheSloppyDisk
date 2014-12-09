#include "ProspectTemplateHeader.h"

void InfoRequest(Queue<Prospects>prospectList)
{
	string nName;
	string companyName;
	string email;
	int    nZip;

	bool validProspect = false;

	//catch classes
	class invalidNameLength{};
	class invalidCompanyLength{};
	class invalidEmail{};
	class invalidZip{};
	class notIntInput{};

	do
	{
		try
		{
			cout << "Please enter your name: ";
			getline(cin, nName);
			//error checking for valid name length.
			if(nName.length() < 4 || nName.length() > 25)
				throw invalidNameLength();

			//input company name from user
			cout << "Please enter in your company name: ";
			getline(cin, companyName);

			if(companyName.length() < 4 || companyName.length() > 20)
				throw invalidCompanyLength();

			cout << "Please enter your email: ";
			getline(cin, email);
			if(email.length() < 8 || email.length() > 30)
				throw invalidEmail();

			//input zip from user
			cout << "Please enter in your zip code: ";
			cin >> nZip;
			if(!(cin >> nZip))
				throw notIntInput();

			if(nZip < 0 || nZip > 99999)
				throw invalidZip();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			validProspect = true;

		}//END - try

		catch(invalidNameLength)
		{
			cout << "::ATTENTION:: Name must be 4-25 characters, "
					 "please try again\n";
		}

		catch(invalidCompanyLength)
		{
			cout << "::ATTENTION:: Company Name must be 4-20 characters, "
					 "please try again\n";
		}

		catch(invalidEmail)
		{
			cout << "::ATTENTION:: Please enter a valid Email, must be "
					"8-30 characters.\n";
		}

		catch(notIntInput)
		{
			cout << "::ATTENTION:: Invalid zip, please enter "
					"a NUMBER from 1-99999.\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		catch(invalidZip)
		{

			cout << "::ATTENTION:: Invalid zip, please enter "
					"a number from 1-99999.\n";
		}
	}while(!validProspect);

	//creating new Prospects object with the provided information.
	Prospects newProspect(nName, companyName, email, nZip);

	cout << "\nWe've received your request. Expect an email within "
			"24 hours for you printable brochure!\n\n";

	prospectList.Enqueue(newProspect);
}

void BuildList(Queue<Prospects>prospectList)
{
	string name;
	string company;
	string email;
	int    zip = 0;

	ifstream inFile;
	inFile.open("prospects.txt");

	while(inFile)
	{
		//taking in user information
		getline(inFile, name);
		getline(inFile, company);
		getline(inFile, email);
		inFile >> zip;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

		Prospects newProspect(name, company, email, zip);

		prospectList.Enqueue(newProspect);

		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	}//END - while(inFile)

	//closing the input file
	inFile.close();
}


void SaveProspectList(Queue<Prospects>prospectList)
{
	ofstream outFile;
	Prospects writeObject;
	int size;

	size = prospectList.Size();


	//removing the old file
	remove("prospects.txt");

	//creating new text of the same name as the input file
	outFile.open("prospects.txt");

	for(int i = 0; i < (size - 1); i++)
	{
		writeObject = prospectList.Dequeue();
		outFile << writeObject.GetName() 	 << endl;
		outFile << writeObject.GetCompany()	 << endl;
		outFile << writeObject.GetEmail()	 << endl;
		outFile << writeObject.GetZip() 	 << endl;
		outFile << writeObject.GetBrocSent() << endl;

		if(i != size - 1)outFile << endl;
	}

	outFile.close();
}//END - CloseProspects
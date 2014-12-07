#ifndef AIR_H_
#define AIR_H_
#include "Robot.h"

class Air:public Robot
{
	public:
			 Air();
			 virtual ~Air();
			 void Reset(string num);
			 void setAlt(bool setAlt);
			 void setAuto(bool setAuto);
			 bool getAlt();
			 bool getAuto();
			 virtual void Display(ostream &file);
			 virtual void DisplayUpgrades(ostream &file);
	private:
			 bool highAltitude;
			 bool autoPilot;

};
void CustomizeAir(int response, Air &airBot);

#endif /* AIR_H_ */

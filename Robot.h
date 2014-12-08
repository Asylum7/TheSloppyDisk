#ifndef ROBOT_H_
#define ROBOT_H_
#include "header.h"

class Robot
{
	public:
			Robot();
			virtual ~Robot();
			Robot(string setName,
				  string setNum,
				  double setPrice,
				  bool setIOS,
				  bool setAndroid);
			void setName(string setName);
			void setNum(string setNum);
			void setPrice(double setPrice);
			void setiOS(bool setiOS);
			void setAndroid(bool setA);
			void resetiOS();
			void resetAndroid();
			void setReset(bool setReset);
			string getName() const;
			string getNum() const;
			double getPrice() const;
			bool getiOS() const;
			bool getAndroid() const;
			bool getReset() const;
			virtual void Display(ostream &file);
			virtual void DisplayUpgrades(ostream &file);
			virtual void DisplayToCart(ostream &file);
	private:
			string name;
			string modelNumber;
			double price;
			bool iOS;
			bool android;
			bool reset;

};
#endif /* ROBOT_H_ */

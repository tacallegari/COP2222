#ifndef CRUISE_H
#define CRUISE_H

#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

//Child class of Ship
class CruiseShip : public Ship
{
private:
	//Memember
	int maxPeople;
public:
	//Constructor 1
	CruiseShip() : Ship() {
		maxPeople = 0;
	}
	//Constructor 2
	CruiseShip(string s, string y, int mp) : Ship(s, y)  {
		maxPeople = mp;
	}
	//Getter 
	int getMaxPeople();
	//Setter
	void setMaxPeople(int m);
	//Override print function
	void print();
};

#endif


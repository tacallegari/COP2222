#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include <iostream>
#include "Ship.h"
using namespace std;

//Child class of Ship
class CargoShip : public Ship
{
private:
	//Memeber
	int maxTons;
public:
	//Constructor 1
	CargoShip() : Ship() {
		maxTons = 0;
	}
	//Constructor 2
	CargoShip(string s, string y, int mt) : Ship(s, y) {
		maxTons = mt;
	}
	//Getter
	int getMaxCargo();
	//Setter
	void setMaxCargo(int m);

	//Override print function
	void print();
};

#endif
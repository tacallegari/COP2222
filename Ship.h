#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
using namespace std;

class Ship
{
protected:
	//Class memembers
	string shipName;
	string yearMade;
public:
	//Constructor 1
	Ship() {
		shipName = "null";
		yearMade = "0";
	}
	//Constructor 2
	Ship(string s, string y) {
		shipName = s;
		yearMade = y;
	}
	//Getters
	string getShipName();

	string getYearMade();
	
	//Setters
	void setShipName(string s);
	void setYearMade(string y);
	
	//Print function
	virtual void print() {
		cout << "\nShip Name: " << shipName
		<< "\nYear Made: " << yearMade << endl;
	}
};

#endif // !SHIP_H

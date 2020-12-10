#include "Ship.h"

//Getters
string Ship :: getShipName() {
	return shipName;
}
string Ship :: getYearMade() {
	return yearMade;
}
//Setters
void Ship :: setShipName(string s) {
	shipName = s;
}
void Ship::setYearMade(string y) {
	yearMade = y;
}


#include "CruiseShip.h"

//Getter
int CruiseShip::getMaxPeople() {
	return maxPeople;
}
//Setter
void CruiseShip::setMaxPeople(int m) {
	maxPeople = m;
}
//Override print function
void CruiseShip::print() {
	cout << "\nShip Name: " << getShipName()
		<< "\nMax number of passengers: " << maxPeople << endl;
}

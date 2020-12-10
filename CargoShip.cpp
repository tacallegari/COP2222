#include "CargoShip.h"

//Getter
int CargoShip :: getMaxCargo() {
	return maxTons;
}
//Setter
void CargoShip :: setMaxCargo(int m) {
	maxTons = m;
}
//Override print function
void CargoShip :: print() {
	cout << "\nShip Name: " << getShipName()
		<< "\nCargo Capacity: " << maxTons << " tons." << endl;
}
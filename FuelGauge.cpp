#include "FuelGauge.h"
#include <iostream>
using namespace std;

//Constructor
FuelGauge::FuelGauge() {
	fuel = 0;
}

//Getter
int FuelGauge::getFuel() {
	reportFuel();
	return fuel;
}

//Adds fuel until tank reaches max
void FuelGauge::addFuel() {
	int max = 15;
	if (fuel < max) {
		fuel++;
	}
	else if (fuel == max) {
		cout << "\nTank is full." << endl;
	}
}

//Burns fuel unless tank is empty
void FuelGauge::burnFuel() {
	if (fuel >= 1) {
		fuel--;
	}
	else if (fuel == 0) {
		cout << "\nTank is empty." << endl;
	}
}

//Display current state of fuel tank
void FuelGauge::reportFuel() {
	cout << "Gas tank: " << fuel << " gallons." << endl;
}

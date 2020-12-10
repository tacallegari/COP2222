#include "Odometer.h"
#include <iostream>
using namespace std;

//Constructor
Odometer::Odometer() {
	mileage = 0;
}

//Getter
int Odometer::getMileage() {
	reportMileage();
	return mileage;
}

//Adds a mile unless odometer has reached max
void Odometer::addMileage() {
	int max = 999999;
	if (mileage < max) {
		mileage++;
	}
	else {
		//Resets odometer
		mileage = 0;
	}
}

//Display current state of odometer
void Odometer::reportMileage() {
	cout << "Mileage: " << mileage << endl;
}



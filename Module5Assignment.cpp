//Tahlia Callegari
//2428774
//COP2222 Fall 2020

#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"
using namespace std;

int main()
{
    //Instances of classes
    FuelGauge fuelGauge;
    Odometer odometer;

    //Declare vars
    char choice;
    string tripName;
    int tripMileage, fuel, maxFuel = 15, counter = 0, fuelEconomy = 24;

    //Opening message
    cout << "Welcome to car simulator."
        << "\nWhere are we driving to? ";
    cin >> tripName; //Get trip name
    cout << "How many miles to " << tripName << " ? ";
    cin >> tripMileage; //Get trip mileage
    cin.ignore();

    //Ask user of current fuel state
    cout << "Do you have gas in the car? (y/n) ";
    cin >> choice;

    //Switch take's in user input in order to set fuel
    //in object fuelGauge
    switch (choice) {
    case 'y':
    case 'Y':
        cout << "Enter in gallons (max 15): ";
        cin >> fuel;
        cin.ignore();
        for (int i = 0; i < fuel; i++) {
            fuelGauge.addFuel();
        }
        break;
    case 'n':
    case 'N':
        cout << "Filling up at the gas station." << endl;
        for (int i = 0; i <= maxFuel; i++) {
            fuelGauge.addFuel();
        }
        break;
    }

    //Creates pause in system
    {
    }
    {
    }

    //Loops until car reaches destination 
    while (counter != tripMileage) {
        //If car has fuel, car can drive
        if (fuelGauge.getFuel() != 0) {
            odometer.addMileage(); //increases mileage
             //counter counts miles traveled for current trip
            counter++;
            //Decreases fuel every 24 miles
            if (odometer.getMileage() % fuelEconomy == 0) {
                fuelGauge.burnFuel();
            }
        }
        //If tank is empty, fill it up
        else if (fuelGauge.getFuel() == 0) {
            cout << "Oops! Ran out of gas."
                << "\nTime to fill up." << endl;
            for (int i = 0; i <= maxFuel; i++) {
                fuelGauge.addFuel();
            }
        }
    }

    //Triggers output once destination was reached
    if (counter == tripMileage) {
        cout << "\nYou have arrived at " << tripName << endl;
        fuelGauge.reportFuel();
        odometer.reportMileage();
    }

    return 0;
}
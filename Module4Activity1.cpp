// Tahlia Callegari
// 2428774
//COP 2222 Fall 2020

#include <iostream>
#include "Car.h"
#include <string>
using namespace std;

// Declare function(s)
void displayChoice();

int main()
{
    //Instance of Car object
    Car car1 = Car(2015, "Toyota Rav 4");

    //Declare variables
    int speed = car1.getSpeed();
    char choice;

    //Display Car object attributes by calling on function
    //in class
    car1.displayCar();
    
    //Display choices
    displayChoice();

    //Do-while loop with a nested switch catches user input
    //to either accelerate or break the car
    do {
        cin >> choice; //User input

        switch (choice) {

        //Accelerates car
        case 'a':
            speed += car1.accelerate();
            cout << "Speed is now " << speed << " mph." << endl;
            break;
        //Breaks car
        case 'b':
            speed += car1.brake();
            cout << "Speed is now " << speed << " mph." << endl;
            break;
        //Exists out of loop
        case 'e':
            cout << "Your final speed is " << speed << " mph." << endl;

        }
    } while (choice != 'e');

    return 0;
}

//Function displays choice menu for user
void displayChoice() {
    cout <<"\nCar is on and at current default speed of 0.\n"
        << "To accelerate, enter 'a'.\nTo brake, enter 'b'.\n"
        << "To escape, enter 'e'.\n" << endl;
}



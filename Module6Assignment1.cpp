// Tahlia Callegari
// 2428774
//COP2222 Fall 2020

#include "CruiseShip.h"
#include "CargoShip.h"
#include "Ship.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //Declare constant 
    const int SIZE = 3;

    //Create ships array of Ship pointers and
    //initialized each element with an object
    //of each class
    Ship* ships[SIZE] = {
         new Ship("Nuestra Senora de Atocha", "1621"),
         new CargoShip("Esmeralda", "1957", 26947),
         new CruiseShip("Achille Lauro", "1947", 869) };

    //Displays each ship
    for (int i = 0; i < SIZE; i++) {
        ships[i]->print(); //Overrides print() function each element
    }

    return 0;
}



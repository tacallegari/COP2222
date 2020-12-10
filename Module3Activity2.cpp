//Tahlia Callegari 
//2428774
//COP2222 Fall 2020

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Const global vars
const int QUARTERS = 4, NAME_SIZE = 6;

//Create structure QuarterSales
struct QuarterSales {
    char division[NAME_SIZE];
    int  quarter,
        sales;
};

//Declare functions
int calculateAvg(int total, int size);
int calculateAvg(int total, int size);
void displayQuarterSales(int total, int qs1, int qs2, int qs3, int qs4);
void displayDivisonSales(int north, int south, int east, int west);
void findMax_Min(int qs1, int qs2, int qs3, int qs4);

//Declare global vars
fstream dataFile;

int main()
{
    //Const Variable
    const int SIZE = 16;

    //Declare variables
    char next;
    char north[NAME_SIZE] = "North", south[NAME_SIZE] = "South", east[NAME_SIZE] = "East", west[NAME_SIZE] = "West";
    int quarterSales1 = 0, quarterSales2 = 0, quarterSales3 = 0, quarterSales4 = 0, annualSales = 0;
    int northSales = 0, southSales = 0, eastSales = 0, westSales = 0;

    //Instance of Struct object
    QuarterSales data;

    //Enter file location


    //Open file
    dataFile.open("C://Users//Tahlia//source//repos//Module3Activity1//Module3Activity1//qs.txt", ios::in | ios::binary);

    //Checks to see if file will open
    if (!dataFile) {
        cout << "Error. Cannot open file.\n";
    }
    else {
        cout << "File opened successfully.\n";
    }

    //Read binary data from file and convert it
    dataFile.read(reinterpret_cast<char*>(&data), sizeof(data));

    //Loops untils it reaches end of file
    while (!dataFile.eof()) {

        //Display data
        cout << "Division: ";
        cout << data.division << endl;
        cout << "Quarter: ";
        cout << data.quarter << endl;
        cout << "Sales: $";
        cout << data.sales << endl;

        //Accumulates total annual sales
        annualSales += data.sales;

        //Loops through quarters and accumulates sales
        //to corresponding quarter
        if (data.quarter == 1) {
            quarterSales1 += data.sales;
        }
        else if (data.quarter == 2) {
            quarterSales2 += data.sales;
        }
        else if (data.quarter == 3) {
            quarterSales3 += data.sales;
        }
        else if (data.quarter == 4) {
            quarterSales4 += data.sales;
        }
        else {
            break;
        }

        //Compares char[] w/o case senstivity and
        //adds sales to corresponding division accumulator
        if (_stricmp(data.division, north)) {
            northSales += data.sales;
        }
        else if (_stricmp(data.division, south)) {
            southSales += data.sales;
        }
        if (_stricmp(data.division, east)) {
            eastSales += data.sales;
        }
        else if (_stricmp(data.division, west)) {
            westSales += data.sales;
        }
        else {
            break;
        }
        
        //User presses enter key to see next struct object
       cout << "\nPress Enter key to see the next record.\n";
       cin.get(next);

       //Convert and read next record
       dataFile.read(reinterpret_cast<char*>(&data), sizeof(data));
    }

    //Close file
    dataFile.close();
    cout << "\nEnd of file. Displaying sales stats." << endl;

    //Display all sales stats
    displayQuarterSales(annualSales, quarterSales1, quarterSales2, quarterSales3, quarterSales4);
    displayDivisonSales(northSales, southSales, eastSales, westSales);

    return 0;
}

//Function caculates averages
int calculateAvg(int total, int size){
    int avg = total / size;

    return avg;
}

//Function displays quarter sales
void displayQuarterSales(int total, int qs1, int qs2, int qs3, int qs4){
    cout << "\nTotal yearly corporate sales: $" << total << endl;
    cout << "Total Corporate sales for each Quarter."
        << "\nQuarter 1: $" << qs1
        << "\nQuarter 2: $" << qs2
        << "\nQuarter 3: $" << qs3
        << "\nQuarter 4: $" << qs4 << endl;
    findMax_Min(qs1, qs2, qs3, qs4); // Calls on function to find lowest and highest quarter sales
}

//Function displays division sales
void displayDivisonSales(int north, int south, int east, int west){
    cout << "\nTotal yearly sales for each division."
        << "\nNorth Division: $" << north
        << "\nSouth Division: $" << south
        << "\nEast Division: $" << east
        << "\nWest Division: $" << west << endl;        
    cout << "\nAverage quarterly sales for each Division."
        << "\nNorth Division: $" << calculateAvg(north, QUARTERS)
        << "\nSouth Division: $" << calculateAvg(south, QUARTERS)
        << "\nEast Division: $" << calculateAvg(east, QUARTERS)
        << "\nWest Division: $" << calculateAvg(west, QUARTERS) << endl;
}

//Function finds highest and lowest quarter sales
void findMax_Min(int qs1, int qs2, int qs3, int qs4) {
    int max = qs1, min = qs2;
    int maxQ = 1, minQ = 2;

    if (max < qs2) {
        max = qs2;
        maxQ = 2;
        min = qs1;
        minQ = 1;
    }
    if (max < qs3) {
        max = qs3;
        maxQ = 3;
    }
    else if (min > qs3) {
        min = qs3;
        minQ = 3;
    }
    if (max < qs4) {
        max = qs4;
        maxQ = 4;
    }
    else if (min > qs4) {
        min = qs4;
        minQ = 4;
    }

    //Displays results
    cout << "\nHighest quarter sales: Quarter " << maxQ << " with $" << max << endl;
    cout << "Lowest quarter sales: Quarter " << minQ << " with $" << min << endl;
}

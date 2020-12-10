// Tahlia Callegari
//2428774
//COP2222 Fall 2020

#include <iostream>
#include <fstream>
using namespace std;

//Const Variable
const int DIVISIONS = 4, NAME_SIZE = 6;

//Create structure QuarterSales
struct QuarterSales {
    char division[NAME_SIZE];
    int  quarter,
         sales;
};

//Declare functions
QuarterSales getData();
bool isSalesValid(int num);

//Global file object
fstream dataFile;

int main()
{


    //Declare variables
    QuarterSales Quarter1[DIVISIONS], Quarter2[DIVISIONS], Quarter3[DIVISIONS], Quarter4[DIVISIONS];
    int index;

    //Display Open file message
    cout << "Opening file...\nRecord is case sensitive."
        <<"\nDivision names are either: North/South/East/West."
        <<"\nPlease enter data for Quarter 1."
        << "\n===============================" << endl;
    
    //Open file
    dataFile.open("qs.txt", ios::out | ios::binary);
    
    //Adds four struct objects to Quarter1
    for (index = 0; index < 4; index++) {
        Quarter1[index] = getData();
    }

    //Quarter 2 ++
    cout << "\nPlease enter data for Quarter 2"
        << "\n===============================" << endl;
    for (index = 0; index < 4; index++) {
        Quarter2[index] = getData();
    }

    //Quarter 3 ++
    cout << "\nPlease enter data for Quarter 3"
        << "\n===============================" << endl;
    for (index = 0; index < 4; index++) {
        Quarter3[index] = getData();
    }

    //Quarter 4 ++
    cout << "\nPlease enter data for Quarter 4"
        << "\n===============================" << endl;
    for (index = 0; index < 4; index++) {
        Quarter4[index] = getData();
    }

    //Close file
    dataFile.close();
    cout << "\nFile closed.\n";

    return 0;
}

//Function creates temp struct to get input data
QuarterSales getData() {

    //Declare temp struct object
    QuarterSales temp;

    //Get division name & write to file
    cout << "\nDivision Name: ";
    cin.getline(temp.division, NAME_SIZE);

    //Get quarter & write to file
    cout << "Quarter: ";
    cin >> temp.quarter;

    //Validate quarter
    if (temp.quarter != 1 && temp.quarter != 2 && temp.quarter != 3 && temp.quarter != 4) {
        cout << "Invalid quarter. Please enter a 1, 2, 3, 4." << endl;
        cin >> temp.quarter;
    }
    cin.ignore();

    //Get sales data
    cout << "Sales: ";
    cin >> temp.sales;
    cin.ignore();

    //Validate sales input
    bool inputVal = isSalesValid(temp.sales);
    if (!inputVal) {
        cin >> temp.sales;
        cin.ignore();
    }
    
    //Write valid sales data to file
    //dataFile << temp.sales<< endl;

    dataFile.write(reinterpret_cast<char *>(&temp), sizeof(temp));

    //Return temp struct object
    return temp;

}

//Function validates sales input
bool isSalesValid(int num) {

    //Declare bool var
    bool isValid = false;

    //If statement validates input is greater than zero 
    //and that a negative number wasn't entered
    if (num > 0) {
        isValid = true;
    }
    else if ((num * -1) > 0) {
        isValid = false;
        cout << "Invalid entry data. Try again.\nSales: ";
    }

    //Return bool var
    return isValid;

}

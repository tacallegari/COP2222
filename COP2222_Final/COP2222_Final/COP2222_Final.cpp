// Tahlia Callegari
// 2428774
// COP2222 Fall 2020

/// This final project simulates a database of a small music streaming company. There is two classes:
/// Account and Favorites. Accounts hold account holder data such as their ID and name. Favorites holds
///  the account's top favorite songs.
/// Since its a small company, they can only hold 10 currently in a playlist.

#include "Favorites.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Declare file object
fstream dataFile;

//Declare functions
string getName();
int getNumOfSongs();
void displayFile(fstream& dataFile);

int main()
{
	//Declare vars
	int numOfAccounts, numOfSongs,counter = 0;
	string name, fileName = "data.txt", fileError = "Error cannot open file. Closing program.";

	//Exosition statement
	cout << "Welcome to ShareJams.";

	//Open file
	try {
		dataFile.open(fileName, ios::out);

		//If file fails to open throw exception
		if (!dataFile) {
			throw fileError;
		}
		else {
			cout << "\nOpening "<< fileName << " file..." << endl;
		}
	}
	//Catch exception 
	catch (string fileError) {
		cout << fileError;
		exit(0); //Ends program
	}

	//Ask user how many accounts they would like to insert into file
	cout << "How many accounts would you like to write into this file? ";
	cin >> numOfAccounts;

	//Loop creates class objects and writes them into the file
	while (counter != numOfAccounts) {
		name = getName(); //Get account name
		numOfSongs = getNumOfSongs(); //Get number of songs 

		//Create Favorites :: Account object
		Favorites account(name, numOfSongs);
		account.print(); //Display 

		//Add data to file
		dataFile << "\n" << account.getID() << endl;
		dataFile << account.getUserName() << endl;
		//Function writes struct objects into file
		account.writeIntoFile(dataFile); 
		
		//Add to counter
		counter++;
	}
	//Close file
	dataFile.close();
	cout << " " << endl;
	cout << "File is closed." << "\n" << endl;
	
	//Open file again to read & display
	try {
		dataFile.open(fileName, ios::in);

		//If file doesn't open throw exception
		if (!dataFile) {
			throw fileError;
		}
		else {
			cout << "\nOpening " << fileName << " file..." << endl;
			cout << " " << endl;
		}
	}
	//Catch expection
	catch (string fileError) {
		cout << fileError;
		exit(0); //Ends program
		}

	//Call on function to display all data in file
	displayFile(dataFile);

	//Close file
	dataFile.close();
	cout << "\nFile is closed." << "\n" <<endl;
	
	//End of program
	return 0;
}

//Function ask's user for name of account
string getName() {
	//Declare var
	string name, lastName;

	cout << "\nAccount holder's first name: ";
	cin >> name;

	cout << "Last name: ";
	cin >> lastName;

	name = name + " " + lastName;

	//Return var
	return name;
}
//Function ask's user for number of songs
int getNumOfSongs() {
	//Declare var
	int num;

	//Ask user for input
	cout << "Number of favorite songs: (Max 10) ";
	cin >> num;

	//Verify num is in range of 1-10
	if (num > 10 || num < 0) {
		cout << "Error. Please enter number between 1-10 (inclusive): ";
		cin >> num;
	}

	//Return var
	return num;
}
//Function displays data within file
void displayFile(fstream &dataFile) {
	//Declare string
	string line;

	//Loop through until end of file
	while (dataFile >> line) {
		cout << line << endl;
	}
}
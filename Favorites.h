#ifndef FAVORITES_H
#define FAVORITES_H

#include "Account.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Declare const int
const int SIZE = 10;

//Declare struct 
struct Song {
    string name,
        artist,
        genre;
};

class Favorites :
    public Account
{
private:
    //Declare vars
    Song songs[SIZE];
    int size;
public:
    //Constructor 1
    Favorites() : Account() {
        
        for (int i = 0; i < SIZE; i++) {
            songs[i].name = ' ';
            songs[i].artist = ' ';
            songs[i].genre = ' ';
        }
    }
    //Constructor 2
    Favorites(string name, int inputSize) : Account(name) {

        //Ask user for song data to create an array
        //of struct song objects
        cout << "\nPlease enter the following...";
        for (int i = 0; i < inputSize; i++) {
            songs[i].name = getSongName();

            songs[i].artist = getArtist();
            
            songs[i].genre = getGenre();

        }

        size = inputSize;
    }

    //Getter
    int getSize();
    string getSongName();
    string getArtist();
    string getGenre();


    //Function writes songs objects into pointer file
    void writeIntoFile(fstream &dataFile) {
        for (int i = 0; i < size; i++) {
            dataFile << songs[i].name << endl;
            dataFile << songs[i].artist << endl;
            dataFile << songs[i].genre << endl;
        }
    }

    //Display's class members
    void print();
};

#endif // !FAVORITES_H
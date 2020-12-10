#include "Favorites.h"

const int SIZE2 = 50;

#include <iostream>
using namespace std;


//Define getters
int Favorites::getSize() {
    return size;
}
string Favorites::getSongName() {
    //declare var
    string name = "";

    //Ask user for song name
    cout << "\nSong name: ";
    cin.ignore();
    getline(cin, name);

    return name;
}
string Favorites::getArtist() {
    //Declare var
    string artist =""; 

    //Ask user for artist name
    cout << "Artist name: ";
    getline(cin, artist);
    
    return artist;
}
string Favorites::getGenre() {
    //Declare var
    string genre = "";

    //Ask user for genre
    cout << "Genre: ";
    getline(cin, genre);

    return genre;
}

//Override print function to display members
//from Account & Favorites class
void Favorites::print() {
    cout << "\nAccount ID: " << getID()
        << "\nFavorites Songs: " << endl;;
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". \nName: " << songs[i].name
            << "\nArtist: " << songs[i].artist
            << "\nGenre: " << songs[i].genre << endl;
    }
}
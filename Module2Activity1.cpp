// Tahlia Callegari
//242877
//COP2222 Fall 2020

/* This program uses a structure to 
* store movie data & display it.*/

#include <iostream>
#include <string>
using namespace std;

//Declare structure
 struct MovieData {
     string title, 
         director;
     int yearReleased,
         time; //in minutues 
    };

 //Declare Function(s)
 void displayData(MovieData movie);

int main()
{
    //Create objects utilizing the structure
    MovieData movie1 = { "Howl's Moving Castle", "Hayao Miyazaki", 2004, 119};
    MovieData movie2;

    //Get movie data for second movie variable
    cout << "Enter movie title: ";
    getline(cin,movie2.title); //Add input to title
    cout << "Director: ";
    getline(cin, movie2.director); //Add input to director
    cout << "Year released: ";
    cin >>movie2.yearReleased; //Add input to yearReleased
    cout << "Time (minutues): ";
    cin >> movie2.time; //Add input to time

    //Call on function to display movie data
    displayData(movie1);
    displayData(movie2);

    return 0;
}
//Function to display movie data
void displayData(MovieData movie) {
    //Display data by calling on each member of stucture
    cout << "\nTitle: " << movie.title
        << "\nDirector: " << movie.director
        << "\nYear released: " << movie.yearReleased
        << "\nLength: " << movie.time << " minutes\n" << endl;
}
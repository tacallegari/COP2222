//Tahlia Callegari
//2428774
//COP2222 Fall 2020

/* This program is a modifcation of MOD2 ACT2.
The program will take in input and display movie data 
by utilizing a structure called Movie Data. Two additonal
members are being added as modification.*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Declare structure
struct MovieData {
    string title,
        director,
        yearReleased,
        time,//in minutues
        cost,
        revenue;
};

//Declare Function(s)
MovieData getData();
long int calculateProfit(MovieData movie);
bool isProfit(int netProfit);
void displayData(MovieData movie, int netProfit);

int main()
{
    cout << "Please enter movie data for two films." << endl;

    //Create objects utilizing the structure
    MovieData movie1, movie2;
    movie1 = getData();
    movie2 = getData();

    //Call on function to caculate profit
    int netProfit1 = calculateProfit(movie1), netProfit2 = calculateProfit(movie2);
    
    //Call on function to display movie data
    displayData(movie1, netProfit1);
    displayData(movie2, netProfit2);

    return 0;
}
MovieData getData() {
    //Temporary structure variable
    MovieData tempMovie;

    //Get movie data for second movie variable
    cout << "\nEnter movie title: ";
    getline(cin, tempMovie.title); //Add input to title
    cout << "Director: ";
    getline(cin, tempMovie.director); //Add input to director
    cout << "Year released: ";
    getline(cin, tempMovie.yearReleased); //Add input to yearReleased
    cout << "Time (minutes): ";
    getline(cin, tempMovie.time); //Add input to time
    cout << "Production cost: ";
    getline(cin, tempMovie.cost); //Add input to cost
    cout << "First-year Revenue: ";
    getline(cin, tempMovie.revenue);

    //Return temp variable
    return tempMovie;
}
long int calculateProfit(MovieData movie) {
    long int profit = stol(movie.revenue) - stol(movie.cost);
    return profit;
}
bool isProfit(int netProfit) {
    bool isProfit;

    if (netProfit < 0) {
        isProfit = false;
    }
    else {
        isProfit = true;
    }
    return isProfit;
}
//Function to display movie data
void displayData(MovieData movie, int netProfit) {

    bool profit = isProfit(netProfit);

    //Display data by calling on each member of stucture
    cout << "\nTitle: " << movie.title
        << "\nDirector: " << movie.director
        << "\nYear released: " << movie.yearReleased
        << "\nRunning time: " << movie.time << " minutes\n"
        << "First year's net ";

    if (!profit) {
        cout << "loss is $" << (netProfit*-1) << endl;
    }
    else {
        cout << "profit is $" << netProfit << endl;
    }
}
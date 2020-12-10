// Tahlia Callegari
// 2428774
// COP2222 Fall 2020

#include <iostream>
#include "TestScores.h"
using namespace std;

void validateSize(int size);
int getScore();

int main()
{
    //Costant Var
    const int SIZE = 101;

    //Declare vars
    int size, total = 0;
    int scores[SIZE];

    //Get user input for size var
    cout << "How many test scores are there? (Must be less than or equal to 100) ";
    cin >> size;

    //Call on function to validate
    validateSize(size); 

    //Call on function to add elements to scores[]
    for (int i = 0; i < size; i++) {
        scores[i] = getScore();
    }

    //Declare class object
    TestScores testScores(scores, size);
    
    //Set size
    testScores.setSize(size);

    //Try & Catch block
    try {
    //Display testScores
    testScores.print();
    //Calculate average
    testScores.calcAverage();
    }
    //Catch invalid score
    catch (TestScores::InvalidScore) {
        cout << "\nError: Invalid score. Must be greater than 0 and less than or equal to 100.";
    }

    //End program
    cout << "\nEnd of program.\n";

    return 0;
}

//Function validates size
void validateSize(int size) {
    if (size > 100 || size < 0) {
        cout << "Invalid input. Please try again: ";
        cin >> size;
    }
}

//Ask user input for score
int getScore() {
    int score;

    cout << "Enter test score: ";
    cin >> score;

    return score;
}
// Tahlia Callegari
// 2428774
// COP2222 Fall 2020

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

//Declare function
void wordCount(char array[], int size);

int main()
{

    //Declare constant variable
    const int SIZE = 127;

    //Declare char array variable
    char userInput[SIZE];

    //Get user input
    cout << "Please enter a string message: ";

    //Store input into array
    cin.getline(userInput, SIZE);

    //Call on wordCount function
    wordCount(userInput, SIZE);

    return 0;
}

//Function counts each word in char array[]
void wordCount(char array[], int size) {
    //Declare variables
    int count = 0;
    char space = ' ', null = '\0';

    //For statement filters through each char in array
    for (int i = 0; i < strlen(array); i++) {
        //If conditions are met, add to counter
        if ((array[i] != null && !i) || array[i] == space) {
            count++;
        }
    }

    //Display number of words
    cout << "\nNumber of words in string message: " << count << endl;
}

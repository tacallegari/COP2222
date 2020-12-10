#include "TestScores.h"
#include <iostream>
using namespace std;

//Constructor 2;
TestScores::TestScores(int array[], int s) {
	for (int i = 0; i < s; i++) {
		testScores[i] = array[i];
	}
}

//Setter;
void TestScores::setSize(int s) {
	size = s;
}

//Calculate average test score
void TestScores::calcAverage() {
	int average = 0;

	//Loop checks to see if there is an invalid score
	for (int i = 0; i < size; i++) {
		if (testScores[i] < 0 || testScores[i] > 100) {
			throw InvalidScore();
		}
		else {
			average += testScores[i];
		}
	}
	//Calculates average
	average = (average / size);

	//Prints out results
	cout << "\nAverage: " << average << endl;
}

//Displays test scores
void TestScores::print() {
	cout << "\nDisplaying " << size <<" Test Scores: ";
	for (int i = 0; i < size; i++) {
	cout << "\nTest score " << (i+1) << ": " << testScores[i];
	}
}
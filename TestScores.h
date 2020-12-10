#ifndef TESTSCORES_H
#define TESTSCORES_H

const int SIZE = 101;

class TestScores
{
private:
	//Declare private vars
	int testScores[SIZE];
	int size;
public:
	//Exception handler
	class InvalidScore {};

	//Constructors
	TestScores(); //Default
	TestScores(int array[], int s);
	
	//Functions
	void setSize(int s); //Set size
	void calcAverage(); //Calculates avg score
	void print(); //Displays test scores

};

#endif


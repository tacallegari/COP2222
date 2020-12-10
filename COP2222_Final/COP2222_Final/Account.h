#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	//Members
	string userName;
	int ID;
public:
	//Constructor 1
	Account() {
		userName = " ";
		ID = 000;
	}
	//Constructor 2
	Account(string name) {
		userName = name;
		setID();
	}

	//Declare getters
	string getUserName();
	int getID();

	//Declare setter
	void setID();

	//Virtually display Account members
	void virtual print() {
		cout << "\nName: " << userName;
		cout << "\nID: " << ID;
	}

};

#endif 
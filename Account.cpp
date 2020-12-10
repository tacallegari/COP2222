#include "Account.h"

// Define Getters
string Account::getUserName() {
	return userName;
}
int Account::getID() {
	return ID;
}

// Define Setter
void Account::setID() {
	//Each ID will be a random number from 1-99
	ID = rand() % 100;
}
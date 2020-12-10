// Tahlia Callegari
// 2428774
// COP2222 Fall 2020

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Declare functions
string getEmail();
string getPassword();
bool verifyPassword(string input);
bool verifyEmail(string email);

int main()
{
    //Display opening message
    cout << "Welcome to *blank* software! "
    << "Before we finish installing the software, you will need to create an account.\n";

    //Declare variables and call on functions
    string username = getEmail();
    string password = getPassword();

    //Display end message
    cout << "\nAccount created. Install is complete.";
    
    return 0;
}
//Function ask's user for email 
string getEmail() {
    //Declare variable
    string email;

    //Ask user for input
    cout << "\nPlease enter a valid email address."
        << " This will be your username."
        << "\nEmail: ";
    //Store input into string variable
    cin >> email; 

    //Check to see if email is valid
    bool isValid = verifyEmail(email);

    //If email isn't valid, ask user for input again
    if (!isValid) {
        cout << "INVALID Email. Please enter again: ";
        //Re-assign input into string variable
        cin >> email;
    }
    //Return valid email 
    return email;
}
//Function ask user for password
string getPassword() {
    //Declare variable
    string input;

    //Ask user for input
    cout << "\nPlease create a password that is at least six characters long."
    << "\nIt must contain one uppercase, one lowercase, and one number. " << endl;
    cout << "Password: ";
    //Store input into string variable
    cin >> input;
    
    //Check to see if password meets requirements
    bool meetsRequirement = verifyPassword(input);

    //If password is invalid, ask user to re-enter input
    if (!meetsRequirement) {
        cout << "\nPlease enter a new password: ";
        //Re-assign input into string variable
        cin >> input;
    }
    //Return input
    return input;
}
//Function verfies email address
bool verifyEmail(string email) {
    //Declare variables
    bool isValid = false;
    char atSymbol = '@';

    //For loop filters through every character in string
    for (int i = 0; i < email.length(); i++) {
        //If email has atSymbol then email is "considered" valid
        if (email[i] == atSymbol) {
            isValid = true;
        }
    }
    //Return bool
    return isValid;
}
//Function verifies password
bool verifyPassword(string input){
    //Declare variables
    bool isValid = true;
    int upper = 0, lower = 0, digit = 0;
    string errorMessage = "INVALID password. Missing the following requirements:";
    
    //If statement verfies length
    if (input.length() < 6) {
        errorMessage += "\nMininum of 6 characters";
        isValid = false;
    }

    //For loop filters through every character in string
    for (int i = 0; i < input.length(); i++) {

        //Counts upper case chars in string
        if (isupper(input[i])) {
            upper++;
        }
        //Counts lower case chars in string
        else if (islower(input[i])) {
            lower++;
        }
        //Counts digits in string
        else if (isdigit(input[i])) {
            digit++;
        }
    }
    //If false, statements will add missing conditions to string errorMessage
    //and changes isValid to false
    if (upper == 0) {
       errorMessage += "\n1 upper case char";
       isValid = false;
    }
    if (lower == 0) {
        errorMessage += "\n1 lower case char";
        isValid = false;
    }
    if (digit == 0) {
        errorMessage+="\n1 digit";
        isValid = false;
    }

    //If bool is false, print out error message
    if (!isValid) {
        cout << errorMessage;
    }

    //Return bool
    return isValid;
    
}




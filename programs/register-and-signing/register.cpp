// # register.cpp #
#include <iostream> // main library
#include <ctype.h> // toupper() function
#include <string.h> // empty() function
#include <unistd.h> // sleep() function
#include <fstream> // ifstream and ifile

#include "signVariables.hpp"
#include "signFunctions.hpp"

int main() {

// Checks for information, if it does exist pre-loads it before the actual program starts
if ( (!(ifile.fail())) ) {
	loadingData();
	sleep(1);
}

std::cout << "# Welcome, would you like to sign up or sign in? #\n";
std::cout << "\n";
std::cout << "# <1 = Sign up / 2 = Sign in>\n";
std::cout << "\n";
std::cout << "-";
std::cin >> answer;	

// If user is sign up and both strings are empty
if ( (answer == '1') && (actName.empty() && actPassword.empty()) ) {
	signUp();	
}

// If user is trying to sign up and both strings are full
else if ( (answer == '1') && (!(actName.empty())) && (!(actPassword.empty())) ) {
	failSignUp();
}

// If user is trying to sign in and both strings are full
else if ( (answer == '2') && (!(actName.empty()) && (!(actPassword.empty()))) ) {
	signIn();
}

// If user is trying to sign in and both strings are empty
// This will re direct you to failSign in where it checks if userData.txt exists, if not signs you up
	else if ( (answer == '2') && (actName.empty()) && (actPassword.empty()) ) {  	
	failSignIn();
}

} // End of main

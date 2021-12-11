// #signFunctions.hpp #
#include <iostream> // main library
#include <ctype.h> // toupper() function
#include <string.h> // empty() function
#include <unistd.h> // sleep() function
#include <fstream> // saving data in text files thingy
#include <vector> // vectors duh
#include <algorithm> // uhhhhh std::transform??

std::ifstream ifile("userData.txt");

// ---------------- DEFINITION OF SIGN FUNCTIONS ---------------- //

// SIGN IN FUNCTION DEFINITION
void signIn() {
	std::cout << "\n";
	signIn_text();
	loadingData();
	if ((curName == actName) && (curPassword == actPassword)) {
		// This "transforms" actName to mayus so it shows properly to the header?????
		// Genuinely i don't know how this works
		std::transform(actName.begin(), actName.end(), actName.begin(), ::toupper);
		
		std::cout << "\n";
		std::cout << " --- WELCOME " << actName << " TO THE PROGRAM --- \n";
		std::cout << "\n";
		sleep(3);
		system("pause");
	} // End of if statement

	else {
		std::cout << "\n",
		std::cout << "# It seems like the information you inputted is wrong to your previous registering, try again\n";
		sleep(2);
		system("cls");
		signIn();
	} // End of else statement
} // End of the signIn() function

// SIGN UP FUNCTION DEFINITION
void signUp() {
	std::cout << "\n";
	signUp_text();
	std::cout << "\n"; 
	
	std::cout << "# So then, your name is " << actName << " And your password is " << actPassword << ", " << "Would you like to sign in now?\n";
	std::cout << "< Y = Yes / N = (Will delete your data and drive you to sign Up again)\n";
	std::cout << "\n";
	std::cout << "-";
	std::cin >> answer;
	
	answer = toupper(answer); 
		
	if (answer == 'Y') {
		savingData();
		std::cout << "\n";
		std::cout << "# The program is restarting, wait a moment\n";
		sleep(1);
		std::cout << "\n",
		std::cout << "# ...\n",
		sleep(1);
		system("cls");
		signIn();
	} // End of pos answer to sign in after sign up

	else if (answer == 'N') {
		deletingData();
		std::cout << "\n";
		std::cout << "# We're deleting your data and re-directering you to signUp, wait a moment\n";
		sleep(2);
		signUp();
	} // End of neg answer to sign in after sign up (deleting data)
} // End of SignUp() Function

// ---------------- DEFINITION OF ELSE FUNCTIONS ---------------- //

// If user is trying to sign up and both strings are full
void failSignUp() {
	std::cout << "\n";
	std::cout << "# It looks like you already signed up. Would you like to delete your data and\n";
	std::cout << "create a new profile or just sign in?\n";
	std::cout << "\n",
	std::cout << "# <1 = Delete data / 2 = sign in>\n";
	std::cout << "-";
	std::cin >> answer;

	if (answer == '1') {
		std::cout << "\n";
		std::cout << "# We're deleting your data and re-directering you to the sign up program, wait a moment!\n";
		deletingData();
		sleep(2);
		signUp();
	}

	else if (answer == '2') {
		std::cout << "\n";
		std::cout << "# We're re-directering you to the sign in program, wait a moment!\n";
		sleep(2);
		signIn();
	}
} // End of failSignUp

// If user is trying to sign in and both strings are empty 	
void failSignIn() {

	// If user is trying to sign in and information exist
	if ( !(ifile.fail()) ) {
		std::cout << "\n";
		std::cout << "# It looks like our program detects already existing your information, so we're loading it and\n";
		std::cout << "re-directering you to the sign in program, wait a moment!\n";
		loadingData();
		sleep(2);
		signIn();
	} 

	// If user is trying to sign in but information does not exist
	else if ( (ifile.fail()) ) {
		std::cout << "\n";
		std::cout << "# It looks like our program hasn't detected existing infomation from you, we're re-directering you\n";
		std::cout << "to our sign up program, wait a moment!\n";
		sleep(2);
		signUp();
	} 
} // End of failSignInFunction()

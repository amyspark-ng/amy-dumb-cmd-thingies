//signFunction.hpp
#include <iostream> // main library
#include <ctype.h> // toupper() function
#include <string.h> // empty() function
#include <unistd.h> // sleep() function
#include <fstream> // saving data in text files shit
#include <vector> // vectors duh
#include <algorithm> // uhhhhh transform??

// ---------------- DEFINITION OF SIGN FUNCTIONS ---------------- //

// SIGN IN FUNCTION DEFINITION
signIn() {
	std::cout << "\n";
	signIn_text();
	loadingData();
if ((curName == actName) && (curPassword == actPassword)) {
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
	std::cout << "# It looks like you already signed up. You're being re directed to the sign in program\n";
	sleep(5);
	system("pause");
	system("cls");
	signIn();
}

// If user is trying to sign in and both strings are empty 	
void failSignIn() {
	std::cout << "\n",
	std::cout << "# Are you sure you want to sign in? The program says you don't have any data\n";
	std::cout << "You're being re-directed to the sign up program, wait a few moments.\n"; 
	sleep(5);
	system("cls");
	signUp();
} // End of failSignInFunction()
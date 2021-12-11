// # signVariables.hpp #
#include <iostream> // main library
#include <ctype.h> // toupper() function
#include <string.h> // empty() function
#include <unistd.h> // sleep() function
#include <fstream> // saving data in text files shit
#include <vector> // vectors duh

// ---- Variables ---- //

// fstream storedData class
std::fstream storedData;

// - act stands for actual — entered input when signing up for first time
std::string actName; 
std::string actPassword;

// - cur stands for current — entered input when signing in
std::string curName;	
std::string curPassword;	

// - extr stands for extracted — extracted input from userData.txt
std::string extrName;
std::string extrPassword;

// just a char with answers
char answer;

// ---------------- DEFINITION OF TEXT FUNCTIONS ---------------- //

// DEFINITION OF THE SIGNUP_TEXT() FUNCTION
void signUp_text() {
	std::cout << "----------- S I G N  U P -----------\n";
	std::cout << "Please enter your name and password\n";
	std::cout << "\n";
	std::cout << "# Name: \n";
	std::cout << "-";
	std::cin >> actName;
	std::cout << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "\n";
	std::cout << "# Password: \n";
	std::cout << "-";
	std::cin >> actPassword;
	std::cout << "\n";
	std::cout << "-------------------------------------\n";
} // End of the signUp_text() function

// DEFINITION OF THE SIGNIN_TEXT() FUNCTION
void signIn_text() {
	std::cout << "----------- S I G N  I N -----------\n";
	std::cout << "Please enter your name and password\n";
	std::cout << "\n";
	std::cout << "# Name: \n";
	std::cout << "-";
	std::cin >> curName;
	std::cout << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "\n";
	std::cout << "# Password: \n";
	std::cout << "-";
	std::cin >> curPassword;
	std::cout << "\n";
	std::cout << "-------------------------------------\n";
} // End of the signIn_text() function

// ---------------- DEFINTION OF SAVING DATA FUNCTIONS ---------------- //

// - some big brain stuff which definetely didn't took me more than 5 hours

// savingData() function
void savingData() {

	// generates and opens file writing in it
	storedData.open("userData.txt", std::ios::out);  
	if (storedData.is_open()) {
		// Stored the actual name and password on the file	
		storedData << actName << "\n";
		storedData << actPassword << "\n";
	} // end of is_open thingy
	
	storedData.close(); // closes the file
} // End of savingData() 

// loadingDdata() function
void loadingData() {

	storedData.open("userData.txt", std::ios::in);
	if (storedData.is_open()) {
		getline(storedData, extrName);
		getline(storedData, extrPassword);	

		// gives the 'act' variables the value of the 'extr' from the .txt file
		actName = extrName;
		actPassword = extrPassword; 
	} // End of if
	
	storedData.close();
} // End of loadingData()

// deletes the already written data in userData.txt
void deletingData() {

	storedData.open("userData.txt", std::ios::out);	

	// turns both lines of information to null
	storedData << "";
	storedData << "";	

	storedData.close();
} // End of deletingData()

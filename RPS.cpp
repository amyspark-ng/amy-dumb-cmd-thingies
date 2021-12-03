#include <iostream> // Main library
#include <unistd.h> // sleep() function
#include <ctype.h> // islower() and isupper() functions
#include <cstdlib> // rand() and srand() functions
#include <ctime> // time variable inside srand() (?

#include "gameFunction.hpp"

// main() function declared and defined
int main() {

sleep(1);
std::cout << "\n";
std::cout << loading;
sleep(1);
system("cls");

// Main menu
	std::cout << "---- Welcome to ----\n";
	std::cout << "\n";
	std::cout << mainMenu << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "--- Choose your election! ----\n";
	std::cout << "-- 1: Rock / 2: Paper / 3: Scissors --\n";
	std::cin >> u_choice;
	std::cout << "\n";
	std::cout << "- LOADING - \n";
	sleep(3);
	std::cout << "\n";
	gameFunction();
} // End of main

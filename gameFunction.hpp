#include <iostream> // Main library
#include <unistd.h> // Sleep() function
#include <cstdlib> // rand() and srand() functions
#include <ctime> // time variable inside srand() (?

// # Setup stuff / Variables and strings #

// Strings
std::string loading = ";--- L O A D I N G ---;\n";
std::string mainMenu = R"(  _____                        _____            _       _____      _                        
|  __ \                      |  __ \          | |     / ____|    (_)                       
| |__) __ _ _ __   ___ _ __  | |__) |___   ___| | __ | (___   ___ _ ___ ___  ___  _ __ ___ 
|  ___/ _` | '_ \ / _ | '__| |  _  // _ \ / __| |/ /  \___ \ / __| / __/ __|/ _ \| '__/ __|
| |  | (_| | |_) |  __| |    | | \ | (_) | (__|   <   ____) | (__| \__ \__ | (_) | |  \__ \
|_|   \__,_| .__/ \___|_|    |_|  \_\___/ \___|_|\_\ |_____/ \___|_|___|___/\___/|_|  |___/
| |                                                                             
|_|                                                                             )";
std::string error = R"( _____                    
|  ___|                   
| |__ _ __ _ __ ___  _ __ 
|  __| '__| '__/ _ \| '__|
| |__| |  | | | (_) | |   
\____/_|  |_|  \___/|_|   )";
std::string rock = "1) ROCK ;";
std::string paper = "2) PAPER ;";
std::string scissors = "3) SCISORS ;";

// Variables
char u_answer;
int u_choice;
int c_choice;

// # Definition of mainMenu_text(), endProgram() and gameFunction() declared and defined 
void endProgram() {
	sleep(1.5);
	std::cout << "\n";
	system("pause");
}
void gameFunction() {

// srand and rand functions
srand(time(NULL));
int c_choice = rand() % 3 + 1; // Rand function

// User's choice switch
switch(u_choice) {
	case 1:
	std::cout << "- ; Your election was: \n"; 
	std::cout << rock;
	std::cout << "\n";
	break;

	case 2: 
	std::cout << "- ; Your election was: \n"; 
	std::cout << paper;
	std::cout << "\n";
	break;

	case 3:
	std::cout << "- ; Your election was: \n"; 
	std::cout << scissors;
	std::cout << "\n";
	break;
	
	default:
	std::cout << "Your election was unknown";
	break;
} // End of u_choice switch

sleep(1);
std::cout << "\n";
std::cout << "- ; And... Computer's choice was...\n";
sleep(1);

// Computer's choice switch
switch(c_choice) {
	case 1: 
	std::cout << rock;
	std::cout << "\n";
	break;
	
	case 2:  
	std::cout << paper;
	std::cout << "\n";
	break;
	
	case 3: 
	std::cout << scissors;
	std::cout << "\n";
	break;
}

sleep(2);
std::cout << "\n";
std::cout << "--Which means that..." << "\n";
std::cout << "\n";
std::cout << "...\n";

if (u_choice == c_choice) {
	std::cout << "; -DRAW\n";
}

else if (u_choice == 1 && c_choice == 3) 
{	std::cout << "; -YOU WIN!!\n";
}
	
else if (u_choice == 2 && c_choice == 1) {
	std::cout << "; -YOU WIN!!\n";
}

else if (u_choice == 3 && c_choice == 2) {
	std::cout << "; -YOU WIN!!\n";

}

else {
	std::cout << "; -COMPUTER WINS! Good luck next time.\n";
}

sleep(2);
std::cout << "\n";
system("pause");

// Part that asks if the user wants to go again
std::cout << "\n";
std::cout << " -- The match is over, restart the app to play again! --\n";
endProgram();

} // Ending of the gameFunction
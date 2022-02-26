#include <iostream>
#include <fstream>

std::fstream FileToCreate("FileCreated.html");

int main() {
	
	std::string textDisplayed;
	
	std::cout << "Hello im creating a 'web page' for you, what text would you like to be displayed there?\n";
	std::cout << "\n";
	std::getline(std::cin, textDisplayed);
	std::cout << "Great, wait a second pls :)\n";

	FileToCreate.open("FileCreated.html", std::ios::out);  

	if (FileToCreate.is_open()) {
		FileToCreate << R"(<p>)" << textDisplayed << R"(</p>)";
	}	

	FileToCreate.close();

	std::cout << "Your file got created, press enter to see it in your default browser :)\n";
	system("pause");

	system("./FileCreated.html");

}
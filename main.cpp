#include <iostream>
#include<cstring>

#include "Page.h"
#include "Book.h"
#include "Comment.h"
#include"Kindle.h"
#include"MyString.h"
const int MAX_COMMAND = 1000;
int main() {
	Kindle proba;
	char command[MAX_COMMAND];
	MyString command1;
	MyString username;
	MyString password;
	char tempinput[MAX_COMMAND];
	std::cout << "Enter signup or login" << std::endl;
	while (true) {
		
		std::cin.getline(command, 1000);
		command1 = command;
		if (command1 == "signup"); {
			std::cout << "Enter username: "<<std::endl;
			
			std::cin >>tempinput;
			username = tempinput;
			std::cout << "Enter password: " << std::endl;
			std::cin >> tempinput;
			password = tempinput;
			proba.RegisterUser(username, password);
			std::cout << "User registered!" << std::endl;
			std::cout << "Enter command" << std::endl;
		}
		if (command1 == "login") {
			std::cout << "Enter username: " << std::endl;
			std::cin >> tempinput;
			username = tempinput;
			std::cout << "Enter password: " << std::endl;
			std::cin >> tempinput;
			password = tempinput;
			if (proba.Login(username, password) == true) {
				std::cout << "Welcome" << std::endl;
				std::cout << "Enter command" << std::endl;
			}
		}
		if (command1 == "view") {
			if (proba.checkUser(username, password) == true) {
				proba.displayBooks();
			}
		}
		if (command1 == "read") {
			if (proba.checkUser(username, password) == true) {
				std::cin.getline(command, 1000);
				MyString bookTitle;
				 bookTitle= command;
				 unsigned int pageFromBook=0; //we always begin with 0
				 if (proba.chooseBook(bookTitle) == true) {
					 std::cout<<proba.findBook(bookTitle).viewPage(pageFromBook).c_str()<<std::endl;

					 while (true) {
						 std::cin.getline(command, 1000);
						 MyString visualization;
						 visualization = command;
						 if (visualization == "n") {
							 pageFromBook++;
							 if (pageFromBook == proba.findBook(bookTitle).getPageSize()) break;
							 std::cout << proba.findBook(bookTitle).viewPage(pageFromBook).c_str()<<std::endl;
						 }
						 if (visualization == "p") {
							 pageFromBook--;
							 if (pageFromBook == 0) break;
							 std::cout << proba.findBook(bookTitle).viewPage(pageFromBook).c_str() << std::endl;
						 }
						 if (visualization == "q") break;
					 }
					 
				 }

			}
			
		}
		if (command1 == "rate") {

		}

	}
	//Page one;
	//one.setBookName("snowwhite");
	//one.getWriting("hey there");
	//one.WriteToPage();

}
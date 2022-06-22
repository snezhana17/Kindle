#include "Kindle.h"
#include <fstream>

void Kindle::freeUsers()
{
	delete[] users;
}

void Kindle::freeAllBooks()
{
	delete[] allBooks;
}

bool Kindle::checkUser(const MyString& username, const MyString& password) const
{
	unsigned int checkUsername = 0;
	unsigned int checkPassword = 0;
	for (int i = 0; i < userNumber; i++) {
		if (users[i].getUsername() == username) {
			checkUsername++;
		}
		if (users[i].getPassword() == password) {
			checkPassword++;
		}
	}
	if (checkPassword == 1 && checkUsername == 1) return true;
	else return false;
}

void Kindle::RegisterUser(MyString& username, MyString& password)
{
	if (checkUser(username, password) == false) {
		userNumber++;
		users[userNumber - 1].setUsername(username);
		users[userNumber - 1].setPassword(password);
	}
}

bool Kindle::Login(const MyString& username, const MyString& password)
{
	if (checkUser(username, password) == true) {
		return true;
	}
	else return false;
}

void Kindle::displayBooks() const
{
	
	for (int i = 0; i < bookNumber; i++) {
		std::cout << i + 1 << "." << allBooks[i].getNameOfBook().c_str() << "by " << allBooks[i].getNameOfAuthor().c_str()<< std::endl;
	}
}

void Kindle::addBook(MyString& name, MyString& author,unsigned int pages)
{
	bookNumber++;
	allBooks[bookNumber - 1].setNameOfBook(name);
	allBooks[bookNumber - 1].setNameOfAuthor(author);
	allBooks[bookNumber - 1].setPageSize(pages);


}

bool Kindle::isBook(MyString& bookName)
{
	int isBook = 0;
	for (int i = 0; i < bookNumber; i++) {
		if (allBooks[i].getNameOfBook() == bookName) {
			isBook++;
		}
	}
	if (isBook == 1) return true;
	else return false;
}

bool Kindle::chooseBook(MyString& bookName)
{
	for (int i = 0; i < bookNumber; i++) {
		if (allBooks[i].getNameOfBook() == bookName) {
			return true;
		}
	}
	return false;
}

unsigned int Kindle::getBookNumber()
{
	return bookNumber;
}

Book& Kindle::findBook(const MyString& bookName)
{
	for (int i = 0; i < bookNumber; i++) {
		if (allBooks[i].getNameOfBook() == bookName) {
			return allBooks[i];
		}
	}
}

void Kindle::saveKindle()
{
	MyString kindle="kindle";
	std::ofstream library(kindle.c_str());
	if (!library.is_open()) return;
	for (int i = 0; i < userNumber; i++) {
		library.write(users[i].getUsername().c_str(), users[i].getUsername().getSize());
		library.write(users[i].getPassword().c_str(), users[i].getPassword().getSize());
	}
	for (int i = 0; i < bookNumber; i++) {
		library.write(allBooks[i].getNameOfAuthor().c_str(), allBooks[i].getNameOfAuthor().getSize());
		library.write(allBooks[i].getNameOfBook().c_str(), allBooks[i].getNameOfBook().getSize());
	}
	library.close();
}

Kindle::~Kindle()
{
	saveKindle();
	freeUsers();
	freeAllBooks();
}



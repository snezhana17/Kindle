#include "User.h"

void User::changeBook(const MyString& bookName)
{
	int foundBook = 0;
	for (int i = 0; i < writtenSize; i++) {
		if (writtenBooks[i].getNameOfBook() == bookName) {
			foundBook++;
		}
	}
	if (foundBook == 1) {

	}
}

void User::setUsername(const MyString& text)
{
	username = text;
}

void User::setPassword(const MyString& text)
{
	password = text;
}

MyString& User::getUsername()
{
	return username;
}

MyString& User::getPassword()
{
	return password;
}

void User::setCurrentBook(Book& curr)
{
	currentBook = curr;
}

User::~User()
{
	freeReadBooks();
	freeWrittenBooks();
}


void User::freeReadBooks()
{
	delete[] readBooks;
}

void User::freeWrittenBooks()
{
	delete[] writtenBooks;
}

void User::readBook(unsigned int page)
{
	if (page == currentBook.getPageSize()) {
		readSize++;
		readBooks[readSize - 1] = currentBook;
	}
}

void User::writeBook(const MyString& bookName)
{
	writtenSize++;
	writtenBooks[writtenSize - 1].setNameOfBook(bookName);
	writtenBooks[writtenSize - 1].setNameOfAuthor(username);
	
}

void User::rateBook()
{
}

void User::leaveAComment(const MyString& bookName, MyString& comment)
{
	for (int i = 0; i < readSize; i++) {
		if (readBooks[i].getNameOfBook() == bookName) {
			readBooks[i].addComment(comment, username); 
			return;
		}
	}
}

void User::leaveARating(const MyString& bookName, unsigned int rating)
{
	for (int i = 0; i < readSize; i++) {
		if (readBooks[i].getNameOfBook() == bookName) {
			readBooks[i].setRatings(username,rating);
			return;
		}
	}
}

void User::openComments()
{
	 currentBook.getComment();
}

void User::openRatings()
{
	currentBook.getallRatings();
}

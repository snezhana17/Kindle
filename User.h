#pragma once
#include "Book.h"

class User {
	MyString username;
	MyString password;
	Book* readBooks;
	Book* writtenBooks;
	unsigned int writtenSize = 0;
	unsigned int readSize = 0;
	Book currentBook;

public:
	
	void freeReadBooks();
	void freeWrittenBooks();
	void readBook(unsigned int);
	void writeBook(const MyString&);
	void rateBook();
	void leaveAComment(const MyString&, MyString&);
	void leaveARating(const MyString&, unsigned int);
	void openComments();
	void openRatings();
	void changeBook(const MyString&);
	void changeRating();
	void setUsername(const MyString&);
	void setPassword(const MyString&);
	MyString& getUsername();
	MyString& getPassword();
	void setCurrentBook(Book&);

	~User();


};

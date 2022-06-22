#pragma once
#include <iostream>
#include "Book.h"
#include "User.h"
class Kindle {
	User* users;
	unsigned int userNumber = 0;
	Book* allBooks;
	unsigned int bookNumber = 0;
public:
	void freeUsers();
	void freeAllBooks();
	bool checkUser(const MyString&, const MyString&) const;
	void RegisterUser(MyString&, MyString&);
	bool Login(const MyString&, const MyString&);
	void displayBooks() const;
	void addBook(MyString&,MyString&,unsigned int);
	bool isBook(MyString&);
	bool chooseBook(MyString&);
	unsigned int getBookNumber();
	Book& findBook(const MyString&);
	void saveKindle();
	~Kindle();
	friend class User;
};
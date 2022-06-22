#include "MyString.h"
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)


void MyString::copyFrom(const MyString& other)
{
	str = new char[other.size + 1];
	strcpy(str, other.str);
	size = other.size;
}

MyString::MyString()
{
	str = new char[1];
	str[0] = 0;
	size = 1;
}

void MyString::free()
{
	delete[] str;
}

MyString::MyString(const char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
	size = strlen(str);
}
void MyString::concat(const MyString& rhs)
{
	char* temp = new char[this->size + rhs.size + 1];
	strcpy(temp, this->str);
	strcat(temp, rhs.str);

	free();
	this->str = temp;
	this->size = strlen(str);
}
bool MyString::operator==(MyString const& str2)
{
	if (str2.size != size) return 0;
	for (size_t i = 0; i < size; i++)
	{
		if (str2.str[i] != str[i]) return 0;
	}
	return 1;
}

bool MyString::operator!=(MyString const& str2)
{
	if (*this == str2) return 0;
	return 1;
}

bool MyString::operator>(MyString const& str2)
{
	size_t shortestLength = (size > str2.size) ? str2.size : size;
	for (size_t i = 0; i < shortestLength; ++i)
	{
		if (str[i] == str2.str[i]) continue;
		if (str[i] > str2.str[i]) return 1;
		else return 0;
	}
	return 0;
}

bool MyString::operator<(MyString const& str2)
{
	if (*this == str2) return 0;
	if (*this > str2) return 0;
	return 1;
}

void MyString::print() // Prints without a new line
{
	std::cout << this->str;
}

void MyString::printnl() // Prints and adds a new line
{
	std::cout << this->str << std::endl;
}

MyString::MyString(const MyString& toCopy)
{
	copyFrom(toCopy);
}

MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs) {
		free();
		copyFrom(rhs);
	}

	return *this;
}


unsigned int MyString::getSize() const
{
	return size;
}

MyString::~MyString()
{
	delete[] str;
}

char* MyString::c_str() const
{
	return str;
}


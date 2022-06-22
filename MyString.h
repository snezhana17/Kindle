#pragma once


class MyString
{
private:
	char* str;
	unsigned int size;
	void copyFrom(const MyString&);
	void free();
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	void print();
	void printnl();
	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	bool operator>(const MyString&);
	bool operator<(const MyString&);
	unsigned int getSize()const;
	char* c_str()const;
	void concat(const MyString&);
	~MyString();
};


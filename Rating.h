#pragma once
#include "MyString.h"
class Rating {
	MyString name;
	unsigned int rating=0;
public:
	void setName(const MyString&);
	MyString getName();
	void setRating(unsigned int);
	unsigned int getRating();
};
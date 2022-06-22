#pragma once
#include "MyString.h"
class Comment {
	MyString comment;
	MyString name;
public:
	void setName(const MyString&);
	void setComment(const MyString&);
	MyString getName();
	MyString getComment();
};
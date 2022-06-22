#include "Comment.h"

void Comment::setName(const MyString& text)
{
	name = text;
}

void Comment::setComment(const MyString& text)
{
	comment = text;
}

MyString Comment::getName()
{
	return name;
}

MyString Comment::getComment()
{
	return comment;
}

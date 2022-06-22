#include "Rating.h"

void Rating::setName(const MyString& text)
{
	name = text;
}

MyString Rating::getName()
{
	return name;
}

void Rating::setRating(unsigned int rate)
{
	if (rate >= 0 && rate <= 10) {
		rating = rate;
	}
	else return;
}

unsigned int Rating::getRating()
{
	return rating;
}

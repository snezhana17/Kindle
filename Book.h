#pragma once
#include "Page.h"
#include "Rating.h"
#include "Comment.h"
class Book {
	MyString nameOfBook;
	MyString nameOfAuthor;
	double rating;
	Rating* ratings;
	Page* pages;
	Comment* comments;
	unsigned int commentSize = 0;
	unsigned int rateSize = 0;
	unsigned int pageSize = 0;
public:
	
	void freeComment();
	void freeRating();
	void freePages();
	void addComment( const MyString&,const MyString&);
	MyString& getNameOfBook();
	void setNameOfBook(const MyString&);
	MyString& getNameOfAuthor();
	void setNameOfAuthor(const MyString&);
	void setRatings(const MyString&, unsigned int);
	void setAverageRating();
	unsigned int getRating();
	void addToPage(const MyString&);
	void addMultiplePages(MyString&);
	void saveBook();
	MyString& viewPage(unsigned int);
	void setPageSize(unsigned int);
	unsigned int getPageSize();
	unsigned int getCommentSize();
	unsigned int getAllRatingSize();
	void getComment();
	void getallRatings();
	~Book();

};

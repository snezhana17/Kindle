#include "Book.h"
#include <cstring>
#include <iostream>
#include <fstream>
#pragma warning(disable: 4996)

void Book::freeComment()
{
	delete[] comments;
}

void Book::freeRating()
{
	delete[] ratings;
}

void Book::freePages()
{
	delete[] pages;
}

void Book::addComment( const MyString& name,const MyString& comment)
{
	commentSize++;
	comments[commentSize - 1].setComment(comment);
	comments[commentSize - 1].setName(name);
}

MyString& Book::getNameOfBook()
{
	return nameOfBook;
}

void Book::setNameOfBook(const MyString& text)
{
	nameOfBook = text;
}

MyString& Book::getNameOfAuthor()
{
	return nameOfAuthor;
}

void Book::setNameOfAuthor(const MyString& text)
{
	nameOfAuthor = text;
}

void Book::setRatings( const MyString& name, unsigned int rate)
{
	rateSize++;
	Rating* ratings = new Rating[rateSize];
	ratings[rateSize - 1].setName(name);
	ratings[rateSize - 1].setRating(rate);
}

void Book::setAverageRating()
{
	int temp=0;
	for (int i = 0; i < rateSize; i++) {
		temp += ratings[i].getRating();
	}
	rating = temp / (rateSize - static_cast<double>(1));
}

unsigned int Book::getRating()
{
	setAverageRating();
	return rating;
}

void Book::addToPage(const MyString& text)
{
	pageSize++;
	Page* pages = new Page[pageSize];
	pages[pageSize - 1].getWriting(text);
	pages->setPageNumber(pageSize - 1);
}

void Book::addMultiplePages(MyString& text)
{
	int tempSize = text.getSize();
	char* tempText = new char[text.getSize()];
	tempText = text.c_str();
	if (text.getSize() < 1800) addToPage(text);
	while (tempSize  >= 1800) {
		char temp[1805];
		strncpy(temp, tempText, 1800);
		MyString temp1;
		temp1 = temp;
		addToPage(temp1);
		MyString temp2;
		for (int i = 1800; i < tempSize; i++) {
			tempText[i - 1800] = tempText[i];
		}
		tempSize -= 1800;
		tempText = new char[tempSize];
		delete[] tempText;
		
	}
		

	
}

void Book::saveBook()
{
	MyString fileName = nameOfBook;
	std::ofstream page(fileName.c_str());
	if (!page.is_open()) return;
	page.write(nameOfBook.c_str(), nameOfBook.getSize());
	page << std::endl;
	page.write(nameOfAuthor.c_str(), nameOfAuthor.getSize());
	page << std::endl;
	page<<rating;
	for (int i = 0; i < rateSize; i++) {
		MyString temp;
		temp = ratings[i].getName();
		page.write(temp.c_str(), temp.getSize());
		page << std::endl;
		page << ratings[i].getRating();
		page << std::endl;


	}
	for (int i = 0; i < pageSize; i++) {
		MyString temp;
		temp = comments[i].getName();
		page.write(temp.c_str(), temp.getSize());
		page << std::endl;
		MyString temp1;
		temp1 = comments[i].getComment();
		page.write(temp1.c_str(), temp1.getSize());
		page << std::endl;


	}

	page.close();
}

MyString& Book::viewPage(unsigned int pageNumber)
{
	 return pages[pageNumber].ReadFromPage();  
}

void Book::setPageSize(unsigned int pages)
{
	pageSize = pages;
}

unsigned int Book::getPageSize()
{
	return pageSize;
}

unsigned int Book::getCommentSize()
{
	return commentSize;
}

unsigned int Book::getAllRatingSize()
{
	return rateSize;
}

void Book::getComment()
{
	for (int i = 0; i < commentSize; i++) {
		std::cout << comments[i].getName().c_str() << "said" << comments[i].getComment().c_str() << std::endl;
	}
}

void Book::getallRatings()
{
	for (int i = 0; i < rateSize; i++) {
		std::cout << ratings[i].getName().c_str() << "rated" << ratings[i].getRating() << std::endl;
	}
}


Book::~Book()
{
	saveBook();
	freePages();
	freeRating();
	freeComment();
}

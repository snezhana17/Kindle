#include"Page.h"
#include <iostream>
#include <fstream>
#pragma warning (disable:4996)
#define MAX_DIGITS 1000
bool Page::MaxPage()
{
	if(charNumber>=1800) return false;
	return true;
}

void Page::WriteToPage()
{	
	createFileName();
	std::ofstream page(fileName.c_str());
	if (!page.is_open()) return;
	page.write(writeToPage.c_str(), writeToPage.getSize());
	page.close();
	
}

MyString& Page::ReadFromPage()
{
	createFileName();
	std::ifstream page(fileName.c_str());
	if (page.is_open()) {
		char ch[1800];
		int i = 0;
		while (1) {

			page >> ch[i];
			readFromPage.concat(ch);
			i++;
		}
	}
	page.close();
	return readFromPage;
}

void Page::createFileName()
{
	char number_array[MAX_DIGITS];
	sprintf(number_array, "%d", pageNumber);
	fileName = bookName;
	fileName.concat("&");
	fileName.concat(number_array);
}

void Page::addSymbols(const MyString& text)
{
	if (MaxPage() == false) return;
	writeToPage.concat(text);
	charNumber = writeToPage.getSize();
	if (MaxPage() == false) return;
	WriteToPage();

}

void Page::getWriting(const MyString& text)
{
	writeToPage = text;
	charNumber = writeToPage.getSize();
	
}

void Page::setBookName(const MyString& text)
{
	bookName = text;
}

void Page::setPageNumber(unsigned int num)
{
	pageNumber = num;
}

void Page::savePage()
{
	WriteToPage();
}

Page::~Page()
{
	savePage();
}


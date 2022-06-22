#pragma once
#include"MyString.h"
//a page usually has 1800 characters with spaces so thats the limit we will expect for every page
class Page {

	unsigned int pageNumber=0;
	unsigned int charNumber=0;
	MyString writeToPage;
	MyString readFromPage;
	MyString fileName;
	MyString bookName;

public:
	bool MaxPage();
	void WriteToPage();
	MyString& ReadFromPage();
	void createFileName();
	void addSymbols(const MyString&);	
	void getWriting(const MyString&);
	void setBookName(const MyString&);
	void setPageNumber(unsigned int);
	void savePage();
	~Page();
};
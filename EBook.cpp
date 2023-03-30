#include "EBook.h"


EBook::EBook(int a_id, int a_price, string a_title, string a_author, string a_type, int a_nr_pages, int a_year, string a_publishing_house):
	Book(a_id, a_price,a_title, a_author, a_type), nr_pages{a_nr_pages}, year{a_year}, publishing_house{a_publishing_house}
{
	// constructor a unei subclase a lui Book
	this->nr_pages = a_nr_pages;
	this->year = a_year;
	this->publishing_house = a_publishing_house;
}

string EBook::toString()
{
	string str;
	str += Book::toString();
	str += "number of pages is " + std::to_string(nr_pages) + " and it was publish in " + std::to_string(year) + " by  publishing house " + publishing_house;
	return str;
}

#pragma once
#include "Book.h"
#include <iostream>

class EBook : public Book
{
public:
	EBook(int a_id, int a_price, string a_title, string a_author, string a_type,int a_nr_pages, int a_year, string a_publishing_house);
	EBook() = default;
	// getters
	inline int getNrPages() const { return nr_pages; }
	inline int getYear() const { return year; }
	inline string getPublishing_house() const { return publishing_house; }

	//setters
	inline void setNrPages(int a_nr_pages) { this->nr_pages = a_nr_pages; }
	inline void setYear(int a_year) { this->year = a_year; }
	inline void setPublishing_house(string a_publishing_house) { this->publishing_house = a_publishing_house; }


	string toString() override;
private:
	int nr_pages, year;
	string publishing_house;
	//bool isfree;
};

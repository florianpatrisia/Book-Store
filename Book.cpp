#include "Book.h"
#include <string>


Book::Book(int a_id, int a_price, string a_title, string a_author, string a_type)
{
	// cosntructor
	this->id = a_id;
	this->price = a_price;
	this->title = a_title;
	this->author = a_author;
	this->type = a_type;
}

void Book::display(ostream& os) const
{
	os << "id: " << id << ", price: " << price << ", title: " << title << ", author: " << author;
	os << ", type: " << type;
}

string Book::toString()
{
	// convert to string
	// display
	string str;
	str += "The book " + title + " of author " + author + " has id " + std::to_string(id) + " and price " + std::to_string(price)+" type "+type;
	return str;
}

ostream& operator<<(std::ostream& os, const Book& other)
{
	other.display(os);
	return os;
}

#pragma once
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using namespace std;

#include <stdexcept>
using std::invalid_argument;

class Book
{
protected:
	int id, price;
	string title, author, type;
public:
	Book(int a_id, int a_price, string a_title, string a_author, string a_type);
	Book() = default;
	// getters
	inline int getID() const { return id; }
	inline int getPrice() const { return price; }
	inline string getTitle() const { return title; }
	inline string getAuthor() const { return author; }
	inline string getType() const { return type; }

	// setters
	inline void setID(int a_id) { this->id = a_id; }
	inline void setPrice(int a_price) { this->price = a_price; }
	inline void setTitle(string a_title) { this->title = a_title; }
	inline void setAuthor(string a_author) { this->author = a_author; }
	inline void setType(string a_type) { this->type = a_type; }


	//pure virtual
	virtual string toString();

	virtual void display(ostream& os)const;
	friend ostream& operator <<(ostream& os, const Book& other);

};
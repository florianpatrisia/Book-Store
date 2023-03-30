#pragma once
#include "Book.h"
#include <vector>
using std::vector;

class BookRepo
{
public:
	// default constructor
	BookRepo()=default;
	// destructor
	~BookRepo()=default;
	
	void addBook(Book *other);
	void remove(int id);
	void modify(int id,int newPrice);

	const vector<Book*>& get_all();

	ostream& display(ostream& os, bool (*filterFunction)(Book*));

	string bookToCSV(Book* other);

	void loadData();
	void saveData();
private:
	vector<Book*> data;
};

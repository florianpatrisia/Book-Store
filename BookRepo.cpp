#include "BookRepo.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

void BookRepo::addBook(Book* other)
{
	// add a new book in the repo
	data.push_back(other);
}

void BookRepo::remove(int id)
{
	// sterge o carte din repo dupa id
	Book* result = nullptr;
	auto it = find_if(data.begin(), data.end(), [id](Book* result) {return result->getID()== id; });// daca returneaza 1 ia pozitia lui ala pe care il cautam
	if (it != data.end())
		data.erase(it);
}

void BookRepo::modify(int id, int newPrice)
{
	// modifica pretul unei carti din repo care are un anumit id
	//for (Book book : data)
	//for (auto i = 0; i < data.size(); i++)
		//if (data[i].getID() == id)
			//data[i].setPrice(newPrice);
	/*
	auto it = find_if(data.begin(), data.end(), [&id](Book idBook) {return id == idBook.getID(); });// daca returneaza 1 ia pozitia lui ala pe care il cautam
	if (it != data.end())
		data[it].setPrice(newPrice);*/
}

const vector<Book*>& BookRepo::get_all()
{
	// returneaza toate cartiile din repo
	return data;
}


void BookRepo::loadData()
{
	fstream inputFile;
	try
	{
		inputFile.open("Input.csv", ios::in);
	}
	catch (const std::exception&)
	{
		cout << "\nInput file couldn't be open!\n";
	}
	string line;

	while (getline(inputFile, line))
	{
		vector<string> tokens;
		stringstream ss(line);
		string token;
		while (getline(ss, token, ','))
			tokens.push_back(token);

		int id = stoi(tokens[0]); // convert allBooks[0] (string) to a int
		int price = stoi(tokens[1]);
		string title = tokens[2];
		string author = tokens[3];
		string type = tokens[4];

		Book* newBook = new Book(id, price, title, author, type);
		addBook(newBook);

	}
	inputFile.close();
}

void BookRepo::saveData()
{
	fstream fout;
	try
	{
		fout.open("Output.csv", ios::out);
	}
	catch (const std::exception&)
	{
		cout << "Output file couldn't be open!\n";
	}

	for (auto i = 0; i < data.size(); i++)
		fout << bookToCSV(data[i]) << endl;
	fout.close();
}

ostream& BookRepo::display(ostream& os, bool(*filterFunction)(Book*))
{
	for (auto i = 0; i < data.size(); i++)
		if (filterFunction(data[i])==true)
		os << *data[i] << endl;
	return os;
}

string BookRepo::bookToCSV(Book* other)
{
	string str;
	str += to_string(other->getID()) + ", " + to_string(other->getPrice()) + ", " + other->getTitle() + ", ";
	str += other->getAuthor() + ", " + other->getType() + ".\n";
	return str;
}


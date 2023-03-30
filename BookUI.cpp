#include "BookUI.h"
#include <iostream>
using namespace std;
#include <stdexcept>
using std::invalid_argument;

void BookUI::addBookUI()
{
	int id, price;
	string title, author, type;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter title: ";
	cin >> title;
	cout << "Enter author: ";
	cin >> author;
	cout << "Enter type: ";
	cin >> type;

	Book* newbook = new Book(id, price, title, author, type);
	controller.addBookCtrl(newbook);
}

void BookUI::removeBookUI()
{
	int id;
	cout << "Enter ID: ";
	cin >> id;

	controller.removeCtrl(id);
}

void BookUI::modifyBookUI()
{
	int id, price;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter price: ";
	cin >> price;

	controller.modifyCtrl(id, price);
}
/*
void BookUI::filterUI()
{
	int price;
	cout << "Enter price: ";
	cin >> price;

	controller.filter(price);
}*/

void BookUI::displayAllBooksUI()
{
	controller.displayAll();
}

void BookUI::undoUI()
{
	controller.undo();
}

void BookUI::redoUI()
{
	controller.redo();
}

void BookUI::displayMenu()
{
	controller.loadDataCtrl();
	do {
		cout << "Please insert your option" << endl;
		cout << "\ta|A: Add a book" << endl;
		cout << "\tr|R: Remove a book" << endl;
		cout << "\tm|M: Modify a book" << endl;
		cout << "\tf|F: Filter all books" << endl;
		cout << "\tu|U: Undo" << endl;
		cout << "\tb|B: Redo" << endl;
		cout << "\td|D: Display all books" << endl;
		cout << "\te|E: Exit" << endl;

		char option;
		cin >> option;
		switch (option)
		{
		case 'a':
		case 'A': {
			addBookUI();
			break;
		}

		case 'r':
		case 'R': {
			removeBookUI();
			break;
		}

		case 'm':
		case 'M': {
			modifyBookUI();
			break;
		}

		case 'f':
		case 'F': {
			//filterUI();
			break;
		}
		case 'u':
		case 'U': {
			undoUI();
			break;
		}

		case 'b':
		case 'B': {
			redoUI();
			break;
		}

		case 'd':
		case 'D': {
			displayAllBooksUI();
			break;
		}

		case 'e':
		case 'E': {
			exit(0);
			break;
		}
		default:
			break;
		}
	} while (true);
	controller.saveDataCtrl();

}
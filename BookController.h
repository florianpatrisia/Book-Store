#pragma once
#include "BookRepo.h"
#include <utility>
#include <vector>
#include <stack>
using namespace std;
using std::vector;
using std::stack;

enum class Action {
	ADD,
	REMOVE
};

class BookController
{
public:
	BookController(BookRepo& other):bookrepo{other}{};
	BookController()=default;
	void addBookCtrl(Book* other);
	void removeCtrl(int id);
	void modifyCtrl(int id, int newPrice);

	//vector<Book*> filter(int price);

	void getAllController();
	void displayAll();
	
	void undo();
	void redo();

	void loadDataCtrl();
	void saveDataCtrl();
	
protected:
	BookRepo& bookrepo;
	//vector de actiuni
	std::stack<pair<Action, Book*>>undoStack;
	std::stack<pair<Action,	Book*>> redoStack;
};
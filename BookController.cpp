#include "BookController.h"
#include <iostream>

void BookController::addBookCtrl(Book* other)
{
	bookrepo.addBook(other);
}

void BookController::removeCtrl(int id)
{
	bookrepo.remove(id);
}

void BookController::modifyCtrl(int id, int newPrice)
{
	bookrepo.modify(id, newPrice);
}
void BookController::getAllController()
{
	bookrepo.get_all();
}
void BookController::displayAll()
{
	bookrepo.display(std::cout, [](Book* book)->bool {return true; });
}
/*
void BookController::displayCtrl()
{
	bookrepo.display(std::cout);
}*/
/*
vector<Book*> BookController::filter(int price)
{
	vector<Book*> data_filter;
	vector<Book*> data = bookrepo.get_all();
	for (const Book* book : data)
		if (book->getPrice() == price)
			data_filter.push_back(&book);
	return data_filter;
}
*/
/*
const vector<Book*> BookController::getAllController()
{
	bookrepo.get_all();
}*/

void BookController::undo()
{
	if (!undoStack.empty())
	{
		pair<Action, Book*> lastOperation = undoStack.top();
		redoStack.push(lastOperation);///add the last operation to the redo stack

		if (lastOperation.first == Action::ADD)///if last operation was 'ADD' then remove the added element
			bookrepo.remove(lastOperation.second->getID());
		else
			bookrepo.addBook(lastOperation.second);///if last operation was 'REMOVE' then add the removed element

		undoStack.pop();
	}

}

void BookController::redo()
{
	if (!redoStack.empty())
	{
		pair<Action, Book*> lastOperation = redoStack.top();
		undoStack.push(lastOperation);///add the last operation back to the undo stack

		if (lastOperation.first == Action::ADD)///if last operation was 'ADD' then add back the animal 
			bookrepo.addBook(lastOperation.second);
		else
			bookrepo.remove(lastOperation.second->getID());///if last operation was 'REMOVE' then remove back the animal

		redoStack.pop();
	}
}

void BookController::loadDataCtrl()
{
	bookrepo.loadData();
}

void BookController::saveDataCtrl()
{
	bookrepo.saveData();
}

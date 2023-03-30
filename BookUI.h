#pragma once

#include "BookController.h"

class BookUI
{
public :
	BookUI(BookController& ctrl):controller{ctrl}{};

	void displayMenu();
	void addBookUI();
	void removeBookUI();
	void modifyBookUI();
	//void filterUI();
	void displayAllBooksUI();

	void undoUI();
	void redoUI();

private:
	BookController controller;
};
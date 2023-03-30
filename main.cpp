#include <iostream>
#include "Book.h"
#include "AudioBook.h"
#include "EBook.h"
#include "BookRepo.h"
#include "BookController.h"
#include "BookUI.h"

using namespace std;
int main() {

	BookRepo repo;
	BookController c(repo);
	BookUI ui(c);

	ui.displayMenu();
}
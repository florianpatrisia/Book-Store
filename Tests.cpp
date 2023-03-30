#include <iostream>
#include <string>
#include "Tests.h"
#include <assert.h>
#include <cassert>
#include "Book.h"
#include "AudioBook.h"
#include "EBook.h"
#include "BookRepo.h"
#include "BookController.h"
#include "BookUI.h"

using namespace std;
using std::cout;
using std::string;

/*
void Tests::runAllTests()
{
	// Run domain tests
	std::cout << "Tests begin\n";

	std::cout << "Domain test:\n";
	runDomainTests();

	std::cout << "Repository test:\n";
	runRepoTests();

	std::cout << "Tests end\n";
}
*/

void Tests::runDomainTests()
{
	cout << "Start domain tests.\n";
	// tests for getters and setters

	Book b1;
	b1.setID(13);
	assert(b1.getID() == 13);
	b1.setPrice(89);
	assert(b1.getPrice() == 89);
	b1.setTitle("Title 1");
	assert(b1.getTitle() == "Title 1");
	b1.setAuthor("Author 1");
	assert(b1.getAuthor() == "Author 1");
	b1.setType("ACTION");
	assert(b1.getType() == "ACTION");

	Book b2{ 90, 450, "Title 2", "Author 2", "HISTORICAL"};
	assert(b2.getID() == 90);
	assert(b2.getPrice() == 89);
	assert(b2.getTitle() == "Title 2");
	assert(b2.getAuthor() == "Author 2");
	assert(b2.getType() == "HISTORICAL");

	AudioBook ab1;
	ab1.setID(10);
	assert(ab1.getID() == 10);
	ab1.setPrice(400);
	assert(ab1.getPrice() == 400);
	ab1.setTitle("Audio Book 1");
	assert(ab1.getTitle() == "Audio Book 1");
	ab1.setAuthor("Author 11");
	assert(ab1.getAuthor() == "Author 11");
	ab1.setType("COMIC");
	assert(ab1.getType() =="COMIC");
	ab1.setTime(140);
	assert(ab1.getTime() == 140);
	ab1.setReader_name("Name 1");
	assert(ab1.getReader_name() == "Name 1");
	ab1.setVoice(Voice::MAN);
	assert(ab1.getVoice() == Voice::MAN);
	
	EBook eb1;
	eb1.setID(19);
	assert(eb1.getID() == 19);
	eb1.setPrice(1200);
	assert(eb1.getPrice() == 1200);
	eb1.setTitle("EBook 1");
	assert(eb1.getTitle() == "EBook 1");
	eb1.setAuthor("Author 5");
	assert(eb1.getAuthor() == "Author 5");
	eb1.setType("HISTORICAL");
	assert(eb1.getType() == "HISTORICAL");
	eb1.setNrPages(500);
	assert(eb1.getNrPages() == 500);
	eb1.setYear(2019);
	assert(eb1.getYear() == 2019);
	eb1.setPublishing_house("Publishing house 1");
	assert(eb1.getPublishing_house() == "Publishing house 1");
}
/*
void Tests::runRepoTests()
{
	cout << "Start repository tests.\n";

	BookRepo repo;

	// addBook Tests
	assert(repo.get_all().size() == 0);

	Book b1{ 1,10, "Title1", "Author1", "ACTION"};
	repo.addBook(&b1);
	assert(repo.get_all().size() == 1);

	Book b2{ 45,40, "Title2", "Author2", "COMIC"};
	repo.addBook(&b2);
	assert(repo.get_all().size() == 2);

	Book b3{ 21,78, "Title3", "Author3", "HORROR"};
	repo.addBook(&b3);
	assert(repo.get_all().size() == 3);

	Book b4{ 56,99, "Title4", "Author4", "BIOGRAPHIES"};
	repo.addBook(&b4);
	assert(repo.get_all().size() == 4);

	// modifyBook Test
	repo.modify(1, 50);
	assert(repo.get_all().at(0).getID() == 1);
	assert(repo.get_all().at(0).getPrice() == 50);
	assert(repo.get_all().at(0).getTitle() == "Title1");
	assert(repo.get_all().at(0).getAuthor() == "Author1");
	assert(repo.get_all().at(0).getType() == "ACTION");

	repo.modify(45, 200);
	assert(repo.get_all().at(1).getPrice() == 200);

	repo.modify(21, 100);
	assert(repo.get_all().at(2).getPrice() == 100);

	repo.modify(56, 300);
	assert(repo.get_all().at(3).getPrice() == 300);


	// removeBook Test
	repo.remove(45);
	assert(repo.get_all().size() == 3);

	repo.remove(1);
	assert(repo.get_all().size() == 2);

	repo.remove(56);
	assert(repo.get_all().size() == 1);
}
/*
void Tests::runCtrlTests()
{
	cout << "Start dontroller tests.\n";
	BookRepo repo;
	BookController ctrl{};
}
*/
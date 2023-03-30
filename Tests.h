#pragma once
#include "Book.h"
#include "AudioBook.h"
#include "EBook.h"
#include "BookRepo.h"
#include "BookController.h"
#include "BookUI.h"

class Tests
{
public:
	void runAllTests();
		
private:
	void runDomainTests();
	void runRepoTests();
	//void runCtrlTests();

};
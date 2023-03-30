#include "AudioBook.h"

AudioBook::AudioBook(int a_id, int a_price, string a_title, string a_author, string a_type, int a_time, string a_reader_name, Voice a_voice) :
	Book(a_id, a_price, a_title, a_author, a_type), time{a_time}, reader_name{a_reader_name}, voice{a_voice}
{
	// constructor a unei subclase a lui Book
	this->time = a_time;
	this->reader_name = a_reader_name;
	this->voice = a_voice;
}

string AudioBook::toString()
{
	string str;
	str += Book::toString();
	// str += " the duration is " + std::to_string(time) + " and is " + std::to_string(voice) + " with name" + reader_name;
	str += " the duration is " + std::to_string(time) + " and is voice ???  " + " with name" + reader_name;
	return str;
}

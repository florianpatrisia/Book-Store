#pragma once
#include "Book.h"
enum class Voice
{
	WOMAN,
	MAN,
	CHILD
};

class AudioBook :public Book {
public:
	AudioBook(int a_id, int a_price, string a_title, string a_author, string a_type, int a_time, string a_reader_name, Voice a_voice);
	AudioBook() = default;

	// getters
	inline int getTime() const { return time; }
	inline string getReader_name() const { return reader_name; }
	inline Voice getVoice() const { return voice; }

	// setters
	inline void setTime(int a_time) { this->time = a_time; }
	inline void setReader_name(string a_reader_name) { this->reader_name = a_reader_name; }
	inline void setVoice(Voice a_voice) { this->voice = a_voice; }

	string toString() override;
private:
	int time;
	string reader_name;
	Voice voice;
};
#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Answer
{
private:
	string textAnswer;
	bool correct;

public:
	Answer();
	Answer(string textAnswer, bool correct);

	bool getCorrect() const;
	string getTextAnswer() const;

	void setCorrect(bool correct);
	bool setTextAnswer(string textAnswer);

	void print();

	~Answer();
};
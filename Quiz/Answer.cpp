#include "Answer.h"

Answer::Answer()
{
	textAnswer = "";
	correct = false;
}

Answer::Answer(string textAnswer, bool correct)
{
	this->textAnswer = textAnswer;
	this->correct = correct;
}

bool Answer::getCorrect() const
{
	return this->correct;
}

string Answer::getTextAnswer() const
{
	return this->textAnswer;
}

void Answer::setCorrect(bool correct)
{
	this->correct = correct;
}

bool Answer::setTextAnswer(string textAnswer)
{
	this->textAnswer = textAnswer;
	return true;
}

void Answer::print()
{
	cout << " # " << this->textAnswer << endl;
}
Answer::~Answer()
{

}

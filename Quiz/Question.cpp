#include "question.h"

Question::Question()
{
	this->textQuestion = "";
}

Question::Question(string textQuestion)
{
	this->textQuestion = textQuestion;
}

void Question::printAnswers()
{
	for (Answer item : this->listAnswer)
		item.print();
}

bool Question::setTextQuestion(string textQuestion)
{
	this->textQuestion = textQuestion;
	return true;
}

string Question::getTextQuestion() const
{
	return this->textQuestion;
}

size_t Question::getCountOfAnswers() const
{
	return this->listAnswer.size();
}

bool Question::checkAnswer(size_t indexAnswer)
{
	size_t index = 1;
	for (Answer item : this->listAnswer)
	{
		if (index == indexAnswer)
			return item.getCorrect();
		index++;
	}
}

void Question::print()
{
	cout << this->textQuestion << endl;
	printAnswers();
}
void Question::addAnswer(Answer newAnswer)
{
	this->listAnswer.push_back(newAnswer);
}

void Question::deleteAnswer(size_t index)
{
	auto iter = this->listAnswer.begin();

	for (size_t i = 0; i < index; i++)
		iter++;

	this->listAnswer.erase(iter);

}

Question::~Question()
{

}
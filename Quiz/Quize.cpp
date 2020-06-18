#include <iostream>
#include <List>
#include "Quize.h"
using namespace std;

Quize::Quize()
{
	this->title = "";
}
Quize::Quize(string title)
{
	this->title = title;
}

void Quize::setTitle(string title)
{
	this->title = title;
}

string Quize::getTitle()const
{
	return this->title;
}

void Quize::print()
{
	cout << "You pass quize: " << this->title << endl;
}

void Quize::addQuestion(Question newQuestion)
{
	this->listQuestion.push_back(newQuestion);
}

void Quize::addAnswer(size_t index, Answer answer)
{
	size_t count = 0;

	for (Question& item : this->listQuestion)
	{
		if (count == index)
			item.addAnswer(answer);

		count++;
	}
}

void Quize::deleteAnswer(size_t index, size_t answerIndex)
{
	size_t count = 0;

	for (Question& item : this->listQuestion)
	{
		if (count == index)
			item.deleteAnswer(index);

		count++;
	}
}

bool Quize::checkQuestion(int indexQuestion, int indexAnswer)
{
	size_t index = 1;

	for (Question item : listQuestion)
	{
		if (index == indexQuestion)
		{
			return item.checkAnswer(indexAnswer);
			break;
		}
		index++;
	}
}

void Quize::passQuize()
{
	size_t score = 0;
	this->print();

	size_t i = 1;

	for (Question item : listQuestion)
	{
		size_t select_answer = 0;
		item.print();
		cout << "Enter answer the question: ";
		cin >> select_answer;

		bool isCheck = checkQuestion(select_answer, i);
		if (isCheck == true)
			score++;

		++i;
	}

	cout << "Score: " << score << "/" << i - 1 << endl;
}

Quize::~Quize()
{
}

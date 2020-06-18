#pragma once
#include "Answer.h"
#include <list>
using std::list;

class Question
{
public:
	Question();
	Question(string textQuestion);

	void printAnswers();
	void print();

	bool setTextQuestion(string textQuestion);
	string getTextQuestion() const;
	size_t getCountOfAnswers() const;

	//check answer
	bool checkAnswer(size_t indexAnswer);
	//add answer
	void addAnswer(Answer newAnswer);
	void deleteAnswer(size_t index);
	~Question();

private:
	string textQuestion;
	list<Answer> listAnswer;

};

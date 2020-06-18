#include "Question.h"
#include <string>

class Quize
{
public:
	Quize();
	Quize(string title);

	void setTitle(string title);
	string getTitle()const;

	void print();

	void addQuestion(Question newQuestion);
	void addAnswer(size_t index, Answer answer);
	void deleteAnswer(size_t index, size_t answerIndex);
	bool checkQuestion(int indexQuestion, int indexAnswer);
	void passQuize();

	//Menu - Quize
	static void Menu();

	~Quize();
private:
	string title;
	list<Question> listQuestion;

	//show main menu
	static void ShowMainMenu();
	//show edit menu
	static void ShowEditMenu();

	//edit menu functions
	static void EditMenu(Quize& quize);
	//main menu functions
	static void MainMenu(Quize* quize, size_t& size);

	//add question to quize
	static void AddQuestion(Quize& quize);
	//add answer to question
	static void AddAnswerToQuestion(Quize& quize);

	//remove answer from question
	static void RemoveAnswerFromQuestion(Quize& quize);
	//remove question from quize
	static void RemoveQuestion(Quize& quize);

	//add quize to quize arr
	static Quize* AddQuize(Quize* quize, size_t& size, bool master);
	//remove quize from quize arr
	static Quize* RemoveQuize(Quize* quize, size_t& size, size_t index);

	//quize master - add many questions with answers
	static void QuizeMaster(Quize* newQuize, size_t size);

	static void Clear();
};
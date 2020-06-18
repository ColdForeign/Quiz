#include "Quize.h"

void Quize::Menu()
{
	Quize* quize = nullptr;
	size_t size = 0;
	MainMenu(quize, size);
}

void Quize::ShowMainMenu()
{
	cout << "1 - Add test\n";
	cout << "2 - Add test with master\n";
	cout << "3 - Delete test\n";
	cout << "4 - Edit\n";
	cout << "5 - Print\n";
	cout << "0 - Exit\n";
}

void Quize::ShowEditMenu()
{
	cout << "1 - Add question\n";
	cout << "2 - Delete question\n";
	cout << "3 - Add answer to question\n";
	cout << "4 - Remove anwser from question\n";
	cout << "0 - Go back\n";
}

void Quize::MainMenu(Quize* quize, size_t& size)
{
	bool menuWork = true;
	char choise;
	bool correct = false;
	size_t index;
	do
	{
		ShowMainMenu();

		cout << "Enter your choise: ";
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case '0':
			menuWork = false;
			exit(0);
			break;
		case '1':
			quize = AddQuize(quize, size, false);
			break;
		case '2':
			quize = AddQuize(quize, size, true);
			break;
		case '3':
			if (size > 0)
			{
				cout << "Enter quize index from 0 to " << size - 1 << ":\n";
				do
				{
					cin >> index;
					if (index < 0 || index > size - 1)
					{
						cout << "Error enter quize index again: \n";
						correct = false;
					}
					else
						correct = true;
				} while (!correct);

				quize = RemoveQuize(quize, size, index);
			}
			else
				cout << "Please add quize, than delete\n";
			break;
		case '4':
			if (size > 0)
			{
				correct = false;
				cout << "Enter quize index from 0 to " << size - 1 << ":\n";
				do
				{
					cin >> index;

				} while (!correct);

				EditMenu(quize[index]);
			}
			else
				cout << "Please add quize, than edit\n";
			break;
		case '5':
			if (size > 0)
			{
				correct = false;
				cout << "Enter quize index from 0 to " << size - 1 << ":\n";
				do
				{
					cin >> index;
					if (index == -1)
						break;
					if (index < 0 || index > size - 1)
					{
						cout << "Error enter quize index again: \n";
						correct = false;
					}
					else
						correct = true;
				} while (!correct);

				quize[index].print();
			}
			else
				cout << "Please add quize, than print\n";
			break;
		}
	} while (menuWork);
}

void Quize::EditMenu(Quize& quize)
{
	bool menuWork = true;
	char choise;

	do
	{
		ShowEditMenu();

		cout << "Enter your choise: ";
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case '0':
			menuWork = false;
			break;
		case '1':
			AddQuestion(quize);
			break;
		case '2':
			RemoveQuestion(quize);
			break;
		case '3':
			AddAnswerToQuestion(quize);
			break;
		case '4':
			RemoveAnswerFromQuestion(quize);
			break;
		}
	} while (menuWork);

}

void Quize::AddQuestion(Quize& quize)
{
	Question question;
	string text;

	do
	{
		Clear();

		cout << "Enter question text: \n";
		getline(cin, text);

	} while (!cin.good());

	question.setTextQuestion(text);
	quize.addQuestion(question);
}

void Quize::AddAnswerToQuestion(Quize& quize)
{
	if (quize.listQuestion.size() > 0)
	{
		Answer answer;
		string text;
		bool correct = false;
		do
		{
			Clear();
			cout << "Enter answer text: ";
			getline(cin, text);
		} while (!answer.setTextAnswer(text));

		text = "";
		cout << "Is this answer correct? (enter yes or no): \n";
		do
		{
			Clear();

			cin >> text;
			if (text != "no" && text != "yes")
			{
				cout << "Error, enter again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		if (text == "yes")
			answer.setCorrect(true);
		else
			answer.setCorrect(false);

		size_t index;
		correct = false;
		cout << "Enter question index from 0 to " << quize.listQuestion.size() - 1 << ": \n";
		do
		{

			cin >> index;
			if (index < 0 || index > quize.listQuestion.size() - 1)
			{
				cout << "Error, enter question index again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		quize.addAnswer(index, answer);
	}
	else
		cout << "List empty\n";
}

void Quize::RemoveAnswerFromQuestion(Quize& quize)
{
	if (quize.listQuestion.size() > 0)
	{
		size_t index;
		size_t answerIndex;
		bool correct = false;

		cout << "Enter question index from 0 to " << quize.listQuestion.size() - 1 << ": \n";
		do
		{
			cin >> index;
			if (index < 0 || index > quize.listQuestion.size() - 1)
			{
				cout << "Error, enter question index again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		size_t count = 0;
		size_t lenght = 0;

		for (Question& item : quize.listQuestion)
		{
			if (count == index)
				lenght = item.getCountOfAnswers();

			count++;
		}

		correct = false;
		cout << "Enter answer index from 0 to " << lenght - 1 << ": \n";
		do
		{

			cin >> answerIndex;
			if (answerIndex < 0 || answerIndex > lenght - 1)
			{
				cout << "Error, enter answer index again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		quize.deleteAnswer(index, answerIndex);
	}
	else
		cout << "List empty\n";
}

void Quize::RemoveQuestion(Quize& quize)
{
	if (quize.listQuestion.size() > 0)
	{
		size_t index;
		bool correct = false;

		cout << "Enter question index from 0 to " << quize.listQuestion.size() - 1 << ": \n";
		do
		{
			Clear();

			cin >> index;
			if (index < 0 || index > quize.listQuestion.size() - 1)
			{
				cout << "Error, enter question index again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		auto iter = quize.listQuestion.begin();

		for (size_t i = 0; i < index; i++)
			iter++;

		quize.listQuestion.erase(iter);
	}
	else
		cout << "Quize empty\n";
}


Quize* Quize::AddQuize(Quize* quize, size_t& size, bool master)
{
	Quize* newQuize = new Quize[size + 1];

	for (size_t i = 0; i < size; i++)
		newQuize[i] = quize[i];

	string text;
	Clear();
	cout << "Enter quize title: ";
	getline(cin, text);

	newQuize[size].setTitle(text);

	if (master)
		QuizeMaster(newQuize, size);

	delete[] quize;
	size++;
	return newQuize;
}

Quize* Quize::RemoveQuize(Quize* quize, size_t& size, size_t index)
{
	if (size > 0)
	{
		Quize* newQuize = new Quize[size - 1];

		size_t count = 0;
		for (size_t i = 0; i < size; i++)
			if (i != index)
				newQuize[count++] = quize[i];

		delete[] quize;
		size--;
		return newQuize;
	}
	return quize;
}

void Quize::QuizeMaster(Quize* newQuize, size_t size)
{
	size_t countOfQuestions;
	Question temp;
	string text;
	size_t count;
	bool correct;

	cout << "Enter count of questions: ";
	cin >> countOfQuestions;

	for (size_t i = 0; i < countOfQuestions; i++)
	{
		cout << "Enter question text: ";
		do
		{
			Clear();

			getline(cin, text);
		} while (!temp.setTextQuestion(text));

		correct = false;
		cout << "Enter count of answers: ";
		do
		{
			cin >> count;
			if (count < 0 && count > 10)
			{
				cout << "Error, enter count of answers again: \n";
				correct = false;
			}
			else
				correct = true;
		} while (!correct);

		Answer tempAnswer;
		for (size_t i = 0; i < count; i++)
		{
			do
			{
				Clear();
				cout << "Enter answer text: ";
				getline(cin, text);
			} while (!tempAnswer.setTextAnswer(text));

			text = "";
			correct = false;
			cout << "Is this answer correct? (enter yes or no): \n";
			do
			{
				Clear();
				cin >> text;
				if (text != "no" && text != "yes")
				{
					cout << "Error, enter count of answers again: \n";
					correct = false;
				}
				else
					correct = true;
			} while (!correct);

			if (text == "yes")
				tempAnswer.setCorrect(true);
			else
				tempAnswer.setCorrect(false);

			temp.addAnswer(tempAnswer);
		}

		newQuize[size].addQuestion(temp);
	}
}

void Quize::Clear()
{
	if (std::cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
	else
		cin.ignore(32767, '\n');
}
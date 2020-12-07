#include <iostream>
#include "../header/exam.hpp"
#include "../header/folder.hpp"
#include "../header/schedule.hpp"
#include "../header/Quiz.hpp"
#include "../header/MultipleChoiceQuiz.hpp"
#include "../header/TrueFalseQuiz.hpp"
#include "../header/FlashCard.hpp"
#include "../header/FlashCardList.hpp"
#include "../header/menu.hpp"

using namespace std;

int main() {
	Schedule* ExamHelper = new Folder("Home Directory");
	Menu* menu = new Menu(ExamHelper);
	menu->runExamHelper();

	return 0;
}

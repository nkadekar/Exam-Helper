#ifndef _EXAM_HPP
#define _EXAM_HPP

#include "schedule.hpp"
#include "FlashCardList.hpp"
#include "Quiz.hpp"
#include "MultipleChoiceQuiz.hpp"
#include "TrueFalseQuiz.hpp"

#include <string>
#include <vector>

using namespace std;

class Exam : public Schedule {
    private:
        string type;
        string name;
        string date;
        FlashCardList *set;
        Quiz *newQuiz;

    public:
        Exam(string name, string date) : Schedule(name) {
            this->name = name;
            this->date = date;
            set = new FlashCardList();
            newQuiz = nullptr;
            this->type = "Exam";
        }

        string getType() {
            return this->type;
        }

        void renameExam(string newName) {
            this->name = newName;
        }

        void changeDate(string newDate) {
            this->date = newDate;
        }

        string displayFlashCards() {
            return set->displayFlashCards();
        }

        void addFlashCards(string term, string definition) {
            set->addFlashCard(term, definition);
        }

        void removeFlashCards(int index) {
            set->removeFlashCard(index);
        }

        void editFlashcards(string term, string definition, int index) {
            set->changeFlashCard(term, definition, index);
        }

        void startQuiz() {
            newQuiz->runQuiz();
        }

        void setQuizMultipleChoice() {
            newQuiz = new MultipleChoiceQuiz(set);
        }

        void setQuizTrueFalse() {
            newQuiz = new TrueFalseQuiz(set);
        }

        string getName() {
            return this->name;
        }

        string getDate() {
            return this->date;
        }
};

#endif // _EXAM_HPP_

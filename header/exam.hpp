#ifndef _EXAM_HPP
#define _EXAM_HPP

#include "header/Schedule.hpp"
#include "header/FlashCardList.hpp"
#include <string>
#include <vector>

using namespace std;

class Exam : public Schedule {
    private:
        string name;
        string date;
        int id;
        FlashCardList *set;
        Quiz *newQuiz;

    public:
        Exam(string name, string date) {
            this->name = name;
            this->date = date;
            set = new FlashCardList();
            newQuiz = nullptr;
        }

        void renameExam(string newName) {
            this->name = newName;
        }

        void changeDate(string newDate) {
            this->date = newDate;
        }

        void displayFlashcards() {
            set->displayFlashCards();
        }

        void addFlashCards() {
            set->addFlashCard();
        }

        void importFlashCards() {
            set->importFlashCards();
        }

        void startQuiz(Flashcard* set) {
            newQuiz->runQuiz();
        }

        void setQuizMultipleChoice() {
            newQuiz = new MultipleChoiceQuiz(set);
        }

        void setQuizFillIn() {
            newQuiz = new FillInQuiz(set);
        }

        string getName() {
            return this->name;
        }

        string getDate() {
            return this->date;
        }

        int getID() {
            return this->id;
        }
};

#endif // _EXAM_HPP_
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

        virtual ~Exam(){}

        virtual string getType() {
            return this->type;
        }

        virtual void renameExam(string newName) {
            this->name = newName;
        }

        virtual void changeDate(string newDate) {
            this->date = newDate;
        }

        virtual string displayFlashCards() {
            return set->displayFlashCards();
        }

        virtual void addFlashCards(string term, string definition) {
            set->addFlashCard(term, definition);
        }

        virtual void removeFlashCards(int index) {
            set->removeFlashCard(index);
        }

        virtual void editFlashcards(string term, string definition, int index) {
            set->changeFlashCard(term, definition, index);
        }

        virtual void startQuiz() {
            if (newQuiz != nullptr){
                newQuiz->runQuiz();
            }
        }

        virtual void setQuizMultipleChoice() {
            newQuiz = new MultipleChoiceQuiz(set);
        }

        virtual void setQuizTrueFalse() {
            newQuiz = new TrueFalseQuiz(set);
        }

        virtual string getName() {
            return this->name;
        }

        virtual string getDate() {
            return this->date;
        }

        virtual int FlashcardSetSize(){
            return set->size();
        }
};

#endif // _EXAM_HPP_

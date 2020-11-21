//Abstract Strategy
#ifndef QUIZ_HPP
#define QUIZ_HPP

#include "FlashCard.hpp"
#include "FlashCardList.hpp"

using namespace std;

class Quiz {
    protected:
        FlashCardList* set = nullptr;

    public:
        Quiz(FlashCardList* set){
            this->set = set;
        }
        
        virtual void runQuiz() = 0;

        //For testing of constructor
        FlashCardList* getSet(){
            return set;
        }
};

#endif
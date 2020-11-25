#ifndef MULTIPLECHOICEQUIZ_HPP
#define MULTIPLECHOICEQUIZ_HPP

#include "Quiz.hpp"
#include <iostream>

class MultipleChoiceQuiz: public Quiz {
    public: 
        MultipleChoiceQuiz(FlashCardList* set) : Quiz(set){};

        virtual void runQuiz() {
            char input;
            cin >> input;
            validateInput(input);
            while (input != 'q' || input != 'Q'){
                //Algorithm goes within the while loop
            }
        }

    private:
        void validateInput(char& input){
            while (input != 'q' || input != 'Q' || input != 'a' || input != 'A' || input != 'b' || input != 'B' || input != 'c' || input != 'C' || input != 'd' || input != 'D'){
                cin >> input;
            }
        }
};

#endif

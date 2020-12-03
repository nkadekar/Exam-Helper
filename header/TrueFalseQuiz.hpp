#ifndef TRUEFALSEQUIZ_HPP
#define TRUEFALSEQUIZ_HPP

#include "Quiz.hpp"
#include "FlashCardList.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

class TrueFalseQuiz: public Quiz {
    public: 
        TrueFalseQuiz(FlashCardList* set) : Quiz(set){};

        virtual bool runQuiz() {
            //checking edge cases
            if (this->set->size() == 0){
                cout << "This Flashcard set is empty." << endl;
                return false;
            }
            if (this->set->size() < 2){
                cout << "Flashcard set must have at least 2 Flashcards to take a quiz." << endl;
                return false;
            }
            bool run = true;
            int counter = 1;
            //main while loop for the quiz
            while (checkAllFlashCardsUsed()){
                cout << counter << ". ";
                char answerUpper = generateNewQuestion(); //generates new question and stores the answer of the question
                char answerLower = answerUpper + 32;
                char input;
                cout << "Type 'T' for True or 'F' for False. Press Q to exit the quiz." << endl;
                cin >> input;
                validateInput(input);
                if (input == 'q' || input == 'Q'){
                    resetFlashcards();
                    return true;
                }
                if (input == answerUpper || input == answerLower){
                    cout << "Correct!" << endl;
                }
                else {
                    cout << "Incorrect! The answer was " << answerUpper << "." << endl;
                }
                counter++;
                cout << endl; //To make the program look nice on the console
            }
            cout << "You have completed this set!" << endl;
            resetFlashcards();
            return true;
        }

        void validateInput(char& input){
            char temp = input;
            while (input != 'q' && input != 'Q' && input != 't' && input != 'T' && input != 'f' && input != 'F'){
                cout << "Your input is invalid. Try again" << endl;
                cin >> input;
            }
            return;
        }

        template <class T>
        inline bool findInVec(vector<T>& v, T key){
            for (int i = 0; i < v.size(); i++){
                if (v.at(i) == key){
                    return true;
                }
            }
            return false;
        }

        bool checkAllFlashCardsUsed(){
            for (int i = 0; i < set->size(); i++){
                if (set->at(i)->getUsed() == false){
                    return true;
                }
            }
            return false;
        }

        char generateNewQuestion(){
            srand(time(NULL));
            vector<int> usedIndex;
            int randTermIndex = rand() % set->size();
            while(set->at(randTermIndex)->getUsed() == true){ //makes sure its not used
                randTermIndex = rand() % set->size();
            }
            set->at(randTermIndex)->setUsedToTrue(); //changes object element "used"
            usedIndex.push_back(randTermIndex); //pushes term into usedIndex vector
            cout << set->at(randTermIndex)->getTerm();
            int randomAnswerPosition = rand() % 2; //0-F, 1-T, This is for position for correct answer
            if (randomAnswerPosition == 1){
                cout << " is " << set->at(randTermIndex)->getDefinition() << endl;
            }
            else {
                int randomIndex = rand() % set->size(); //picks random definition to display as dummy answer choice
                    while(findInVec(usedIndex, randomIndex)){ //checks to make sure index not already used
                        randomIndex = rand() % set->size();
                    }
                    usedIndex.push_back(randomIndex); //pushes index into usedIndex vector
                    cout << " is " << set->at(randomIndex)->getDefinition() << endl;
                }
            if (randomAnswerPosition == 1){
                return 84;
            }
            else {
                return 70;
            }
        }

        void resetFlashcards(){
            for (int i = 0; i < set->size(); i++){
                if (set->at(i)->getUsed() == true){
                    set->at(i)->setUsedToTrue();
                }
            }
        }
};

#endif
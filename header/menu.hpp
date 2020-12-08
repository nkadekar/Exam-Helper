#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>
#include <climits>

#include "exam.hpp"
#include "schedule.hpp"
#include "folder.hpp"
#include "FlashCard.hpp"
#include "FlashCardList.hpp"
#include "MultipleChoiceQuiz.hpp"
#include "Quiz.hpp"
#include "TrueFalseQuiz.hpp"

using namespace std;

class Menu {
    private:
        Schedule* curr;
        Quiz* currQuiz;

    public:
        Menu(Schedule* ExamHelper) {
            curr = ExamHelper;
            currQuiz = nullptr;
        }

        void runExamHelper() {
            while (curr->getType() == "Folder") {
                folderMenu();
            }

            while (curr->getType() == "Exam") {
                examMenu();
            }
        }

        void printFolderMenu() {
            cout << curr->getName() << endl;
            cout << "-----------------------------" << endl
                 << "a - Display Contents" << endl
                 << "b - Explore Contents" << endl
                 << "c - Add Folder" << endl
                 << "d - Delete Folder/Exam" << endl
                 << "e - Rename Folder" << endl
                 << "f - Add Exam" << endl
                 << "q - Exit Exam Helper" << endl
                 << "-----------------------------" << endl << endl
                 << "Choose an option: ";
        }

        void printExamMenu() {
            cout << endl << curr->getName() << " - "
                 << "Exam Date: " << curr->getDate() << endl;
            cout << "-----------------------------" << endl
                 << "a - Rename Exam" << endl
                 << "b - Change Exam Date" << endl
                 << "c - Practice Quizzes" << endl
                 << "d - Display Flashcards" << endl
                 << "e - Add a Flashcard" << endl
                 << "f - Delete a Flashcard" << endl
                 << "g - Edit a Flashcard" << endl
                 << "q - Exit Exam Helper" << endl
                 << "-----------------------------" << endl << endl
                 << "Choose an option: ";
        }

        bool checkChoice(int choice) {
            if (choice > curr->getSize() || choice < 1) {
                return false;
            }
            else {
                return true;
            }
        }

        bool checkFlashCardChoice(int choice) {
            if (choice > curr->FlashcardSetSize() || choice < 1) {
                return false;
            }
            else {
                return true;
            }
        }
        
        void folderMenu() {
            char input;
            printFolderMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && input != 'C' &&
                   input != 'd' && input != 'D' && input != 'e' && input != 'E' && input != 'f' && input != 'F' &&
                   input != 'q' && input != 'Q') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }
            
            // a - Display Contents
            if (input == 'a' || input == 'A') {
                if (curr->getSize() == 0){
                    cout << "This folder is empty." << endl;
                }
                else{
                    cout << "Contents in this folder: " << endl << endl;
                    curr->print();
                }
                cout << endl;
            }
            // b - Explore Contents
            else if (input == 'b' || input == 'B') {
                if (curr->getSize() == 0){
                    cout << "This folder is empty." << endl;
                }
                else{
                    int choice;
                    curr->print();
                    cout << endl << "Enter Folder/Exam to Explore: ";
                    cin >> choice;

                    // Check choice if valid
                    while (checkChoice(choice) == false) {
                        cout << "Invalid Number." << endl
                             << "Enter the number of the folder you want to explore: ";
                        cin >> choice;
                    }

                    curr = curr->at(choice - 1);
                }
            }
            // c - Add Folder
            else if (input == 'c' || input == 'C') {
                string folderName;
                string junk;
                cout << "Enter the name of your new folder: ";
                getline(cin, junk); //to set up the buffer for getline
                getline(cin, folderName);
                cout << endl;
                curr->addChildFolder(folderName);
            }
            // d - Remove Folder/Exam
            else if (input == 'd' || input == 'D') {
                if (curr->getSize() == 0) {
                    cout << "This folder is empty." << endl;
                }
                else {
                    int choice;
                    cout << "Contents in this folder: " << endl;
                    curr->print();
                    cout << endl << "Enter the number of the folder/exam you want to remove: ";
                    cin >> choice;
                    cout << endl;

                    // Check choice if valid
                    while (checkChoice(choice) == false) {
                        cout << "Invalid Number." << endl
                            << "Enter the number of the folder you want to remove: ";
                        cin >> choice;
                        cout << endl;
                    }

                    curr->removeChildFolder(choice - 1);
                }
            }
            // e - Rename Folder
            else if (input == 'e' || input == 'E') {
                int choice;
                string newName;
                string junk;
                getline(cin, junk); //to set up the buffer for getline
                cout << "Enter new folder name: ";
                getline(cin, newName);
                cout << endl;
                curr->renameCurrentFolder(newName);
            }
            // f - Add Exam
            else if (input == 'f' || input == 'F') {
                string name;
                string date;
                string junk;

                getline(cin, junk); //To set up the buffer for getline

                cout << "Enter exam name: ";
                getline(cin, name);
                cout << endl << "Enter exam date: ";
                getline(cin, date);
                cout << endl;
                curr->addChildExam(name, date);
            }
            // q - Exit exam helper
            else if (input == 'q' || input == 'Q') {
                cout << "Goodbye!" << endl;
                exit(0);
            }
        }

        void examMenu() {
            char input = ' ';
            printExamMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && input != 'C' &&
                   input != 'd' && input != 'D' && input != 'e' && input != 'E' && input != 'f' && input != 'F' &&
                   input != 'g' && input != 'G' && input != 'q' && input != 'Q') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }

            // a - Rename Exam
            if (input == 'a' || input == 'A') {
                string newName;
                string junk;
                getline(cin, junk); //to set up the buffer for newline
                cout << "Enter new Exam name: ";
                getline(cin, newName);
                curr->renameExam(newName);
            }
            // b - Change Exam Date
            else if (input == 'b' || input == 'B'){
                string newDate;
                string junk;
                getline(cin, junk); //to set up the buffer for newline
                cout << "Enter new exam date: ";
                getline(cin, newDate);
                curr->changeDate(newDate);
            }
            // c - Practice Quizzes 
            else if (input == 'c' || input == 'C' ) {
                int quizInput;
                cout << "Which practice quiz would you like to take?" << endl
                     << "1 - Multiple Choice" << endl
                     << "2 - True / False" << endl
                     << endl
                     << "Choose an option: ";
                cin >> quizInput;
                cout << endl;

                while (quizInput != 1 && quizInput != 2) {
                    cout << "Invalid Input. Choose an option: ";
                    cin >> quizInput;
                    cout << endl << endl;
                }

                cout << "QUIZ" << endl;

                if (quizInput == 1) {
                    curr->setQuizMultipleChoice();
                    curr->startQuiz();
                }
                else if (quizInput == 2) {
                    curr->setQuizTrueFalse();
                    curr->startQuiz();
                }
            }
            // d - Display Flashcards
            else if (input == 'd' || input == 'D') {
                cout << curr->displayFlashCards();
            }
            // e - Add a Flashcard
            else if (input == 'e' || input == 'E') {
                string term;
                string definition;
                string junk;

                getline(cin, junk); //to set up the buffer for newline

                cout << "Enter term: ";
                getline(cin, term);
                cout << endl;

                cout << "Enter definition: ";
                getline(cin, definition);
                curr->addFlashCards(term, definition);
            }
            // f - Delete a Flashcard
            else if (input == 'f' || input == 'F') {
                int index;
                if (curr->FlashcardSetSize() == 0) {
                        cout << "This set is empty." << endl;
                }
                else {
                    cout << curr->displayFlashCards();
                    cout << "Enter index of flashcard to be removed: ";
                    cin >> index;

                    // Check choice if valid
                    while (checkFlashCardChoice(index) == false) {
                        cout << "Invalid Number." << endl
                            << "Enter the number of the Flashcard you want to remove: ";
                        cin >> index;
                        cout << endl;
                    }
                    
                    curr->removeFlashCards(index - 1);
                }
            }
            // g - Edit a Flashcard
            else if (input == 'g' || input == 'G') {
                int index;
                string newTerm;
                string newDefinition;

                if (curr->FlashcardSetSize() == 0) {
                    cout << "This set is empty." << endl;
                }
                else {
                    cout << curr->displayFlashCards();
                    cout << "Enter the index of term you want to edit : ";
                    cin >> index;
                    cout << endl;

                    // Check choice if valid
                    while (checkFlashCardChoice(index) == false) {
                        cout << "Invalid Number." << endl
                             << "Enter the number of the Flashcard you want to edit: ";
                        cin >> index;
                        cout << endl;
                    }

                    string junk;
                    getline(cin, junk); //to set up the buffer for newline

                    cout << "Enter new term name: ";
                    getline(cin, newTerm);
                    cout << endl;

                    cout << "Enter new definition: ";
                    getline(cin, newDefinition);
                    curr->editFlashCards(newTerm, newDefinition, index - 1);
                }
            }
            // h - Exit Exam Helper
            else if (input == 'q' || input == 'Q') {
                cout << "Goodbye!" << endl;
                exit(0);
            }
        }
};

#endif // _MENU_HPP_
#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>

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
        void runExamHelper() {
            while (curr->getType() == "Folder") {
                folderMenu();
            }

            while (curr->getType() == "Exam") {
                examMenu();
            }
        }

        void printFolderMenu() {
            cout << curr->getName();
            cout << "-----------------------------" << endl
                 << "a - Display Contents" << endl
                 << "b - Explore Contents" << endl
                 << "c - Add Folder" << endl
                 << "d - Delete Folder" << endl
                 << "e - Rename Folder" << endl
                 << "f - Add Exam" << endl
                 << "g - Delete Exam" << endl
                 << "h - Exit Exam Helper" << endl << endl
                 << "Choose an option: ";
        }

        void printExamMenu() {
            curr->getName();
            cout << endl << "Exam Date: " << curr->getDate() << endl;
            cout << "-----------------------------" << endl
                 << "a - Rename Exam" << endl
                 << "b - Change Exam Date" << endl
                 << "c - Practice Quizzes" << endl
                 << "d - Display Flashcards" << endl
                 << "e - Add a Flashcard" << endl
                 << "f - Delete a Flashcard" << endl
                 << "g - Edit a Flashcard" << endl
                 << "h - Exit Exam Helper" << endl << endl
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
            if (choice > curr->getSize() || choice < 1) {
                return false;
            }
            else {
                return true;
            }
        }
        
        void folderMenu() {
            char input = ' ';
            printFolderMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' || input != 'A' || input != 'b' || input != 'B' || input != 'c' || input != 'C' ||
                   input != 'd' || input != 'D' || input != 'e' || input != 'E' || input != 'f' || input != 'F' ||
                   input != 'g' || input != 'G' || input != 'h' || input != 'H') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }
            
            // a - Display Contents
            if (input == 'a' || input == 'A') {
                cout << "Contents in this folder: " << endl;
                curr->print();
            }
            // b - Explore Contents
            else if (input == 'b' || input == 'B') {
                cout << "Enter Folder/Exam to Explore: " << endl;
                curr->print();
            }
            // c - Add Folder
            else if (input == 'c' || input == 'C') {
                string folderName;
                cout << endl << "Enter the name of your folder: ";
                getline(cin, folderName);
                cout << endl;
                curr->addChildFolder(folderName);
            }
            // d - Remove Folder
            else if (input == 'd' || input == 'D') {
                int choice;
                cout << endl << "Contents in this folder: " << endl;
                curr->print();
                cout << endl << "Enter the number of the folder you want to remove: ";
                cin >> choice;
                cout << endl;

                // Check choice if valid
                while (checkChoice(choice) == false) {
                    cout << "Invalid Number." << endl
                         << "Enter the number of the folder you want to remove: ";
                    cin >> choice;
                    cout << endl;
                }

                curr->removeChildFolder(choice);
            }
            // e - Rename Folder
            else if (input == 'e' || input == 'E') {
                int choice;
                string newName;
                cout << endl << "Enter new folder name: ";
                getline(cin, newName);
                cout << endl;
                curr->renameCurrentFolder(newName);
            }
            // f - Add Exam
            else if (input == 'f' || input == 'F') {
                string name;
                string date;

                cout << endl << "Enter exam name: ";
                getline(cin, name);
                cout << endl << "Enter exam date: ";
                getline(cin, date);
                cout << endl;
                curr->addExam(name, date);
            }
            // g - Delete Exam
            else if (input == 'g' || input == 'G') {
                int choice;
                cout << "Enter the number of the exam you want to remove: ";
                cin >> choice;
                cout << endl;

                // Check choice if valid
                while (checkChoice(choice) == false) {
                    cout << "Invalid Number." << endl
                         << "Enter the number of the exam you want to remove: ";
                    cin >> choice;
                    cout << endl;
                }

                curr->removeChildExam(choice);
            }
            // h - Exit exam helper
            else if (input == 'h' || input == 'H') {
                cout << endl << "Goodbye!" << endl;
                exit(0);
            }
        }

        void examMenu() {
            char input = ' ';
            printExamMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' || input != 'A' || input != 'b' || input != 'B' || input != 'c' || input != 'C' ||
                   input != 'd' || input != 'D' || input != 'e' || input != 'E' || input != 'f' || input != 'F' ||
                   input != 'g' || input != 'G' || input != 'h' || input != 'H') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }

            // a - Rename Exam
            if (input = 'a' || input = 'A') {
                string newName;
                cout << endl << "Enter new Exam name: ";
                getline(cin, newName);
                cout << endl;
                curr->renameExam(newName);
            }
            // b - Change Exam Date
            else if (input = 'b' || input = 'B'){
                string newDate;
                cout << endl << "Enter new exam date: ";
                getline(cin, newDate);
                cout << endl;
                curr->changeDate(newDate);
            }
            // c - Practice Quizzes 
            else if (input == 'c' || input == 'C' ) {
                int quizInput;
                cout << endl << "Which practice quiz would you like to take?" << endl
                     << "1 - Multiple Choice" << endl
                     << "2 - True / False" << endl
                     << endl
                     << "Choose an option: ";
                cin >> quizInput;
                cout << endl;

                while (quizInput != 1 || quizInput != 2) {
                    cout << "Invalid Input. Choose an option: ";
                    cin >> quizInput;
                    cout << endl << endl;
                }

                if (quizInput == 1) {
                    currQuiz->setQuizMultipleChoice();
                    currQuiz->startQuiz();
                }
                else if (quizInput == 2) {
                    currQuiz->setQuizTrueFalse();
                    currQuiz->startQuiz();
                }
            }
            // d - Display Flashcards
            else if (input == 'd' || input == 'D') {
                curr->displayFlashCards();
            }
            // e - Add a Flashcard
            else if (input == 'e' || input == 'E') {
                string term;
                string definition;

                cout << endl << "Enter term: ";
                getline(cin, term);
                cout << endl;

                cout << "Enter definition: ";
                getline(cin, definition);
                cout << endl;
                curr->addFlashCard(term, definition)
            }
            // f - Delete a Flashcard
            else if (input == 'f' || input == 'F') {
                int index;
                cout << endl << "Enter index of flashcard to be removed: ";
                cin >> index;
                cout << endl;
                curr->removeFlashCard(index);
            }
            // g - Edit a Flashcard
            else if (input == 'g' || input 'G') {
                int index;
                string newTerm;
                string newDefinition;

                cout << endl << "Enter the index of term you want to edit : ";
                cin >> index;
                cout << endl;

                cout << "Enter new term name: ";
                getline(cin, newTerm);
                cout << endl;

                cout << "Enter new definition: ";
                getline(cin, newDefinition);
                cout << endl;
                changeFlashCard(newTerm, newDefinition, index);
            }
            // h - Exit Exam Helper
            else if (input == 'h' || input == 'H') {
                cout << endl << "Goodbye!" << endl;
                exit(0);
            }
        }
};

#endif // _MENU_HPP_
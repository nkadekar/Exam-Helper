//
//  schedule.h
//  Exam Helper
//
//  Created by Arlene Phimmasone on 11/21/20.
//

#ifndef schedule_hpp
#define schedule_hpp
#include <string>
#include <iostream>

using namespace std;

class Schedule {
protected:
    string name;

public: 
    Schedule(string name) : name(name) {}

    virtual string getName() = 0;

    virtual string getType() = 0;

    virtual void renameExam(string);
    
    virtual void changeDate(string);

    virtual string displayFlashCards();
    
    virtual void addFlashCards(string, string);
    
    virtual void removeFlashCards(int);

    virtual void editFlashCards(string, string, int);

    virtual void startQuiz();
    
    virtual void setQuizMultipleChoice();
    
    virtual void setQuizTrueFalse();
    
    virtual string getDate();
    
    virtual int getSize();

    virtual Schedule* at(int);
    
    virtual void addChildFolder(string);

    virtual void removeChildFolder(int);

    virtual void renameCurrentFolder(string);

    virtual void addChildExam(string, string);

    virtual void removeChildExam(int);
    
    virtual void print();

    virtual int FlashcardSetSize();
};

#endif /* schedule_hpp */

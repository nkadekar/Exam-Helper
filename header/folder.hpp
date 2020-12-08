//
//  folder.hpp
//  Exam Helper
//
//  Created by Arlene Phimmasone on 11/21/20.
//

#ifndef folder_hpp
#define folder_hpp
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "schedule.hpp"
#include "exam.hpp"

using namespace std;

//student enters name of course which then creates respective ID for the course
//student has the option to add or remove a course

class Folder : public Schedule {
private:
    vector<Schedule *> contents; //contents
    string type;

public:
    Folder(string name) : Schedule(name) {
        this->type = "Folder";
        this->name = name;
    }

    virtual ~Folder(){
        for (int i = 0; i < contents.size(); i++){
            delete contents.at(i);
        }
    }

    virtual string getType() {
        return this->type;
    }

    virtual string getName() {
        return this->name;
    }

    virtual int getSize() {
        return contents.size();
    }

    virtual Schedule *at(int index) {
        return contents.at(index);
    }

    virtual void addChildFolder(string newName) {
        contents.push_back(new Folder(newName));
    }

    virtual void removeChildFolder(int index) {
        delete contents.at(index);
        contents.erase(contents.begin() + index);
    }

    virtual void renameCurrentFolder(string newName) {
        this->name = newName;
    }

    virtual void addChildExam(string name, string date) {
        contents.push_back(new Exam(name, date));
    }

    virtual void removeChildExam(int index) {
        delete contents.at(index);
        contents.erase(contents.begin() + index);
    }

    virtual void print() {
        for (int i = 0; i < contents.size(); ++i) {
            cout << i + 1 << " - " << contents.at(i)->getType() << ": " << contents.at(i)->getName() << endl;
        }
    }
};

#endif // folder_hpp 

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
    protected:
        vector<Schedule* > contents; //contents
    
    public:
        Folder(string name, int ID) : Schedule(name, ID) { }

        string getName() {
            return this->name;
        }

        int getID() {
            return this->ID;
        }

        int getSize() {
            return contents.size();
        }

        Schedule *at(int index) {
            index = ID - 1;
            return contents.at(index);
        }

        void addFolder(string newName) {
            name = newName;
            ID = contents.size() + 1;

            contents.push_back(new Folder(name, ID));
        }

        void removeFolder(int index) {
            delete contents.at(index);
            contents.erase(contents.begin() + index);
        }

        void renameFolder(int ID, string edited) {
            int index = find(ID);
            contents.at(index)->setNewName(name);
        }
        
        int findID(int userID) {
            int indexVal;
            for(i = 0; i < getSize(); i++) {
                if(userID - 1 == i) {
                    indexVal = contents.at(i);
                    break;
                }
            }
            return indexVal;
        }

        void addExam(string name, string date) {
            contents.push_back(new Exam(name, date));
        }

        void removeExam(int id) {
            delete set.at(id);
            set.erase(set.begin() + id);
        }

        void editExam(string name, string date, int id) {
            int index = findID(id);
            if (name != "") {
                contents.at(index)->renameExam(name);
            }
            if (date != "") {
                contents.at(index)->changeDate(date);
            }
        }

        void setNewName(string newName) {
            this->name = newName;
        }

        void print() {
            for (int i = 0; i < v.size(); ++i) {
                cout << v.at(i)->getID() << " - " << v.at(i)->getName() << endl;g
            }
        }
};

#endif /* folder_hpp */
#ifndef FLASHCARDLIST_HPP
#define FLASHCARDLIST_HPP

#include "FlashCard.hpp"
#include <vector>
#include <sstream>

using namespace std;

class FlashCardList {
	private:
		vector<FlashCard*> set;
	
	public:
		FlashCardList(){};

		int size(){
			return set.size();
		}

		FlashCard* at(int index){
			return set.at(index);
		}

		void removeFlashCard(int index){
			delete set.at(index);
			set.erase(set.begin() + index);
		}

		void addFlashCard(string term, string definition){
			set.push_back(new FlashCard(term, definition));
		}

		string displayFlashCards(){
			stringstream inSS;
			inSS << "FLASHCARDS" << endl;
			if (set.empty()){
				inSS << "List is empty." << endl;
			}

			for (int i = 0; i < set.size(); i++){
				inSS << i + 1 << ". " << set.at(i)->getTerm() << " : " << set.at(i)->getDefinition() << endl;
			}
			return inSS.str();
		}

		void changeFlashCard(string term, string definition, int index){
			set.at(index)->changeTerm(term);
			set.at(index)->changeDefinition(definition);
		}
};

#endif
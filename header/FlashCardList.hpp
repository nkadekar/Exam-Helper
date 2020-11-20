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
		int size(){
			return set.size();
		}

		FlashCard* at(int i){
			return set.at(i);
		}

		void removeFlashCard(int i){
			delete set.at(i);
			set.erase(set.begin() + i);
		}

		void addFlashCard(string term, string definition){
			set.push_back(new FlashCard(term, definition));
		}

		string displayFlashCards(){
			stringstream inSS;
			inSS << "Flashcards" << endl;
			for (int i = 0; i < set.size(); i++){
				inSS << i + 1 << ". " << set.at(i)->getTerm() << " : " << set.at(i)->getDefinition() << endl;
				inSS << endl;
			}
			return inSS.str();
		}
};

#endif
#ifndef FLASHCARDLIST_HPP
#define FLASHCARDLIST_HPP

#include "FlashCard.hpp"
#include <vector>

using namespace std;

class FlashCardList {
	private:
		vector<FlashCard*> set;
	
	public:
		int size(){
			return set.size();
		}

		FlashCard* at(i){
			return set.at(i);
		}

		

};

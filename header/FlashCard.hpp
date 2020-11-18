#ifndef FLASHCARD_HPP
#define FLASHCARD_HPP

#include <string>

using namespace std;

class FlashCard {
	private:
		string term;
		string definition;
		bool used;

	public:
		FlashCard(string term, string definition) {
			this->term = term;
			this->definition = definition;
			this->used = false;
		}

		string getTerm(){
			return "";
		}

		string getDefinition(){
			return definition;
		}

		bool getUsed(){
			return used;
		}

		void setUsedToTrue(){
			this->used = true;
		}

		void setUsedToFalse(){
			this->used = false;
		}
};

#endif

#include "../header/Quiz.hpp"
#include "../header/TrueFalseQuiz.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){

    // // Test Case1: Completed the Test
	// FlashCardList* set = new FlashCardList();
	// set->addFlashCard("FCT1", "FCD1");
	// set->addFlashCard("FCT2", "FCD2");
	// set->addFlashCard("FCT3", "FCD3");
	// set->addFlashCard("FCT4", "FCD4");
	// Quiz* test = new MultipleChoiceQuiz(set);
	// test->runQuiz();

    //Should be "1111"
    // cout << set->at(0)->getUsed() << set->at(1)->getUsed() << set->at(2)->getUsed() << set->at(3)->getUsed() << endl;


    //Test Case 2: Pressed 'Q' to exit. Checking to see 3 '1' and 4 '0' in output.
    FlashCardList* set2 = new FlashCardList();
	set2->addFlashCard("FCT1", "FCD1");
	set2->addFlashCard("FCT2", "FCD2");
	set2->addFlashCard("FCT3", "FCD3");
	set2->addFlashCard("FCT4", "FCD4");
    set2->addFlashCard("FCT5", "FCD5");
    set2->addFlashCard("FCT6", "FCD6");
    set2->addFlashCard("FCT7", "FCD7");
	Quiz* test2 = new TrueFalseQuiz(set2);
	test2->runQuiz();

    cout << set2->at(0)->getUsed() << set2->at(1)->getUsed() << set2->at(2)->getUsed() << set2->at(3)->getUsed() << set2->at(4)->getUsed() << set2->at(5)->getUsed() << set2->at(6)->getUsed() << endl;


	return 0;
}

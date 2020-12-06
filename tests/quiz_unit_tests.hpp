#include "gtest/gtest.h"
#include "../header/Quiz.hpp"
#include "../header/MultipleChoiceQuiz.hpp"
#include "../header/TrueFalseQuiz.hpp"

TEST(MultipleChoiceQuizTest, EmptySet){
	FlashCardList* set = new FlashCardList();
	Quiz* test = new MultipleChoiceQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

TEST(MultipleChoiceQuizTest, SizeOneSet){
	FlashCardList* set = new FlashCardList();
	set->addFlashCard("FCT1", "FCD1");

	Quiz* test = new MultipleChoiceQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

TEST(MultipleChoiceQuizTest, SizeTwoSet){
	FlashCardList* set = new FlashCardList();
	set->addFlashCard("FCT1", "FCD1");
	set->addFlashCard("FCT2", "FCD2");
	Quiz* test = new MultipleChoiceQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

TEST(MultipleChoiceQuizTest, SizeThreeSet){
	FlashCardList* set = new FlashCardList();
	set->addFlashCard("FCT1", "FCD1");
	set->addFlashCard("FCT2", "FCD2");
	set->addFlashCard("FCT3", "FCD3");

	Quiz* test = new MultipleChoiceQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

TEST(TrueFalseQuizTest, EmptySet){
	FlashCardList* set = new FlashCardList();

	Quiz* test = new TrueFalseQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

TEST(TrueFalseQuizTest, SizeThreeSet){
	FlashCardList* set = new FlashCardList();
	set->addFlashCard("FCT1", "FCD1");

	Quiz* test = new TrueFalseQuiz(set);
	
	EXPECT_EQ(test->runQuiz(), false);
}

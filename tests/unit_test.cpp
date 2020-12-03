#include "gtest/gtest.h"

#include "../header/FlashCard.hpp"
#include "../header/FlashCardList.hpp"
#include "../header/Quiz.hpp"
#include "../header/MultipleChoiceQuiz.hpp"

//FlashCard Tests
TEST(FlashCardTest, ConstructorTest){
	FlashCard* test = new FlashCard("Test", "This is a test");
	
	EXPECT_EQ(test->getTerm(), "Test");
	EXPECT_EQ(test->getDefinition(), "This is a test");
	EXPECT_EQ(test->getUsed(), false);
}

TEST(FlashCardTest, UsedSetterFunctions){
	FlashCard* test = new FlashCard("Test", "This is a test");
	
	EXPECT_EQ(test->getUsed(), false);

	test->setUsedToTrue();

	EXPECT_EQ(test->getUsed(), true);

	test->setUsedToTrue();

	EXPECT_EQ(test->getUsed(), true);

	test->setUsedToFalse();

	EXPECT_EQ(test->getUsed(), false);

	test->setUsedToFalse();

	EXPECT_EQ(test->getUsed(), false);
}

TEST(FlashCardTest, EmptyStrings){
	FlashCard* test = new FlashCard("", "");

	EXPECT_EQ(test->getTerm(), "");
	EXPECT_EQ(test->getDefinition(), "");
	EXPECT_EQ(test->getUsed(), false);
}

TEST(FlashCardTest, ChangeTerm){
	FlashCard* test = new FlashCard("", "");
	
	EXPECT_EQ(test->getTerm(), "");

	test->changeTerm("Test");

	EXPECT_EQ(test->getTerm(), "Test");
}

TEST(FlashCardTest, ChangeDefintion){
	FlashCard* test = new FlashCard("", "");

	EXPECT_EQ(test->getDefinition(), "");

	test->changeDefinition("This is a test");

	EXPECT_EQ(test->getDefinition(), "This is a test");
}

//FlashcardList Tests
TEST(FlashCardListTest, SizeTest_AddTest){
	FlashCardList* test = new FlashCardList();

	ASSERT_EQ(test->size(), 0);

	test->addFlashCard("Term1", "Definition1");
	test->addFlashCard("Term2", "Definition2");
	test->addFlashCard("Term3", "Definition3");

	EXPECT_EQ(test->size(), 3);
}

TEST(FlashCardListTest, SizeEmptyTest){
	FlashCardList* test = new FlashCardList();

	EXPECT_EQ(test->size(), 0);
}

TEST(FlashCardListTest, AddTest_AtTest){
	FlashCardList* test = new FlashCardList();
	test->addFlashCard("Term1", "Definition1");
	test->addFlashCard("Term2", "Definition2");

	ASSERT_EQ(test->size(), 2);
	EXPECT_EQ(test->at(0)->getTerm(), "Term1");
	EXPECT_EQ(test->at(1)->getTerm(), "Term2");
	EXPECT_EQ(test->at(0)->getDefinition(), "Definition1");
	EXPECT_EQ(test->at(1)->getDefinition(), "Definition2");
}

TEST(FlashCardListTest, RemoveFlashCardTest){
	FlashCardList* test = new FlashCardList();
	test->addFlashCard("Term1", "Definition1");
	test->addFlashCard("Term2", "Definition2");

	ASSERT_EQ(test->size(), 2);

	test->removeFlashCard(1);

	ASSERT_EQ(test->size(), 1);
	EXPECT_EQ(test->at(0)->getTerm(), "Term1");
	EXPECT_EQ(test->at(0)->getDefinition(), "Definition1");
}

TEST(FlashCardListTest, displayFlashCardsTest){
	FlashCardList* test = new FlashCardList();
	test->addFlashCard("Term1", "Definition1");
	test->addFlashCard("Term2", "Definition2");

	ASSERT_EQ(test->size(), 2);

	EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\n1. Term1 : Definition1\n2. Term2 : Definition2\n");
}

TEST(FlashCardListTest, EmptydisplayFlashCardsTest){
	FlashCardList* test = new FlashCardList();

	EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\nList is empty.\n");
}

TEST(FlashCardListTest, changeFlashCardTest){
	FlashCardList* test = new FlashCardList();
	test->addFlashCard("Term1", "Definition1");

	ASSERT_EQ(test->size(), 1);

	test->changeFlashCard("NewTerm1", "NewDefinition1", 0);

	ASSERT_EQ(test->size(), 1);
	EXPECT_EQ(test->at(0)->getTerm(), "NewTerm1");
	EXPECT_EQ(test->at(0)->getDefinition(), "NewDefinition1");
}

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

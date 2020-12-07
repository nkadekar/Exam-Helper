#include "gtest/gtest.h"
#include "../header/exam.hpp"

// Exam Tests
TEST(ExamTest, ConstructorTest) {
    Exam* test = new Exam("Midterm2", "12/06/20");

    EXPECT_EQ(test->getName(), "Midterm2");
    EXPECT_EQ(test->getDate(), "12/06/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, RenameTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->renameExam("Midterm02");

    EXPECT_EQ(test->getName(), "Midterm02");
}

TEST(ExamTest, ChangeDateTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->changeDate("12/07/20");

    EXPECT_EQ(test->getDate(), "12/07/20");
}

TEST(ExamTest, GetExamNameTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");

    EXPECT_EQ(test->getName(), "Midterm2");
}

TEST(ExamTest, GetDateTest) {
    Exam *test = new Exam("Midterm3", "12/07/20");

    EXPECT_EQ(test->getDate(), "12/07/20");
}

TEST(ExamTest, GetExamNameTest) {
    Exam *test = new Exam("Midterm4", "12/08/20");

    EXPECT_EQ(test->getType(), "Exam");
}

// FlashCard Tests
TEST(FlashCardListTest, DisplayFlashCardsTest) {
    FlashCardList *test = new FlashCardList();
    test->addFlashCard("Term1", "Definition1");
    test->addFlashCard("Term2", "Definition2");

    EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\n1. Term1 : Definition1\n2. Term2 : Definition2\n");
}

TEST(FlashCardListTest, AddFlashCardTest) {
    FlashCardList *test = new FlashCardList();
    test->addFlashCard("Term1", "Definition1");

    EXPECT_EQ(test->at(0)->getTerm(), "Term1");
    EXPECT_EQ(test->at(0)->getDefinition(), "Definition1");
}

TEST(FlashCardListTest, RemoveFlashCardTest) {
    FlashCardList *test = new FlashCardList();
    test->addFlashCard("Term1", "Definition1");
    test->addFlashCard("Term2", "Definition2");
    test->removeFlashCard(1);

    ASSERT_EQ(test->size(), 1);
    EXPECT_EQ(test->at(0)->getTerm(), "Term1");
    EXPECT_EQ(test->at(0)->getDefinition(), "Definition1");
}

TEST(FlashCardListTest, EditFlashCardTest) {
    FlashCardList *test = new FlashCardList();
    test->addFlashCard("Term1", "Definition1");
    test->changeFlashCard("NewTerm1", "NewDefinition1", 0);

    EXPECT_EQ(test->at(0)->getTerm(), "NewTerm1");
    EXPECT_EQ(test->at(0)->getDefinition(), "NewDefinition1");
}
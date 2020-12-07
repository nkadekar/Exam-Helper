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

TEST(ExamTest, GetTypeTest) {
    Exam *test = new Exam("Midterm4", "12/08/20");

    EXPECT_EQ(test->getType(), "Exam");
}

// FlashCard Tests
TEST(ExamFlashCardListTest, DisplayFlashCardsTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->addFlashCards("Term1", "Definition1");
    test->addFlashCards("Term2", "Definition2");

    EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\n1. Term1 : Definition1\n2. Term2 : Definition2\n");
}


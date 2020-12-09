#include "gtest/gtest.h"
#include "../header/exam.hpp"

// Exam Tests
TEST(ExamTest, ConstructorTestOne) {
    Exam *test = new Exam("Midterm1", "12/05/20");

    EXPECT_EQ(test->getName(), "Midterm1");
    EXPECT_EQ(test->getDate(), "12/05/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, ConstructorTestTwo) {
    Exam* test = new Exam("Midterm2", "12/06/20");

    EXPECT_EQ(test->getName(), "Midterm2");
    EXPECT_EQ(test->getDate(), "12/06/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, ConstructorTestThree) {
    Exam *test = new Exam("Midterm3", "12/07/20");

    EXPECT_EQ(test->getName(), "Midterm3");
    EXPECT_EQ(test->getDate(), "12/07/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, ConstructorTestFour) {
    Exam *test = new Exam("Midterm4", "12/08/20");

    EXPECT_EQ(test->getName(), "Midterm4");
    EXPECT_EQ(test->getDate(), "12/08/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, ConstructorTestFive) {
    Exam *test = new Exam("Midterm5", "12/09/20");

    EXPECT_EQ(test->getName(), "Midterm5");
    EXPECT_EQ(test->getDate(), "12/09/20");
    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, RenameTestOne) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->renameExam("Midterm02");

    EXPECT_EQ(test->getName(), "Midterm02");
}

TEST(ExamTest, RenameTestTwo) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->renameExam("Midterm-03");

    EXPECT_EQ(test->getName(), "Midterm-03");
}

TEST(ExamTest, RenameEmptyTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->renameExam("");

    EXPECT_EQ(test->getName(), "");
}

TEST(ExamTest, ChangeDateTestOne) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->changeDate("12/07/20");

    EXPECT_EQ(test->getDate(), "12/07/20");
}

TEST(ExamTest, ChangeDateTestTwo) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->changeDate("12/07/2020");

    EXPECT_EQ(test->getDate(), "12/07/2020");
}

TEST(ExamTest, ChangeEmptyDateTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->changeDate("");

    EXPECT_EQ(test->getDate(), "");
}

TEST(ExamTest, GetExamNameTest) {
    Exam *test = new Exam("Midterm2", "12/06/20");

    EXPECT_EQ(test->getName(), "Midterm2");
}

TEST(ExamTest, GetEmptyNameTest) {
    Exam *test = new Exam("", "12/07/20");

    EXPECT_EQ(test->getName(), "");
}

TEST(ExamTest, GetDateTest) {
    Exam *test = new Exam("Midterm3", "12/07/20");

    EXPECT_EQ(test->getDate(), "12/07/20");
}

TEST(ExamTest, GetEmptyDateTest) {
    Exam *test = new Exam("Midterm3", "");

    EXPECT_EQ(test->getDate(), "");
}

TEST(ExamTest, GetEmptyBothTest) {
    Exam *test = new Exam("", "");

    EXPECT_EQ(test->getName(), "");
    EXPECT_EQ(test->getDate(), "");
}

TEST(ExamTest, GetTypeTestOne) {
    Exam *test = new Exam("Midterm4", "12/08/20");

    EXPECT_EQ(test->getType(), "Exam");
}

TEST(ExamTest, GetTypeTestTwo) {
    Exam *test = new Exam("", "");

    EXPECT_EQ(test->getType(), "Exam");
}

// FlashCard Tests
TEST(ExamFlashCardListTest, DisplayFlashCardsTestOne) {
    Exam *test = new Exam("Midterm2", "12/06/20");
    test->addFlashCards("Term1", "Definition1");
    test->addFlashCards("Term2", "Definition2");

    EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\n1. Term1 : Definition1\n2. Term2 : Definition2\n");
}

TEST(ExamFlashCardListTest, DisplayFlashCardsTestTwo) {
    Exam *test = new Exam("Midterm1", "12/05/20");
    test->addFlashCards("T1", "D1");
    test->addFlashCards("T2", "D2");

    EXPECT_EQ(test->displayFlashCards(), "FLASHCARDS\n1. T1 : D1\n2. T2 : D2\n");
}

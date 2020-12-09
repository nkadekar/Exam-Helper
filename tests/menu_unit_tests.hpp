#include "gtest/gtest.h"
#include "../header/menu.hpp"

// Invalid Folder Inputs
TEST(MenuTest, InvalidFolderNegInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(-1));
}

TEST(MenuTest, InvalidFolderBigNegInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(-100));
}

TEST(MenuTest, InvalidFolderZeroInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(0));
}

TEST(MenuTest, InvalidFolderInputOne) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(5));
}

TEST(MenuTest, InvalidFolderInputTwo) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(100));
}

TEST(MenuTest, InvalidFolderInputThree) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(50));
}

TEST(MenuTest, InvalidFolderInputFour) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(3));
}

TEST(MenuTest, InvalidFolderInputFive) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(10));
}

// Invalid Flashcard Inputs
TEST(MenuTest, InvalidFlashCardNegInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(-1));
}

TEST(MenuTest, InvalidFlashCardBigNegInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(-100));
}

TEST(MenuTest, InvalidFlashCardZeroInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(0));
}

TEST(MenuTest, InvalidFlashCardInputOne) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(5));
}

TEST(MenuTest, InvalidFlashCardInputTwo) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(100));
}

TEST(MenuTest, InvalidFlashCardInputThree) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(90));
}

TEST(MenuTest, InvalidFlashCardInputFour) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(8));
}

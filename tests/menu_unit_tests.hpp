#include "gtest/gtest.h"
#include "../header/menu.hpp"

TEST(MenuTest, InvalidFolderInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);
    menu->runExamHelper();

    ASSERT_FALSE(menu->checkChoice(0));
}

TEST(MenuTest, InvalidFolderInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);
    menu->runExamHelper();

    ASSERT_FALSE(menu->checkFlashCardChoice(0));
}

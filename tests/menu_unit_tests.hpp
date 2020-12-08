#include "gtest/gtest.h"
#include "../header/menu.hpp"

TEST(MenuTest, InvalidFolderZeroInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkChoice(0));
}

TEST(MenuTest, InvalidFlashCardZeroInput) {
    Schedule *ExamHelper = new Folder("Home Directory");
    Menu *menu = new Menu(ExamHelper);

    ASSERT_FALSE(menu->checkFlashCardChoice(0));
}


#ifndef FOLDER_TESTS_HPP
#define FOLDER_TESTS_HPP

#include "../header/folder.hpp"
#include "gtest/gtest.h"

TEST(FolderTest, ConstructorTest) { 
    Folder test("testFolder");
    EXPECT_EQ(test.getName(), "testFolder"); 
}

TEST(FolderTest, addFolder) {
    Folder* test = new Folder("Winter Quarter");
    test->addChildFolder("CS100");
    test->addChildFolder("CS061");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
    EXPECT_EQ(test->at(1)->getName(), "CS061");
}

TEST(FolderTest, removeFolder) {
    Folder* test = new Folder("Winter quarter");
    test->addChildFolder("CS100");
    test->addChildFolder("CS061");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildFolder(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
}

TEST(FolderTest, renameFolder) {
    Folder* test = new Folder("Winter quarter");
    EXPECT_EQ(test->getName(), "Winter quarter");

    test->renameCurrentFolder("CS111");
    EXPECT_EQ(test->getName(), "CS111");
}

TEST(FolderTest, addExam) {
    Folder *test = new Folder("Winter Quarter");
    test->addChildExam("CS100", "December 6, 2020");
    test->addChildExam("CS061", "December 18, 2020");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
    EXPECT_EQ(test->at(1)->getName(), "CS061");
}

TEST(FolderTest, removeExam) {
    Folder *test = new Folder("Winter Quarter");
    test->addChildExam("CS100", "December 6, 2020");
    test->addChildExam("CS061", "December 18, 2020");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildExam(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
}

#endif //FOLDER_TESTS_HPP

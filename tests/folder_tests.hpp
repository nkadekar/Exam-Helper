#ifndef FOLDER_TESTS_HPP
#define FOLDER_TESTS_HPP

#include "../header/folder.hpp"
#include "gtest/gtest.h"

TEST(FolderTest, ConstructorTest) { 
    Folder test("testFolder");
    EXPECT_EQ(test.getName(), "testFolder"); 
}

TEST(FolderTest, ConstructorTest2) {
    Folder test("Spring Quarter");
    EXPECT_EQ(test.getName(), "Spring Quarter");
}

TEST(FolderTest, ConstructorTest3) {
    Folder test("Fall Quarter");
    EXPECT_EQ(test.getName(), "Fall Quarter");
}

TEST(FolderTest, addFolder) {
    Folder* test = new Folder("Winter Quarter");
    test->addChildFolder("CS100");
    test->addChildFolder("CS061");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
    EXPECT_EQ(test->at(1)->getName(), "CS061");
}

TEST(FolderTest, addFolder2) {
    Folder* test = new Folder("Spring Quarter");
    test->addChildFolder("CS111");
    test->addChildFolder("Math010A");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS111");
    EXPECT_EQ(test->at(1)->getName(), "Math010A");
}

TEST(FolderTest, addFolder3) {
    Folder* test = new Folder("Fall Quarter");
    test->addChildFolder("CS014");
    test->addChildFolder("CS011");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS014");
    EXPECT_EQ(test->at(1)->getName(), "CS011");
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

TEST(FolderTest, removeFolder2) {
    Folder* test = new Folder("Spring quarter");
    test->addChildFolder("CS111");
    test->addChildFolder("CS061");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildFolder(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS111");
}

TEST(FolderTest, removeFolder3) {
    Folder* test = new Folder("Fall quarter");
    test->addChildFolder("CS014");
    test->addChildFolder("CS011");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildFolder(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS014");
}

TEST(FolderTest, renameFolder) {
    Folder* test = new Folder("Winter quarter");
    EXPECT_EQ(test->getName(), "Winter quarter");

    test->renameCurrentFolder("CS111");
    EXPECT_EQ(test->getName(), "CS111");
}

TEST(FolderTest, renameFolder2) {
    Folder* test = new Folder("Spring quarter");
    EXPECT_EQ(test->getName(), "Spring quarter");

    test->renameCurrentFolder("CS100");
    EXPECT_EQ(test->getName(), "CS100");
}

TEST(FolderTest, renameFolder3) {
    Folder* test = new Folder("Fall quarter");
    EXPECT_EQ(test->getName(), "Fall quarter");

    test->renameCurrentFolder("CS014");
    EXPECT_EQ(test->getName(), "CS014");
}

TEST(FolderTest, addExam) {
    Folder *test = new Folder("Winter Quarter");
    test->addChildExam("CS100", "December 6, 2020");
    test->addChildExam("CS061", "December 18, 2020");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS100");
    EXPECT_EQ(test->at(1)->getName(), "CS061");
}

TEST(FolderTest, addExam2) {
    Folder *test = new Folder("Spring Quarter");
    test->addChildExam("CS111", "April 6, 2020");
    test->addChildExam("Math010A", "May 18, 2020");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS111");
    EXPECT_EQ(test->at(1)->getName(), "Math010A");
}

TEST(FolderTest, addExam3) {
    Folder *test = new Folder("Fall Quarter");
    test->addChildExam("CS014", "October 6, 2020");
    test->addChildExam("CS012", "November 18, 2020");

    ASSERT_EQ(test->getSize(), 2);
    EXPECT_EQ(test->at(0)->getName(), "CS014");
    EXPECT_EQ(test->at(1)->getName(), "CS012");
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

TEST(FolderTest, removeExam2) {
    Folder *test = new Folder("Spring Quarter");
    test->addChildExam("CS111", "April 6, 2020");
    test->addChildExam("Math010A", "May 18, 2020");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildExam(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS111");
}

TEST(FolderTest, removeExam3) {
    Folder *test = new Folder("Fall Quarter");
    test->addChildExam("CS014", "October 6, 2020");
    test->addChildExam("CS012", "November 18, 2020");
    ASSERT_EQ(test->getSize(), 2);

    test->removeChildExam(1);
    ASSERT_EQ(test->getSize(), 1);
    EXPECT_EQ(test->at(0)->getName(), "CS014");
}

#endif //FOLDER_TESTS_HPP

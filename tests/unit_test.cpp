#include "gtest/gtest.h"

#include "../header/FlashCard.hpp"

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

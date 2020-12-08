#include "gtest/gtest.h"
#include "flashcard_unit_tests.hpp"
#include "quiz_unit_tests.hpp"
#include "folder_tests.hpp"
#include "exam_unit_tests.hpp"
#include "menu_unit_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include "Puzzle.hpp"
#include "gtest/gtest.h"

TEST(PuzzleTest, CheckCorrectAndWrongAnswer) {
  Puzzle p("What has to be broken before you can use it?", "egg", "sword", 10);

  EXPECT_TRUE(p.check("egg"));
  EXPECT_FALSE(p.check("stone"));
}

TEST(PuzzleTest, GettersReturnExpectedValues) {
  Puzzle p("Q?", "ans", "key", 5);

  EXPECT_EQ(p.getQuestion(), "Q?");
  EXPECT_EQ(p.getRewardItem(), "key");
  EXPECT_EQ(p.getRewardPoints(), 5);
}

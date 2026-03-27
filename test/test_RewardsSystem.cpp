#include "Player.hpp"
#include "RewardSystem.hpp"
#include "gtest/gtest.h"

TEST(RewardSystemTest, GivesPointsAndItem) {
  Player p;
  RewardSystem r;

  r.giveReward(&p, "axe", 10);

  EXPECT_TRUE(p.hasItem("axe"));
  EXPECT_EQ(p.getPoints(), 10);
}

TEST(RewardSystemTest, ZeroPointsStillGivesItem) {
  Player p;
  RewardSystem r;

  r.giveReward(&p, "lamp", 0);

  EXPECT_TRUE(p.hasItem("lamp"));
  EXPECT_EQ(p.getPoints(), 0);
}

TEST(RewardSystemTest, EmptyItemStillGivesPoints) {
  Player p;
  RewardSystem r;

  r.giveReward(&p, "", 15);

  EXPECT_FALSE(p.hasItem(""));
  EXPECT_EQ(p.getPoints(), 15);
}

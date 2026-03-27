#include "Axe.hpp"
#include "Player.hpp"
#include "gtest/gtest.h"

TEST(AxeTest, PlayerCollectsAxe) {
  Player player;
  Axe axe;

  EXPECT_FALSE(player.hasItem("axe"));
  axe.collect(player);
  EXPECT_TRUE(player.hasItem("axe"));
}

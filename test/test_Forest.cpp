#include <sstream>

#include "Forest.hpp"
#include "Player.hpp"
#include "gtest/gtest.h"

TEST(ForestInteractionTest, WinPathRequiresAxeGivesLampAndSetsHealth40) {
  Player player;
  player.addItem("axe");

  std::istringstream in("rose\n2\n");
  std::ostringstream out;

  auto* cinbuf = std::cin.rdbuf(in.rdbuf());
  auto* coutbuf = std::cout.rdbuf(out.rdbuf());

  Forest forest;
  forest.enter(&player);

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);

  EXPECT_TRUE(player.hasItem("lamp"));
  EXPECT_EQ(player.getHealth(), 40);
  EXPECT_EQ(player.getPoints(), 20);
}

TEST(ForestInteractionTest, FightWithoutAxeIsGameOver) {
  Player player;

  std::istringstream in("rose\n2\n");
  std::ostringstream out;

  auto* cinbuf = std::cin.rdbuf(in.rdbuf());
  auto* coutbuf = std::cout.rdbuf(out.rdbuf());

  Forest forest;
  forest.enter(&player);

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);

  EXPECT_EQ(player.getHealth(), 0);
}

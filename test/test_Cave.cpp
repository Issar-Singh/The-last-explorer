#include <sstream>

#include "Player.hpp"
#include "cave.hpp"
#include "gtest/gtest.h"

TEST(CaveInteractionTest, WinPathEggThenWLSMGivesSwordAndWinText) {
  Player player;

  std::istringstream in("egg\nw l s m\n");
  std::ostringstream out;

  auto* cinbuf = std::cin.rdbuf(in.rdbuf());
  auto* coutbuf = std::cout.rdbuf(out.rdbuf());

  Cave cave;
  cave.enter(&player);

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);

  EXPECT_TRUE(player.hasItem("sword"));
  EXPECT_EQ(player.getHealth(), 100);
  EXPECT_EQ(player.getPoints(), 10);
  EXPECT_NE(out.str().find("End: YOU WIN."), std::string::npos);
}

TEST(CaveInteractionTest, WrongRiddleNoSwordDiesInBattle) {
  Player player;

  std::istringstream in("stone\n");
  std::ostringstream out;

  auto* cinbuf = std::cin.rdbuf(in.rdbuf());
  auto* coutbuf = std::cout.rdbuf(out.rdbuf());

  Cave cave;
  cave.enter(&player);

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);

  EXPECT_EQ(player.getHealth(), 0);
  EXPECT_EQ(player.getPoints(), 0);
}

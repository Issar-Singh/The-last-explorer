#include <sstream>

#include "GameManager.hpp"
#include "gtest/gtest.h"

static std::string runGameWithInput(const std::string& input) {
  std::istringstream in(input);
  std::ostringstream out;
  auto* cinbuf = std::cin.rdbuf(in.rdbuf());
  auto* coutbuf = std::cout.rdbuf(out.rdbuf());

  GameManager gm;
  gm.startGame();

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);
  return out.str();
}

TEST(GameManagerTest, FullWinRunPrintsWin) {
  std::string input =
      "w v\n"
      "2\n"
      "rose\n"
      "2\n"
      "egg\n"
      "w l s m\n";

  std::string output = runGameWithInput(input);

  EXPECT_NE(output.find("Axe received"), std::string::npos);
  EXPECT_NE(output.find("[Forest]"), std::string::npos);
  EXPECT_NE(output.find("[Cave Entrance]"), std::string::npos);
  EXPECT_NE(output.find("End: YOU WIN."), std::string::npos);
}

TEST(GameManagerTest, RiverSwimDiesGameOver) {
  std::string input =
      "w v\n"
      "1\n";

  std::string output = runGameWithInput(input);

  EXPECT_NE(output.find("drown"), std::string::npos);
  EXPECT_NE(output.find("GAME OVER"), std::string::npos);
}

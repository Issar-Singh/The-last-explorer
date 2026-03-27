#include <sstream>
#include <string>

#include "Player.hpp"
#include "PuzzleManager.hpp"
#include "RewardSystem.hpp"
#include "gtest/gtest.h"

static std::string runPuzzleWithInput(const std::string& input,
                                      const std::string& puzzleName,
                                      Player* player) {
  std::istringstream in(input);
  std::ostringstream out;

  std::streambuf* cinbuf = std::cin.rdbuf(in.rdbuf());
  std::streambuf* coutbuf = std::cout.rdbuf(out.rdbuf());

  RewardSystem rewards;
  PuzzleManager manager(&rewards);
  manager.initPuzzles();
  manager.runPuzzle(puzzleName, player);

  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);

  return out.str();
}

TEST(PuzzleManagerTest, MaidCleaningSolvedGivesReward) {
  Player player;

  std::string output = runPuzzleWithInput("w v\n", "maid_cleaning", &player);

  EXPECT_TRUE(player.hasItem("money"));
  EXPECT_EQ(player.getPoints(), 10);
  EXPECT_NE(output.find("Correct"), std::string::npos);
}

TEST(PuzzleManagerTest, MaidCleaningWrongAnswerNoReward) {
  Player player;

  std::string output = runPuzzleWithInput("g w\n", "maid_cleaning", &player);

  EXPECT_FALSE(player.hasItem("money"));
  EXPECT_EQ(player.getPoints(), 0);
  EXPECT_NE(output.find("Wrong"), std::string::npos);
}

#include "PuzzleManager.hpp"

#include <iostream>

static std::string normalize(const std::string& s) {
  std::string t = s;
  auto l = t.find_first_not_of(" \t\r\n");
  auto r = t.find_last_not_of(" \t\r\n");
  if (l == std::string::npos) return "";
  t = t.substr(l, r - l + 1);
  for (auto& c : t) c = std::tolower(c);
  return t;
}

PuzzleManager::PuzzleManager(RewardSystem* rewardSystem)
    : m_rewardSystem(rewardSystem) {}

void PuzzleManager::initPuzzles() {
  // River storyline puzzle (Maid)
  m_puzzles.emplace(
      "maid_cleaning",
      Puzzle("Choose two ingredients to mix (water=w, vinegar=v, grass=g).",
             "w v", "money", 10));

  // Gardener puzzle (Flower selection)
  m_puzzles.emplace(
      "gardener_flower",
      Puzzle("Which one of these is a flower? (cactus, rose, pitcher plant)",
             "b", "axe", 10));

  // Bear Encounter (Fight or Hide)
  m_puzzles.emplace(
      "bear_encounter",
      Puzzle("You encounter a bear. Do you hide or fight? (hide/fight)",
             "fight", "bear pelt", 20));

  // Maze Puzzle (Finding the Lamp)
  m_puzzles.emplace(
      "maze_puzzle",
      Puzzle("A glowing lamp is on a pedestal. Take it?", "y", "lamp", 10));

  // Final Trial (Cave Riddle)
  m_puzzles.emplace("cave_riddle",
                    Puzzle("What has to be broken before you can use it? (egg)",
                           "egg", "sword", 20));

  // Final Symbol Puzzle
  m_puzzles.emplace("final_symbol",
                    Puzzle("Life begins with water, grows with leaf, "
                           "shines with sun, and rests with moon. "
                           "Enter sequence using letters.",
                           "w l s m", "treasure", 50));
}

bool PuzzleManager::runPuzzle(const std::string& puzzleName, Player* player) {
  auto it = m_puzzles.find(puzzleName);
  if (it == m_puzzles.end()) {
    std::cout << "[PuzzleManager] Puzzle not found: " << puzzleName
              << std::endl;
    return false;
  }

  Puzzle& puzzle = it->second;
  std::cout << "\nPuzzle: " << puzzle.getQuestion() << std::endl;
  std::cout << "(Type 'h' for help to see the winning answer.)\n";

  std::string answer;
  while (true) {
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    std::string normalizedAnswer = normalize(answer);

    if (normalizedAnswer == "h" || normalizedAnswer == "help") {
      std::cout << "[Help] The winning answer is: '"
                << puzzle.getCorrectAnswer() << "'.\n";
      continue;
    }

    // Validate answer (check if it's correct)
    if (puzzle.check(normalizedAnswer)) {
      std::cout << "Correct answer!\n";
      m_rewardSystem->giveReward(player, puzzle.getRewardItem(),
                                 puzzle.getRewardPoints());
      return true;
    } else {
      std::cout << "Wrong! The puzzle remains unsolved.\n";
      return false;
    }
  }
}

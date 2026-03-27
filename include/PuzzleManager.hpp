#ifndef PUZZLEMANAGER_HPP
#define PUZZLEMANAGER_HPP

#include <string>
#include <unordered_map>
#include "Puzzle.hpp"
#include "Player.hpp"
#include "RewardSystem.hpp"

/**
 * Manages all puzzles in the game and handles puzzle execution.
 */
class PuzzleManager {
 public:
  explicit PuzzleManager(RewardSystem* rewardSystem);

  // Loads predefined puzzles into memory
  void initPuzzles();

  // Run a puzzle by name (returns true if solved)
  bool runPuzzle(const std::string& puzzleName, Player* player);

 private:
  std::unordered_map<std::string, Puzzle> m_puzzles;
  RewardSystem* m_rewardSystem;
};

#endif  // PUZZLEMANAGER_HPP

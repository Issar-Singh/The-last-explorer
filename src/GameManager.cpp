#include "GameManager.hpp"

#include <iostream>

GameManager::GameManager()
    : m_player(), m_gameOver(false), m_river(), m_forest(), m_cave() {}

void GameManager::startGame() {
  m_gameOver = false;

  // Global tip so players know help is available everywhere.
  std::cout
      << "(Tip: type 'h' for help at any prompt to see the winning path.)\n";

  m_river.enter(&m_player);
  if (m_player.getHealth() == 0) return endGame(false);

  m_forest.enter(&m_player);
  if (m_player.getHealth() == 0) return endGame(false);

  m_cave.enter(&m_player);
  if (m_player.getHealth() == 0) return endGame(false);

  endGame(true);
}

void GameManager::endGame(bool win) {
  if (win) {
    std::cout << "End: YOU WIN." << std::endl;
  } else {
    std::cout << "\nEnd: GAME OVER.\n";
  }
}

#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Forest.hpp"
#include "Player.hpp"
#include "River.hpp"
#include "cave.hpp"

class GameManager {
 public:
  GameManager();
  void startGame();
  void endGame(bool win);

 private:
  Player m_player;
  bool m_gameOver;

  River m_river;
  Forest m_forest;
  Cave m_cave;
};

#endif  // GAMEMANAGER_HPP

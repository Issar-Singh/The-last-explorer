#ifndef RIVER_HPP
#define RIVER_HPP

#include <memory>

#include "Environment.hpp"

/**
 * River
 * -----
 * First major environment:
 *  - Maid puzzle (handled via NPC / PuzzleManager later)
 *  - Boatman choice (swim vs boat) – currently only partially coded
 */
class River : public Environment {
 private:
  std::unique_ptr<NPC> maid;

 public:
  River();

  void enter(IPlayer* player) override;
  void triggerEvent(IPlayer* player) override;
};

#endif  // RIVER_HPP

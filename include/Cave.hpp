#ifndef CAVE_HPP
#define CAVE_HPP

#include <memory>

#include "Environment.hpp"

/**
 * Cave
 * ----
 * For this milestone:
 *  - Travel-only endpoint after Forest
 *  - No puzzles or combat yet (future extension)
 */
class Cave : public Environment {
 private:
  std::unique_ptr<NPC> cavekeeper;

 public:
  Cave();

  void enter(IPlayer* player) override;
  void triggerEvent(IPlayer* player) override;
};

#endif  // CAVE_HPP

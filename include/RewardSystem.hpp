#ifndef REWARDSYSTEM_HPP
#define REWARDSYSTEM_HPP

#include <string>

#include "Player.hpp"

/**
 * RewardSystem
 * ------------
 * Handles giving items and points to the player as rewards.
 * Single responsibility:
 *  - Update player's points.
 *  - Update player's inventory.
 */
class RewardSystem {
 public:
  // Give an item and/or points to the player.
  // Implementation is provided in RewardSystem.cpp.
  void giveReward(Player* player, const std::string& item, int points);
};

#endif  // REWARDSYSTEM_HPP

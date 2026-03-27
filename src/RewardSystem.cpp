#include "RewardSystem.hpp"

#include <iostream>

void RewardSystem::giveReward(Player* player, const std::string& item,
                              int points) {
  if (points > 0) player->addPoints(points);
  if (!item.empty()) player->addItem(item);
}

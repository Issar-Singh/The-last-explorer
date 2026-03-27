#include "Axe.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "gtest/gtest.h"

namespace {
class Gem : public Item {
 public:
  Gem() : Item("gem", "A shiny stone that glows faintly.") {}
  void use() override {}
};
}  // namespace

TEST(ICollectibleTest, GemCollectionAddsToInventory) {
  Player player;
  EXPECT_FALSE(player.hasItem("gem"));

  Gem gem;
  gem.collect(player);

  EXPECT_TRUE(player.hasItem("gem"));
}

TEST(ICollectibleTest, AxeCollectionAddsToInventory) {
  Player player;
  EXPECT_FALSE(player.hasItem("axe"));

  Axe axe;
  axe.collect(player);

  EXPECT_TRUE(player.hasItem("axe"));
}

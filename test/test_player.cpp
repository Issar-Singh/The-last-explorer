#include "gtest/gtest.h"
#include "Player.hpp"

TEST(PlayerTest, HealthChange) {
    Player p;
    int start = p.getHealth();
    p.changeHealth(-10);
    EXPECT_EQ(p.getHealth(), start - 10);
    p.changeHealth(20);
    EXPECT_LE(p.getHealth(), 100);
}

TEST(PlayerTest, PointsChange) {
    Player p;
    EXPECT_EQ(p.getPoints(), 0);
    p.addPoints(15);
    EXPECT_EQ(p.getPoints(), 15);
    EXPECT_TRUE(p.hasEnoughPoints(10));
    EXPECT_FALSE(p.hasEnoughPoints(20));
}

TEST(PlayerTest, InventoryAddAndHas) {
    Player p;
    EXPECT_FALSE(p.hasItem("axe"));
    p.addItem("axe");
    EXPECT_TRUE(p.hasItem("axe"));
}

TEST(PlayerTest, InventoryRemoveAndClear) {
    Player p;
    p.addItem("axe");
    p.addItem("lamp");
    EXPECT_TRUE(p.hasItem("axe"));
    EXPECT_TRUE(p.hasItem("lamp"));

    p.removeItem("axe");
    EXPECT_FALSE(p.hasItem("axe"));

    p.clearInventory();
    EXPECT_FALSE(p.hasItem("lamp"));
}
